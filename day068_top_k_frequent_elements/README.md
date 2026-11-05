# Day 068 - Top K Frequent Elements

| Field      | Details          |
| :--------- | :--------------- |
| Platform   | LeetCode (347)   |
| Difficulty | Medium           |
| Topic      | Arrays / Hash Map |
| Pattern    | Bucket Sort      |
| Time       | O(n)             |
| Space      | O(n)             |

---

## Problem Statement

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in any order.

*Added 2026-11-05 from Srujan's LeetCode Recent AC list (photo) — not previously in the repo.*

---

## Input / Output

```
Input:  nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input:  nums = [1], k = 1
Output: [1]

Input:  nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]
```

---

## Pattern Recognition

**Bucket Sort** — count frequencies with a hash map (Phase 1), then use the *frequency itself* as a bucket index. A number can appear at most `n` times, so there are only `n` buckets; the top `k` live in the fullest buckets. No sorting needed.

---

## Approach

### Brute Force — Count, Then Sort by Frequency, O(n log n)

```
freq = count each number
return the k keys with the largest counts, sorted by count
```

### Optimized — Bucket Sort, O(n)

```
freq = count each number
buckets = [[] for _ in range(len(nums) + 1)]
for num, count in freq.items():
    buckets[count].append(num)     # frequency IS the index
walk buckets from fullest to emptiest, collect k numbers
```

---

## Complexity

| Approach         | Time       | Space | Notes                          |
| ---------------- | ---------- | ----- | ------------------------------ |
| Count + sort     | O(n log n) | O(n)  | Sorting the distinct keys      |
| Bucket sort      | O(n)       | O(n)  | Frequency as the bucket index  |

(A size-k min-heap is the other standard answer at O(n log k) — same idea, keep only the k best.)
