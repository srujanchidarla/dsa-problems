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

*Next: useRef/useMemo/useCallback, context, and performance (memo, why re-renders happen).*
