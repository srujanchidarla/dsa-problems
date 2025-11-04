import sys

def solve_vowels_consonants():
    try:
        S = sys.stdin.readline().strip().lower()
    except:
        return

    # Optimized: O(N) Time, O(1) Space - Using a Set for O(1) lookup
    VOWELS = {'a', 'e', 'i', 'o', 'u'}
    vowel_count = 0
    consonant_count = 0
    
    for char in S:
        if 'a' <= char <= 'z':
            if char in VOWELS:
                vowel_count += 1
            else:
                consonant_count += 1
            
    print(f"Vowels: {vowel_count}")
    print(f"Consonants: {consonant_count}")

# Brute Force: O(N) Time - Using a long 'if-elif' chain instead of a set (less clean, same complexity)
def solve_vowels_consonants_brute():
    solve_vowels_consonants()

if __name__ == "__main__":
    solve_vowels_consonants()