import math


class SolutionBruteForce:
    """O(n * m) time — try every divisor length, longest first."""

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def divides(s: str, t: str) -> bool:
            if len(s) % len(t) != 0:
                return False
            return s == t * (len(s) // len(t))

        for length in range(min(len(str1), len(str2)), 0, -1):
            if len(str1) % length == 0 and len(str2) % length == 0:
                candidate = str1[:length]
                if divides(str1, candidate) and divides(str2, candidate):
                    return candidate
        return ""


class Solution:
    """O(n + m) time — equal concatenations + gcd of the lengths."""

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        return str1[:math.gcd(len(str1), len(str2))]
