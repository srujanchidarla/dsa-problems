import sys
from collections import defaultdict

def diagonalTraversal_optimal(matrix):
    """O(N^2) Time, O(N^2) Space - Index Grouping with Alternating Reversal"""
    if not matrix or not matrix[0]: return []
    R = len(matrix)
    C = len(matrix[0])
    
    # Use defaultdict for clean grouping
    diagonals = defaultdict(list)

    # 1. Group elements by the sum of their indices (i + j)
    for i in range(R):
        for j in range(C):
            diagonals[i + j].append(matrix[i][j])

    # 2. Traverse the diagonals in order (keys are sorted automatically)
    result = []
    
    for sum_val in sorted(diagonals.keys()):
        current_diagonal = diagonals[sum_val]
        
        # Reverse every other diagonal (based on index sum's parity)
        if sum_val % 2 == 0:
             # Reverse only for odd sums if starting up-right, reverse for even sums if starting down-left.
             # Standard implementation (like LeetCode 498) requires reversal based on sum parity.
            current_diagonal.reverse() 
        
        result.extend(current_diagonal)

    # Print the space-separated output
    print(" ".join(map(str, result)))