import sys

def solve_valid_palindrome():
    try:
        S = sys.stdin.readline().strip()
    except:
        return

    # Optimized: O(N) Time, O(1) Space - Two Pointers with in-place filtering
    
    left = 0
    right = len(S) - 1
    
    while left < right:
        # Move left pointer past non-alphanumeric characters
        while left < right and not S[left].isalnum():
            left += 1
            
        # Move right pointer past non-alphanumeric characters
        while left < right and not S[right].isalnum():
            right -= 1
            
        # Compare characters (case-insensitive)
        if S[left].lower() != S[right].lower():
            print("NO")
            return
            
        # Move both pointers inward
        left += 1
        right -= 1
        
    print("YES")

# Brute Force: O(N) Time, O(N) Space - Preprocessing
def solve_valid_palindrome_brute():
    try:
        S = sys.stdin.readline().strip()
    except:
        return
    
    # Preprocess: Filter and convert to lower case (O(N) time and O(N) space)
    filtered_s = "".join(char.lower() for char in S if char.isalnum())
    
    # Check if string equals its reverse (O(N) time)
    if filtered_s == filtered_s[::-1]:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    solve_valid_palindrome()