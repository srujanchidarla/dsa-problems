from typing import List


class SolutionBruteForce:
    """O(n * m^2) time — try every prefix of the shortest word, longest first."""

    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        shortest = min(strs, key=len)
        for length in range(len(shortest), -1, -1):
            prefix = shortest[:length]
            if all(w.startswith(prefix) for w in strs):
                return prefix
        return ""


class Solution:
    """O(S) time | O(1) extra space — vertical scan, stop at first mismatch."""

    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        for i in range(len(strs[0])):
            c = strs[0][i]
            for w in strs[1:]:
                if i >= len(w) or w[i] != c:
                    return strs[0][:i]
        return strs[0]
