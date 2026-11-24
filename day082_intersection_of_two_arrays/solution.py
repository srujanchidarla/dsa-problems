class SolutionBruteForce:
    """O(n * m) time | O(n) space — for each value, linear-scan the other array."""

    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        out = set()
        for x in nums1:
            for y in nums2:
                if x == y:
                    out.add(x)
        return list(out)


class Solution:
    """O(n + m) time | O(m) space — hash set of nums2, keep matching values."""

    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        s2 = set(nums2)
        return list({x for x in nums1 if x in s2})
