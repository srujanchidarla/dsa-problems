import sys

def solve_print_n():
    try:
        N = int(sys.stdin.readline().strip())
    except:
        return

    # Optimized (1 to N): Post-recursion print
    def print_1_to_N(n):
        if n == 0:
            return
        print_1_to_N(n - 1)
        print(n, end=" ")
        
    # Brute Force (N to 1): Pre-recursion print
    def print_N_to_1(n):
        if n == 0:
            return
        print(n, end=" ")
        print_N_to_1(n - 1)

    print("N to 1 (Brute):", end=" ")
    print_N_to_1(N)
    print("\n1 to N (Optimal):", end=" ")
    print_1_to_N(N)
    print()

if __name__ == "__main__":
    solve_print_n()