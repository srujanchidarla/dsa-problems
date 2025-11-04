import sys

def solve_letter_coverage():
    try:
        S = sys.stdin.readline().strip().lower()
    except:
        return

    # Optimized: O(N) Time, O(1) Space - Use a set for counting unique letters
    unique_letters = set()
    
    for char in S:
        if 'a' <= char <= 'z':
            unique_letters.add(char)
            
    # Check if the set contains 26 unique letters
    if len(unique_letters) == 26:
        print("Pangram: YES")
    else:
        print("Pangram: NO")

# Brute Force: O(N^2) Time - Iteratively check if 'a', 'b', 'c', etc., is present in the string (very slow)
def solve_letter_coverage_brute(S):
    # This is not implemented as the O(N^2) is prohibitively slow and non-standard.
    # The simple O(N) check above is the standard "brute" solution for this problem.
    solve_letter_coverage()

if __name__ == "__main__":
    solve_letter_coverage()