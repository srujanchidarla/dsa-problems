import sys

def solve_ternary_array_cost():
    try:
        # Read N (not strictly needed for the cost calculation)
        N = int(sys.stdin.readline())
        # Read the array elements
        A = list(map(int, sys.stdin.readline().split()))
    except:
        return

    min_total_cost = 0

    # Optimal: O(N) Time - Greedy Local Minimization
    for a_i in A:
        # Possible target values for B[i] are 0, 1, 2
        
        # Start with a very high cost
        min_local_cost = float('inf') 
        
        for b_i in [0, 1, 2]:
            # Constraint check: A[i] != B[i]
            if a_i != b_i:
                # Calculate the cost: |A[i] - B[i]|
                cost = abs(a_i - b_i)
                
                # Update the minimum local cost
                if cost < min_local_cost:
                    min_local_cost = cost
        
        # Add the minimum local cost to the total
        min_total_cost += min_local_cost

    print(min_total_cost)

if __name__ == "__main__":
    solve_ternary_array_cost()