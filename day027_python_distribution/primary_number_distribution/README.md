---
dayNumber: 27
title: "Number Distribution"
difficulty: "Easy"
pattern: "Bucketing / Binning"
approach: "Use integer division `(num - 1) // range_size` to determine the bin index. Store counts in a dictionary or `collections.defaultdict`."
---

# Number Distribution

**Logic:** Map values to predefined ranges to see data density.
**Optimal:** $O(N)$ time, $O(K)$ space where $K$ is the number of bins.
