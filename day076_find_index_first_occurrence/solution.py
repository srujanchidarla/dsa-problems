class SolutionBruteForce:
    """O(n * m) time | O(1) space — try every start, compare char by char."""

    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        for i in range(n - m + 1):
            match = True
            for j in range(m):
                if haystack[i + j] != needle[j]:
                    match = False
                    break
            if match:
                return i
        return -1


class Solution:
    """O(n + m) time | O(m) space — KMP with the prefix function (LPS)."""

    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        # Build LPS: lps[k] = longest proper prefix of needle[0..k]
        # that is also a suffix of needle[0..k].
        lps = [0] * len(needle)
        length = 0
        i = 1
        while i < len(needle):
            if needle[i] == needle[length]:
                length += 1
                lps[i] = length
                i += 1
            elif length:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
        # Search: j = how much of needle is currently matched.
        j = 0
        i = 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
                if j == len(needle):
                    return i - j
            elif j:
                j = lps[j - 1]
            else:
                i += 1
        return -1
