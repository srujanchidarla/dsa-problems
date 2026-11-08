class SolutionBruteForce:
    """O(n^2) time | O(n) space — rescan from the start after every removal."""

    def canRemoveAll(self, types, colors, groupSize):
        types = list(types)
        colors = list(colors)
        while True:
            removed = False
            i = 0
            while i < len(types):
                j = i
                while (j < len(types) and types[j] == types[i]
                       and colors[j] == colors[i]):
                    j += 1
                if j - i >= groupSize[types[i]]:
                    k = groupSize[types[i]]
                    del types[i:i + k]
                    del colors[i:i + k]
                    removed = True
                    break
                i = j
            if not removed:
                return len(types) == 0


class Solution:
    """O(n) time | O(n) space — one pass with a stack of runs."""

    def canRemoveAll(self, types, colors, groupSize):
        stack = []  # each entry: [type, color, count]
        for t, c in zip(types, colors):
            if stack and stack[-1][0] == t and stack[-1][1] == c:
                stack[-1][2] += 1
            else:
                stack.append([t, c, 1])
            if stack[-1][2] == groupSize[t]:
                stack.pop()
        return not stack
