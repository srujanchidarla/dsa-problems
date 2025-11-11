import sys
from typing import List

class Solution:
    # Optimized: O(N) Time, O(1) Space - Backward Greedy Traversal
    def canJump_optimal(self, nums: List[int]) -> bool:
        if not nums: return False
        
        goal = len(nums) - 1 # The goal is the last index

        # Iterate backward from the second-to-last element
        for i in range(len(nums) - 2, -1, -1):
            # Check if current position can reach or pass the goal
            if i + nums[i] >= goal:
                goal = i # This is the new, closer goal
                
        # If the goal successfully reached index 0, return True
        return goal == 0

    # Brute Force: O(N^2) Time - Dynamic Programming (DP) or recursion with memoization
    def canJump_brute(self, nums: List[int]) -> bool:
        # Simplistic O(N^2) DP solution (often the first attempt)
        N = len(nums)
        memo = [False] * N
        memo[N - 1] = True # Last index is reachable

        for i in range(N - 2, -1, -1):
            max_jump = min(i + nums[i], N - 1)
            for j in range(i + 1, max_jump + 1):
                if memo[j]:
                    memo[i] = True
                    break
        
        return memo[0]

# Standard input reading (assuming the input is a single line of space-separated jumps)
def solve_jump_game():
    try:
        # Read the array elements
        nums = list(map(int, sys.stdin.readline().split()))
    except:
        return
    
    result = Solution().canJump_optimal(nums)
    print("YES" if result else "NO")

if __name__ == "__main__":
    solve_jump_game()