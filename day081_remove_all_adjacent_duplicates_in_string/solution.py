class SolutionBruteForce:
    """O(n^2) time | O(n) space — rescan and delete pairs until nothing changes."""

    def removeDuplicates(self, s: str) -> str:
        changed = True
        while changed:
            changed = False
            out = []
            i = 0
            while i < len(s):
                if i + 1 < len(s) and s[i] == s[i + 1]:
                    i += 2
                    changed = True
                else:
                    out.append(s[i])
                    i += 1
            s = "".join(out)
        return s


class Solution:
    """O(n) time | O(n) space — stack: a matching top cancels the pair."""

    def removeDuplicates(self, s: str) -> str:
        stack = []
        for ch in s:
            if stack and stack[-1] == ch:
                stack.pop()
            else:
                stack.append(ch)
        return "".join(stack)
