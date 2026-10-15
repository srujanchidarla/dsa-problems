# React — Study Log

Chronological notes from the interview-prep program. Rebuilding from component fundamentals (components, props, state) → hooks one by one → rendering & performance → design patterns.

---

## Phase 1 — Core Fundamentals

### 1. The mental model

React is: **UI = f(state)**. You describe what the UI should look like for a given state; React updates the DOM when state changes. You never touch the DOM directly.

- **Virtual DOM**: React keeps a lightweight copy of the DOM, diffs it on state change, and patches only what changed (reconciliation).
- **Components**: functions that return JSX. Capitalized names (`<Profile />`), one job each.

### 2. JSX

HTML-ish syntax inside JavaScript. Two rules that trip up beginners:

```jsx
// class → className, and one parent wrapper (or fragment)
function Card({ title }) {
  return (
    <>
      <h2 className="title">{title}</h2>
      <p>{title.length} characters</p>
    </>
  );
}
```

`{}` embeds any JS expression. That's the whole trick.

### 3. Props vs State

| | Props | State |
|---|---|---|
| What | Data passed **in** from parent | Data the component **owns** |
| Mutable? | Read-only | Changed via setter |
| Analogy | Function arguments | Local variables |

```jsx
function Counter({ start }) {          // prop
  const [count, setCount] = useState(start);  // state
  return <button onClick={() => setCount(count + 1)}>{count}</button>;
}
```

**Lifting state up**: when two siblings need the same data, move the state to their shared parent and pass it down as props.

### 4. The two hooks that matter most

**useState** — component memory. The setter *schedules* a re-render; state updates are async, so `setCount(count + 1)` twice in one handler only adds 1. Use the functional form when the new value depends on the old: `setCount(c => c + 1)`.

**useEffect** — side effects after render (fetching, timers, subscriptions).

```jsx
useEffect(() => {
  fetch("/api/user").then(r => r.json()).then(setUser);
}, []); // [] = run once on mount
```

The dependency array is the contract: "re-run me when these change." Missing deps → stale data; wrong deps → infinite loops. Cleanup goes in the return: `return () => clearInterval(id)`.

### 5. Lists and keys

```jsx
{items.map(item => <li key={item.id}>{item.name}</li>)}
```

Keys must be **stable and unique** (ids, not array indexes) — React uses them to tell items apart across re-renders. Index-as-key breaks when the list reorders.

### 6. Conditional rendering

```jsx
{isLoggedIn ? <Dashboard /> : <Login />}
{items.length > 0 && <List items={items} />}
```

`&&` with a possibly-falsy left side renders `0` — guard with an explicit comparison when the value could be `0`.

---

## Phase 2 — Hooks Deep-Dive

### 1. Rules of hooks (non-negotiable)

1. **Only at the top level** — never inside loops, conditions, or nested functions. React tracks hooks by call order; a conditional hook shifts the order and corrupts state.
2. **Only in React functions** — components and custom hooks, never plain JS functions.

### 2. useRef — the value that doesn't re-render

```jsx
const inputRef = useRef(null);
<input ref={inputRef} />
<button onClick={() => inputRef.current.focus()}>Focus</button>
```

Two jobs:
- **DOM access**: focus, scroll, measure — the escape hatch for things React doesn't model.
- **Mutable scratch space**: `ref.current` holds a value across renders *without* triggering one (timers, previous values, latest callback). If changing it shouldn't repaint the UI, it's a ref, not state.

Rule of thumb: state is for data the UI *shows*; refs are for data the component *remembers silently*.

### 3. useMemo & useCallback — referential stability

React re-renders re-run the whole component function. Two tools to skip work:

- **useMemo(fn, deps)** — cache a *computed value* (expensive sort/filter) until deps change.
- **useCallback(fn, deps)** — cache a *function identity* so it doesn't look "new" every render.

They matter for exactly one reason: **identity**. A child wrapped in `React.memo` re-renders if it receives a new object/function reference — even if the contents are identical. `useCallback` + `memo` together stop that cascade.

When *not* to use them: everywhere. Memoizing a cheap computation costs more (comparison + memory) than redoing it. Reach for them when a profiler shows a real problem, or when passing callbacks/objects to memoized children.

### 4. useContext — the prop-drilling exit

```jsx
const ThemeContext = createContext("light");
function App() { return <ThemeContext.Provider value="dark"><Page /></ThemeContext.Provider>; }
function Page() { const theme = useContext(ThemeContext); /* no props needed */ }
```

Context is a tunnel through the tree: provide at the top, consume anywhere below. Built for slow-changing, app-wide data — theme, auth user, locale.

Caveat interviewers probe: when the context value changes, **every consumer re-renders**. Fine for a theme; a footgun for rapidly changing state. For that, pair context with a state library or split contexts by update frequency.

### 5. Custom hooks — logic with a name

Any function named `useX` that calls other hooks. It shares *logic*, not state — each caller gets its own copy.

```jsx
function useFetch(url) {
  const [data, setData] = useState(null);
  useEffect(() => {
    let live = true;
    fetch(url).then(r => r.json()).then(d => { if (live) setData(d); });
    return () => { live = false; };  // ignore stale responses after unmount/re-run
  }, [url]);
  return data;
}
```

If the same useState+useEffect dance appears twice, extract it. This is the most common "design" question in React interviews: show the messy component, then the custom-hook refactor.

### 6. Why re-renders happen (the model to recite)

- A component re-renders when **its own state changes**, its **parent re-renders** (children re-render by default, props or not), or a **context it consumes changes**.
- Re-render ≠ DOM update: React re-runs the function, diffs the output, and touches the DOM only where the diff says so. Re-renders are cheap-ish; reconciliation exists to avoid wasted DOM writes.
- `React.memo` opts a component out of the parent cascade — if props are shallowly equal, skip. Useless unless props are referentially stable, which is what useMemo/useCallback are *for*.

---

*Next: rendering & performance in depth (code splitting, lazy, Suspense), then design patterns (controlled vs uncontrolled, compound components).*
