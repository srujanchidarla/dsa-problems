import sys

def solve_odd_even_index():
    try:
        S = sys.stdin.readline().strip()
    except:
        return

    # Optimized: O(N) Time, O(N) Space - Single Pass
    even_chars = []
    odd_chars = []
    
    for i, char in enumerate(S):
        if i % 2 == 0:
            even_chars.append(char)
        else:
            odd_chars.append(char)
            
    # Print the two resulting strings
    print("".join(even_chars))
    print("".join(odd_chars))

# Brute Force: Same O(N) logic, perhaps using two separate loops (less efficient constant factor)
def solve_odd_even_index_brute():
    # Since the optimal logic is a single O(N) pass, the "brute" method would be very similar.
    solve_odd_even_index()

if __name__ == "__main__":
    solve_odd_even_index()