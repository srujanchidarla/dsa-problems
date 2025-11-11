import sys

def rotateMatrix_optimal(matrix):
    """O(N^2) Time, O(1) Space - Transpose then Reverse"""
    N = len(matrix)

    # 1. Transpose: Swap matrix[i][j] with matrix[j][i]
    for i in range(N):
        for j in range(i + 1, N):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # 2. Reverse each row
    for i in range(N):
        matrix[i].reverse()

def rotateMatrix_brute(matrix):
    """O(N^2) Time, O(N^2) Space - Brute Force (Extra Space)"""
    N = len(matrix)
    rotated = [[0] * N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            # Rotation rule: rotated[j][N - 1 - i] = matrix[i][j]
            rotated[j][N - 1 - i] = matrix[i][j]
            
    return rotated

# The platform reading logic needs to handle multiple test cases (T) and N.