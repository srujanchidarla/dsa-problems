import sys

# O(log N) Time, O(1) Space - Optimal
def is_palindrome_optimal(n: int) -> bool:
    if n < 0: return False
    original = n
    reversed_num = 0
    temp = n
    
    while temp > 0:
        reversed_num = reversed_num * 10 + (temp % 10)
        temp //= 10
        
    return original == reversed_num

# O(log N) Time, O(1) Space - Optimal
def is_armstrong_optimal(n: int) -> bool:
    if n < 0: return False
    
    s = str(n)
    D = len(s) # Digit count
    original = n
    sum_val = 0
    
    for digit in s:
        sum_val += int(digit) ** D
        
    return original == sum_val

def solve_palindrome_armstrong():
    try:
        N = int(sys.stdin.readline().strip())
    except:
        return
        
    print(f"Palindrome: {'YES' if is_palindrome_optimal(N) else 'NO'}")
    print(f"Armstrong: {'YES' if is_armstrong_optimal(N) else 'NO'}")

if __name__ == "__main__":
    solve_palindrome_armstrong()