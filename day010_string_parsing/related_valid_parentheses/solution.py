import sys

class Solution:
    # Optimized: O(N) Time, O(N) Space - Stack and Hash Map (Dictionary)
    def isValid_optimal(self, s: str) -> bool:
        # Dictionary for O(1) lookup: closer -> opener
        mappings = {')': '(', '}': '{', ']': '['}
        stack = []

        for char in s:
            if char in mappings.values():
                # Case 1: Opener -> Push to stack
                stack.append(char)
            elif char in mappings.keys():
                # Case 2: Closer
                
                # If stack is empty (unmatched closer) or mismatch
                if not stack or stack.pop() != mappings[char]:
                    return False
            
            # Ignore other characters

        # Final check: Must be empty
        return not stack

    def solve(self):
        try:
            s = sys.stdin.readline().strip()
        except:
            return
        
        result = self.isValid_optimal(s)
        print("true" if result else "false")

if __name__ == "__main__":
    Solution().solve()