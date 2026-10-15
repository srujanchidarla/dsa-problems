# Python — Study Log

Chronological notes from the interview-prep program. Rebuilding from syntax & data-structure refresh → OOP → decorators/generators/context managers → interview patterns.

---

## Phase 1 — Interview Essentials

### 1. The four data structures (know cold)

| Structure | Literal | Get/Set | Notes |
|---|---|---|---|
| `list` | `[1, 2]` | O(1) index; O(n) insert-front | Dynamic array; `append` amortized O(1) |
| `dict` | `{"a": 1}` | O(1) avg | Hash map — the interview workhorse |
| `set` | `{1, 2}` | O(1) avg | Membership tests, dedup |
| `tuple` | `(1, 2)` | O(1) index | Immutable — usable as dict keys |

`dict.get(k, 0)` avoids KeyError. `in` on a list is O(n); on a set/dict it's O(1) — that one-line change has decided interviews.

### 2. Strings and slicing

Strings are immutable — every "modification" builds a new one. For building strings in a loop, collect into a list and `"".join(parts)` (O(n) total, not O(n²)).

```python
s = "algorithm"
s[0], s[-1]        # 'a', 'm'
s[2:5]             # 'gor'  (start inclusive, end exclusive)
s[::-1]            # 'mhtirogla'  (reverse)
```

### 3. Comprehensions

```python
squares = [x*x for x in range(10)]            # list
evens = {x for x in range(10) if x % 2 == 0}  # set
freq = {c: s.count(c) for c in set(s)}        # dict (careful: O(n²))
```

Readable > clever. If a comprehension needs two `if`s, write a loop.

### 4. The stdlib six (import without thinking)

```python
from collections import Counter, defaultdict, deque
import heapq, bisect

Counter("aabbc")            # {'a': 2, 'b': 2, 'c': 1}
d = defaultdict(list)       # d[k].append(v) with no KeyError
q = deque()                 # O(1) popleft — BFS queues
heapq.heappush(h, x)        # min-heap (negate for max-heap)
bisect.bisect_left(a, x)    # binary search insertion point
```

### 5. Sorting with keys

```python
pairs.sort(key=lambda p: p[1])          # sort by second element
words.sort(key=lambda w: (-len(w), w))  # longest first, then alphabetical
```

`sorted()` returns new; `.sort()` is in-place. Both are Timsort: O(n log n), stable.

### 6. Gotchas that cost time

- **Mutable default args**: `def f(x=[])` shares one list across calls. Use `None` + init inside.
- **`is` vs `==`**: `is` checks identity. Use `==` for values (except `None`: `x is None`).
- **Integer division**: `//` floors (`-3 // 2 == -2`). For LeetCode-style truncation toward zero on negatives, use `int(a / b)`.
- **Copying**: `b = a` aliases; `b = a[:]` or `list(a)` copies one level; `copy.deepcopy` for nested.

---

## Phase 2 — Decorators & Generators

### 1. Functions are objects

Everything in this phase follows from one fact: in Python, functions are first-class values — assignable, passable, returnable.

```python
def greet(): return "hi"
f = greet          # no call — f IS the function
f()                # "hi"
```

A **decorator** is just a function that takes a function and returns a better one.

### 2. Decorators

```python
import functools, time

def timer(fn):
    @functools.wraps(fn)          # keep the original name/docstring
    def wrapper(*args, **kwargs):
        start = time.perf_counter()
        result = fn(*args, **kwargs)
        print(f"{fn.__name__}: {time.perf_counter() - start:.3f}s")
        return result
    return wrapper

@timer                            # job = timer(job)
def job(): ...
```

Anatomy to recite: the outer function takes `fn`; `wrapper` accepts `*args, **kwargs` so it fits any signature; the wrapper calls `fn`, adds behavior before/after, and returns the result; `@functools.wraps` stops the decorated function from losing its identity.

**Decorator with arguments** = one more nesting level — a function that returns a decorator:

```python
def retry(times=3):
    def deco(fn):
        @functools.wraps(fn)
        def wrapper(*args, **kwargs):
            for attempt in range(times):
                try:
                    return fn(*args, **kwargs)
                except Exception:
                    if attempt == times - 1: raise
        return wrapper
    return deco

@retry(times=5)
def flaky_call(): ...
```

Real uses worth naming: logging, timing, retry, caching (`@functools.lru_cache` *is* a decorator — memoization for free), auth checks in web frameworks (`@login_required`).

### 3. Generators and yield

A function with `yield` doesn't run when called — it returns a **generator** that produces values one at a time, pausing between them.

```python
def countdown(n):
    while n > 0:
        yield n
        n -= 1

for x in countdown(3): ...   # 3, 2, 1 — computed on demand
```

Why interviewers care: **memory**. A generator streams values in O(1) memory; the equivalent list for `range(10**9)` costs gigabytes. Any "process a huge file" question is a generator question: read and yield line by line, never load it all.

- **Generator expression**: `(x*x for x in data)` — a comprehension in parentheses; lazy and single-use.
- **`yield from`**: delegate to another generator (`yield from inner()`).
- Generators are **single-pass**: once consumed, they're empty. Converting to a list "to use it twice" throws away the whole point.

### 4. The iterator protocol (what's under the hood)

`for` works on anything with `__iter__` + `__next__`, raising `StopIteration` at the end. Generators implement it automatically — that's all a generator is: an iterator you write with a function instead of a class. `iter()` / `next()` let you drive one manually, which is also how you inspect one in a debugger.

### 5. Context managers — the generator tie-in

`with` guarantees cleanup (files, locks, connections). The fastest way to write one is a generator + decorator:

```python
from contextlib import contextmanager

@contextmanager
def open_session():
    session = connect()
    try:
        yield session          # everything before yield = setup
    finally:
        session.close()        # everything in finally = guaranteed cleanup
```

Setup → yield → teardown is the same pause-and-resume machinery as §3, pointed at resource management.

Interview one-liner: "Decorators wrap *behavior around functions*; generators wrap *production of values over time*."

---

*Next: OOP — classes, dunder methods, dataclasses; then concurrency basics (threads vs processes, the GIL).*
