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

## Phase 3 — Rendering & Performance, Then Design Patterns

Phase 2 answered *why* re-renders happen. This phase answers *what to do about it* — and how to structure components so performance problems don't appear in the first place.

### 1. The render pipeline (recite this in 30 seconds)

1. **Render**: React calls your component functions and builds a new virtual-DOM tree. Cheap-ish, but not free.
2. **Reconcile (diff)**: the new tree is compared with the old one, node by node. Same type + same key → update in place; different type → tear down and rebuild.
3. **Commit**: only the diff touches the real DOM.

Two consequences interviewers love: re-render ≠ DOM update (Phase 2), and **keys decide identity** — a wrong key makes React destroy and rebuild a component that should have been updated, losing its state.

### 2. Code splitting — don't ship the whole app on first load

Most of the bundle is code the user hasn't asked for yet (settings pages, admin panels, heavy charts). Split it out and load it on demand:

```jsx
import { lazy, Suspense } from "react";

const Settings = lazy(() => import("./Settings")); // separate chunk

function App() {
  return (
    <Suspense fallback={<p>Loading settings…</p>}>
      <Settings />
    </Suspense>
  );
}
```

- `React.lazy` turns an `import()` into a component that loads when first rendered.
- `Suspense` is the loading boundary: whatever you put in `fallback` shows while the chunk downloads. Without it, lazy throws.
- Split by **route** first (each page is a natural boundary), then by heavy feature. Splitting every component is noise.

### 3. Suspense for data (the mental model, not the library)

Suspense is a general "wait for something" boundary: a component can *suspend* while data loads, and the nearest `Suspense` shows its fallback. In interviews, the point to make is the **declarative shift** — instead of `if (loading) return <Spinner />` in every component, the loading state lives at the boundary, and the component reads data as if it were already there.

Caveats to name: a suspended component unmounts its subtree while loading (state inside is lost unless lifted), and waterfalls happen when nested Suspense boundaries load one after another — fetch in parallel at the parent when you can.

### 4. Performance: measure first, memoize second

The order matters — memoization without measurement is the most common React performance mistake:

1. **Profile** (React DevTools Profiler): which components re-render, how often, how long? Fix the top offender, not the one you suspect.
2. **Fix the structure**: lift state down (state used by one leaf shouldn't live at the root and re-render the whole tree), split components so a fast-changing part is its own subtree.
3. **Then memoize**: `React.memo` for components, `useMemo` for expensive values, `useCallback` for function identity — exactly the Phase 2 tools, applied where the profiler pointed.

Also worth naming: **virtualization** for long lists (render only the visible rows — `react-window` and friends), and **debouncing** inputs that trigger expensive work on every keystroke.

### 5. Controlled vs uncontrolled components

| | Controlled | Uncontrolled |
|---|---|---|
| Value lives in | React state (`value` + `onChange`) | The DOM itself (`ref` / `defaultValue`) |
| Best for | Validation, instant feedback, submit logic | Simple forms, file inputs, one-off reads |
| Cost | Re-render on every keystroke | React can't see the value until you ask |

```jsx
// Controlled: React owns the value
const [name, setName] = useState("");
<input value={name} onChange={e => setName(e.target.value)} />

// Uncontrolled: the DOM owns it, React reads it once
const inputRef = useRef(null);
<input ref={inputRef} defaultValue="Srujan" />
```

Interview answer: "Controlled by default for anything I validate or submit; uncontrolled when I just need the value once." A file `<input type="file">` is always uncontrolled — React can't set its value.

### 6. Compound components — the pattern behind every good UI library

Instead of one component with twenty props, expose a family that shares state implicitly:

```jsx
<Tabs defaultTab="profile">
  <Tabs.List>
    <Tabs.Tab id="profile">Profile</Tabs.Tab>
    <Tabs.Tab id="settings">Settings</Tabs.Tab>
  </Tabs.List>
  <Tabs.Panel id="profile">…</Tabs.Panel>
</Tabs>
```

The parent (`Tabs`) holds the active-tab state in context (Phase 2's `useContext`); the children consume it without prop-drilling. The user of the component composes the pieces, so the API is flexible without a prop for every layout.

Why interviewers ask: it tests whether you reach for composition over configuration — the React way to make a component both powerful and simple to use.

Closing line for the interview: "Profile before memoizing, split by route before splitting components, and prefer composition — compound components — over a prop for every case."

---

*Next: Phase 4 — State management (lifting state vs context vs a store, the Redux/Zustand mental model) and testing React components.*

