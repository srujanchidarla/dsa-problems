class SolutionBruteForce:
    """O(n^2) time | O(n) space — repeatedly strip matching pairs."""

    def isValid(self, s: str) -> bool:
        prev = None
        while prev != s:
            prev = s
            s = s.replace("()", "").replace("{}", "").replace("[]", "")
        return s == ""


class Solution:
    """O(n) time | O(n) space — stack matching."""

    def isValid(self, s: str) -> bool:
        stack = []
        pairs = {")": "(", "}": "{", "]": "["}
        for c in s:
            if c in pairs:
                if not stack or stack.pop() != pairs[c]:
                    return False
            else:
                stack.append(c)
        return not stack
