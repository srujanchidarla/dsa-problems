from collections import Counter
from typing import List

# --- Optimized Approach ---
# Time Complexity: O(N + M)
# Space Complexity: O(U)
def matchingStringsOptimized(stringList: List[str], queries: List[str]) -> List[int]:
    """
    Uses the Hash Map (Frequency Counter) pattern for efficient lookups.
    """
    # 1. Build Frequency Map using Counter (O(N))
    freqMap = Counter(stringList)
    
    # 2. Process Queries (O(M))
    results = []
    for query in queries:
        # Dictionary lookup is O(1) average time. 
        # .get(key, 0) handles cases where the query string isn't present.
        results.append(freqMap.get(query, 0))
        
    return results

# --- Brute Force Approach ---
# Time Complexity: O(N * M)
# Space Complexity: O(1)
def matchingStringsBruteForce(stringList: List[str], queries: List[str]) -> List[int]:
    """
    Uses nested loops to compare every query against every input string.
    """
    results = []
    
    # Iterate through every query (O(M))
    for query in queries:
        count = 0
        # For every query, iterate through every string in the list (O(N))
        for s in stringList:
            if query == s:
                count += 1
        results.append(count)
        
    return results