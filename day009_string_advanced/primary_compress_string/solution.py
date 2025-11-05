import sys

def solve_compress_string():
    try:
        S = sys.stdin.readline().strip()
    except:
        return

    if not S:
        print("")
        return

    # Optimal: O(N) Time, O(N) Space - Single Pass with Counting
    compressed = []
    i = 0
    N = len(S)

    while i < N:
        current_char = S[i]
        count = 0
        j = i
        
        # Count the consecutive run
        while j < N and S[j] == current_char:
            count += 1
            j += 1
        
        # Append character and count
        compressed.append(current_char)
        compressed.append(str(count))
        
        # Move i to the start of the next run
        i = j
            
    print("".join(compressed))

# Brute Force is effectively the same logic (O(N))
def solve_compress_string_brute():
    solve_compress_string()

if __name__ == "__main__":
    solve_compress_string()