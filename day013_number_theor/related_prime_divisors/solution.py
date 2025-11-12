import sys
import math

# O(sqrt(N)) Time, O(1) Space - Optimal Primality Check
def is_prime_optimal(N: int) -> bool:
    if N <= 1: return False
    if N <= 3: return True
    
    # Check factors up to sqrt(N)
    for i in range(2, int(math.sqrt(N)) + 1):
        if N % i == 0:
            return False
    return True

# O(N) Time, O(1) Space - Brute Force Primality Check
def is_prime_brute(N: int) -> bool:
    if N <= 1: return False
    for i in range(2, N):
        if N % i == 0:
            return False
    return True

# O(sqrt(N)) Time, O(sqrt(N)) Space - Optimized Divisor Printing
def print_divisors_optimal(N: int):
    if N <= 0: return

    divisors = set() # Use a set to automatically handle duplicates (when i*i = N)
    
    for i in range(1, int(math.sqrt(N)) + 1):
        if N % i == 0:
            divisors.add(i)
            divisors.add(N // i)
            
    print("Divisors: ", " ".join(map(str, sorted(list(divisors)))))

def solve_prime_divisors():
    try:
        N = int(sys.stdin.readline().strip())
    except:
        return
        
    print(f"Is Prime: {'YES' if is_prime_optimal(N) else 'NO'}")
    print_divisors_optimal(N)

if __name__ == "__main__":
    solve_prime_divisors()