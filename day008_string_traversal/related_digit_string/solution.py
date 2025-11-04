import sys

def solve_digit_string():
    try:
        S = sys.stdin.readline().strip()
    except:
        return

    # Optimal: O(N) Time - Pythonic check
    if S.isdigit():
        print("YES")
    else:
        print("NO")

# Brute Force: O(N) Time - Manual iteration
def solve_digit_string_brute():
    S = sys.stdin.readline().strip()
    for char in S:
        if not ('0' <= char <= '9'):
            print("NO")
            return
    print("YES")

if __name__ == "__main__":
    solve_digit_string()