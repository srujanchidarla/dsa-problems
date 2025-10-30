import sys

def solve_matrix_sums():
    # Set up fast input reading
    try:
        # Read N and M from the first line
        line = sys.stdin.readline().split()
        if not line:
            return
        N = int(line[0])
        M = int(line[1])
    except:
        return

    # O(M) Space: Initialize list to store column sums
    col_sums = [0] * M

    # Store the row sums for separate printing (optional, depends on platform)
    row_sums_output = []

    # --- Combined Input Pass (O(N*M)) ---
    for i in range(N):
        try:
            # Read the current row's M elements
            row_elements = list(map(int, sys.stdin.readline().split()))
        except:
            break
        
        row_sum = 0
        
        for j in range(M):
            element = row_elements[j]
            
            # 1. Row Sum Calculation (Streaming)
            row_sum += element
            
            # 2. Column Sum Calculation (Storage)
            col_sums[j] += element
        
        # Store Row Sum (for "Matrix Row Sum" output)
        row_sums_output.append(row_sum)

    # --- Print Row Sums (Output for Problem 1: Matrix Row Sum) ---
    for r_sum in row_sums_output:
        print(r_sum)

    # --- Print Column Sums (Output for Problem 2: Matrix Column Sum) ---
    # Note: Added separator for combined testing; remove for individual problem submission.
    print("--- Column Sums ---")
    for c_sum in col_sums:
        print(c_sum)

# If running as a script, solve the problem
if __name__ == "__main__":
    solve_matrix_sums()