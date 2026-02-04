---
dayNumber: 28
title: "The Missing Number"
difficulty: "Easy"
pattern: "Sum Formula / XOR"
approach: "Use the Gauss formula n*(n+1)/2 to find the expected sum and subtract the actual sum. Alternatively, use XOR to avoid integer overflow risk."
---

# The Missing Number

**Logic:**

1. **Sum:** $ExpectedSum - ActualSum = Missing$
2. **XOR:** $(1 \oplus 2 \dots \oplus n) \oplus (arr[0] \oplus \dots \oplus arr[n-1])$
