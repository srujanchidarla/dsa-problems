import sys

def solve_submatrix_sum():
    # Read N
    try:
        N = int(sys.stdin.readline())
    except:
        return

    # Read i, j, k, l (r1, c1, r2, c2)
    try:
        coords = list(map(int, sys.stdin.readline().split()))
        r1, c1, r2, c2 = coords[0], coords[1], coords[2], coords[3]
    except:
        return

    # 1. Read and Store Matrix
    matrix = []
    for _ in range(N):
        try:
            row = list(map(int, sys.stdin.readline().split()))
            matrix.append(row)
        except:
            return

    # 2. Pre-calculate 2D Prefix Sum Array (O(N^2) Preprocessing)
    # ps[i][j] stores the sum of sub-matrix from (0, 0) to (i-1, j-1)
    ps = [[0] * (N + 1) for _ in range(N + 1)]

    for i in range(1, N + 1):
        for j in range(1, N + 1):
            ps[i][j] = matrix[i-1][j-1] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1]

    # 3. Query the Submatrix Sum (O(1) Query)
    # The query is for the region [r1, c1] to [r2, c2].
    # Sum(r1, c1, r2, c2) = PS[r2+1][c2+1] - PS[r1][c2+1] - PS[r2+1][c1] + PS[r1][c1]
    total_sum = (ps[r2 + 1][c2 + 1]
                 - ps[r1][c2 + 1]
                 - ps[r2 + 1][c1]
                 + ps[r1][c1])

    print(total_sum)

# Optional: Brute force approach for comparison (O(N^2) per query)
def submatrix_sum_brute(matrix, r1, c1, r2, c2):
    sum_val = 0
    for i in range(r1, r2 + 1):
        for j in range(c1, c2 + 1):
            sum_val += matrix[i][j]
    return sum_val

if __name__ == "__main__":
    solve_submatrix_sum()