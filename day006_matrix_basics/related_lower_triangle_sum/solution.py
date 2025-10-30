import sys

def solve_lower_triangle_sum():
    # Read N
    try:
        N = int(sys.stdin.readline())
    except:
        return

    matrix = []
    lower_triangle_sum = 0

    # 1. Read, Store, and Sum in a single O(N^2) pass
    for i in range(N):
        try:
            row = list(map(int, sys.stdin.readline().split()))
            matrix.append(row)
        except:
            return
        
        for j in range(N):
            element = matrix[i][j]
            
            # Check the lower triangle condition: row index >= column index
            if i >= j:
                lower_triangle_sum += element

    print(lower_triangle_sum)

if __name__ == "__main__":
    solve_lower_triangle_sum()