import sys

# Optimal: O(log(min(A,B))) Time - Euclidean Algorithm (Recursive)
def gcd_recursive(a, b):
    if b == 0:
        return a
    return gcd_recursive(b, a % b)

# Alternative Optimal: O(log(min(A,B))) Time - Euclidean Algorithm (Iterative)
def gcd_iterative(a, b):
    while b:
        a, b = b, a % b
    return a

# Brute Force: O(min(A,B)) Time
def gcd_brute(a, b):
    # Find the minimum of the two numbers
    min_val = min(a, b)
    
    # Iterate from min_val down to 1
    for i in range(min_val, 0, -1):
        if a % i == 0 and b % i == 0:
            return i
    return 1

def solve_gcd():
    try:
        A, B = map(int, sys.stdin.readline().split())
    except:
        return
    
    # Use the iterative optimal approach
    result = gcd_iterative(A, B)
    print(f"GCD: {result}")

if __name__ == "__main__":
    solve_gcd()