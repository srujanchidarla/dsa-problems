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

## Phase 3 — OOP, Then Concurrency & the GIL

### 1. Classes: the 30-second model

A class is a blueprint; an object is a house built from it. `self` is just the object itself, passed in as the first argument — Python does it for you on `obj.method()`.

```python
class BankAccount:
    def __init__(self, owner, balance=0):   # constructor: set up state
        self.owner = owner
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount
        return self.balance
```

### 2. Inheritance vs composition (the question behind the question)

- **Inheritance** ("is-a"): a `SavingsAccount` *is a* `BankAccount`. Use it when the subclass truly behaves like the parent everywhere (Liskov, from the system-design notes).
- **Composition** ("has-a"): a `Car` *has an* `Engine`. Use it when you just need the capability — it's almost always the safer default, because it doesn't lock you into a hierarchy.

```python
class Engine: ...
class Car:
    def __init__(self):
        self.engine = Engine()   # has-a: swap the engine, keep the car
```

Interview line: "Prefer composition; inherit only when the subclass must be usable wherever the parent is."

### 3. Dunder methods — the ones interviewers actually ask about

Dunder (double-underscore) methods let your objects speak Python's built-in language:

| Method | Called by | Use it for |
|---|---|---|
| `__init__` | `Account(...)` | Setting up state |
| `__str__` / `__repr__` | `print(x)` / debugger | Human vs unambiguous display — `__repr__` should ideally rebuild the object |
| `__eq__` / `__hash__` | `==`, sets, dict keys | Value equality — **if you define `__eq__`, define `__hash__` too, or set it to `None`** |
| `__len__` | `len(x)` | Container-like objects |
| `__iter__` / `__next__` | `for x in obj` | The iterator protocol (Phase 2, §4) — custom collections |
| `__call__` | `obj()` | Callable objects — this is how decorators-as-classes work |

```python
from dataclasses import dataclass

@dataclass
class Point:
    x: int
    y: int

p = Point(1, 2)
print(p)          # Point(x=1, y=2) — __repr__ free
```

### 4. Dataclasses (and when not to use them)

`@dataclass` writes `__init__`, `__repr__`, and `__eq__` for you — perfect for data carriers (a `Point`, a `Transaction`, a parsed row). Add `frozen=True` for immutability, `field(default_factory=list)` for mutable defaults (the Phase 1 mutable-default gotcha, solved properly).

Don't use one when the class has real behavior, invariants to enforce in a hand-written `__init__`, or a complex lifecycle — then a plain class is clearer. And `__slots__` (listing allowed attributes) saves memory for millions of small objects, at the cost of no dynamic attributes — name it, don't reach for it unprompted.

### 5. @property — validation without breaking callers

```python
class Circle:
    def __init__(self, radius):
        self._radius = radius

    @property
    def radius(self):
        return self._radius

    @radius.setter
    def radius(self, value):
        if value < 0:
            raise ValueError("radius can't be negative")
        self._radius = value
```

Callers still write `c.radius` — the attribute access *looks* the same, but now it runs code. That's the interview point: encapsulation in Python is a convention (`_private` by name), and `@property` is how you add a guard later without changing the API.

### 6. Concurrency: threads vs processes vs async

| | Threads | Processes | Async (`asyncio`) |
|---|---|---|---|
| Memory | Shared | Separate (copy-on-write) | Shared, single thread |
| Best for | I/O-bound (network, disk) | CPU-bound | Many I/O-bound tasks, one thread |
| Cost | Cheap to start | Expensive, more memory | Cheapest per task |
| Gotcha | The GIL (below) | Data must be pickled to share | One blocking call stalls everything |

### 7. The GIL — the answer interviewers want

The **Global Interpreter Lock** means only one thread executes Python bytecode at a time, per process. Consequences:

- **CPU-bound code does not speed up with threads** — ten threads crunching numbers take turns on one core. Use `multiprocessing` (or `concurrent.futures.ProcessPoolExecutor`) to actually use multiple cores.
- **I/O-bound code *does* benefit** — while one thread waits on a network response, the GIL is released and another thread runs. Web servers, scrapers, API fan-out: threads are fine.
- **The escape hatches**: NumPy/C extensions release the GIL during heavy computation; `asyncio` sidesteps it by never blocking in the first place.

```python
from concurrent.futures import ThreadPoolExecutor, ProcessPoolExecutor

# I/O-bound: download 100 URLs — threads win
with ThreadPoolExecutor(max_workers=10) as ex:
    ex.map(fetch_url, urls)

# CPU-bound: crunch 100 images — processes win
with ProcessPoolExecutor() as ex:
    ex.map(process_image, images)
```

Interview one-liner: "Threads for waiting, processes for working, async for waiting *a lot* — and the GIL is why."

Closing line for the interview: "Composition over inheritance, dunders to make objects Pythonic, dataclasses for data — and when it comes to speed, ask first whether the work is waiting or working."

---

*Next: Phase 4 — Python interview patterns (two pointers, sliding window, heapq idioms) and async/await in depth.*

