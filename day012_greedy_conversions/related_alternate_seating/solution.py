import sys

def solve_alternate_seating():
    # Read N (people needed)
    try:
        N = int(sys.stdin.readline())
    except:
        return
        
    # Read M (number of seats)
    try:
        M = int(sys.stdin.readline())
    except:
        return
        
    # Read the array elements
    try:
        seats = list(map(int, sys.stdin.readline().split()))
    except:
        return

    people_seated = 0

    # Optimal: O(M) Time - Greedy Single Pass
    for i in range(M):
        if people_seated >= N:
            break

        # Check 1: Seat must be vacant
        if seats[i] == 0:
            
            # Check 2: Left neighbor must be empty (or boundary)
            left_empty = (i == 0) or (seats[i-1] == 0)
            
            # Check 3: Right neighbor must be empty (or boundary)
            right_empty = (i == M - 1) or (seats[i+1] == 0)
            
            if left_empty and right_empty:
                # Greedily take the seat
                seats[i] = 1 
                people_seated += 1

    if people_seated >= N:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    solve_alternate_seating()