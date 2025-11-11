import sys

def spiralTraversal_optimal(matrix):
    """O(N^2) Time, O(1) Space - Boundary Pointers"""
    if not matrix or not matrix[0]: return []
    R = len(matrix)
    C = len(matrix[0])
    
    top, bottom = 0, R - 1
    left, right = 0, C - 1
    result = []

    while top <= bottom and left <= right:
        # 1. Traverse Right (Top row)
        for j in range(left, right + 1):
            result.append(str(matrix[top][j]))
        top += 1

        # 2. Traverse Down (Right column)
        for i in range(top, bottom + 1):
            result.append(str(matrix[i][right]))
        right -= 1

        # 3. Traverse Left (Bottom row) - Check boundary
        if top <= bottom:
            for j in range(right, left - 1, -1):
                result.append(str(matrix[bottom][j]))
            bottom -= 1

        # 4. Traverse Up (Left column) - Check boundary
        if left <= right:
            for i in range(bottom, top - 1, -1):
                result.append(str(matrix[i][left]))
            left += 1
            
    # Print the space-separated output
    print(" ".join(result))