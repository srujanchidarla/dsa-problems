from typing import List
from collections import defaultdict


class SolutionBruteForce:
    """O(n^2 * k log k) — compare each word against every group."""

    def _is_anagram(self, a: str, b: str) -> bool:
        return sorted(a) == sorted(b)

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups: List[List[str]] = []
        for w in strs:
            placed = False
            for g in groups:
                if self._is_anagram(w, g[0]):
                    g.append(w)
                    placed = True
                    break
            if not placed:
                groups.append([w])
        return groups


class Solution:
    """O(n * k log k) — sorted canonical key in a hash map."""

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        for w in strs:
            key = "".join(sorted(w))
            groups[key].append(w)
        return list(groups.values())
