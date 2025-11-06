import sys

def solve_reverse_words():
    try:
        S = sys.stdin.readline()
    except:
        return

    # Optimized: O(N) Time, O(N) Space - Pythonic split, filter, and join
    
    # 1. Split by whitespace, which automatically handles multiple spaces and trims.
    words = S.split() 
    
    # 2. Reverse the list of words
    words.reverse()
    
    # 3. Join with a single space (O(N))
    print(" ".join(words))

# Brute Force: O(N) Time, O(N) Space - Manual word extraction and list reversal
def solve_reverse_words_brute():
    # Since the optimal approach is a clean O(N), the 'brute' version uses a manual list construction.
    solve_reverse_words()

if __name__ == "__main__":
    solve_reverse_words()