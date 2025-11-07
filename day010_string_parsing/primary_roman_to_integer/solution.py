import sys

class Solution:
    # O(N) Time, O(1) Space - Right-to-Left Traversal (Cleanest Optimal)
    def romanToInt_optimal(self, s: str) -> int:
        roman_map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        total = 0
        
        # Start with the value of the last character
        total += roman_map[s[-1]]
        
        # Iterate from the second-to-last character backward
        for i in range(len(s) - 2, -1, -1):
            current_val = roman_map[s[i]]
            prev_val = roman_map[s[i+1]]
            
            if current_val < prev_val:
                total -= current_val
            else:
                total += current_val
                
        return total

    # Brute Force: O(N) Time, O(1) Space - Left-to-Right Check
    def romanToInt_brute(self, s: str) -> int:
        roman_map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        total = 0
        N = len(s)
        
        for i in range(N):
            current_val = roman_map[s[i]]
            
            if i < N - 1:
                next_val = roman_map[s[i+1]]
                
                # Check for the subtraction case (IV, IX, XL, etc.)
                if current_val < next_val:
                    total -= current_val
                    continue # Skip addition, subtract and move to next char
            
            # Default case: add the value
            total += current_val
            
        return total
    
    def solve(self):
        try:
            s = sys.stdin.readline().strip()
        except:
            return
        
        result = self.romanToInt_optimal(s)
        print(result)

if __name__ == "__main__":
    Solution().solve()