import sys

def solve_digit_manipulation():
    try:
        N = int(sys.stdin.readline().strip())
    except:
        return

    original_n = N
    
    # Handle negative numbers by converting to positive for digit logic
    num = abs(N) 
    
    # --- 1. Count Digits ---
    temp_count = num
    count = 0
    while temp_count > 0:
        temp_count //= 10
        count += 1
    print(f"Count: {count}")
    
    # --- 2. Reverse Number ---
    temp_reverse = num
    reversed_num = 0
    while temp_reverse > 0:
        last_digit = temp_reverse % 10
        reversed_num = reversed_num * 10 + last_digit
        temp_reverse //= 10
        
    # Apply original sign
    if original_n < 0:
        reversed_num *= -1
        
    print(f"Reversed: {reversed_num}")

if __name__ == "__main__":
    solve_digit_manipulation()