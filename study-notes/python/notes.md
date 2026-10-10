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

*Next: OOP (classes, dunder methods), generators/iterators, decorators.*
