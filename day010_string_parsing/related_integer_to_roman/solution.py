import sys

class Solution:
    # Use paired lists or a tuple of tuples for the lookup table, ordered largest to smallest
    MAPPING = [
        (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"),
        (90, "XC"), (50, "L"), (40, "XL"), (10, "X"), (9, "IX"), (5, "V"), 
        (4, "IV"), (1, "I")
    ]

    # O(1) Time, O(1) Space - Optimal (Greedy Lookup)
    def intToRoman_optimal(self, num: int) -> str:
        result = []
        
        for value, symbol in self.MAPPING:
            if num == 0:
                break
            
            # Calculate how many times the symbol fits
            count = num // value
            if count > 0:
                result.append(symbol * count)
                num %= value
                
        return "".join(result)

    def solve(self):
        try:
            num = int(sys.stdin.readline().strip())
        except:
            return
        
        result = self.intToRoman_optimal(num)
        print(result)

if __name__ == "__main__":
    Solution().solve()