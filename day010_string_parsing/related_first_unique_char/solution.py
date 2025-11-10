import sys
from collections import Counter

class Solution:
    # Optimized: O(N) Time, O(1) Space (Using Counter and a two-pass strategy)
    def firstUniqChar_optimal(self, s: str) -> int:
        if not s: return -1
        
        # Pass 1: Count frequencies (O(N))
        counts = Counter(s)

        # Pass 2: Find the first index (O(N))
        for i, char in enumerate(s):
            if counts[char] == 1:
                return i
        
        return -1
    
    # Brute Force: O(N^2) Time
    def firstUniqChar_brute(self, s: str) -> int:
        N = len(s)
        for i in range(N):
            is_unique = True
            for j in range(N):
                if i != j and s[i] == s[j]:
                    is_unique = False
                    break
            if is_unique:
                return i
        return -1

    def solve(self):
        try:
            s = sys.stdin.readline().strip()
        except:
            return
        
        result = self.firstUniqChar_optimal(s)
        print(result)

if __name__ == "__main__":
    Solution().solve()