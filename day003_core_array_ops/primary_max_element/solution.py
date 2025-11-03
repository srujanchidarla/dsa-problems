import sys

def solve_max_element():
    try:
        # Read the entire line of array elements
        nums = list(map(int, sys.stdin.readline().split()))
    except:
        return

    if not nums:
        return

    # Initialize max_val to the first element
    max_val = nums[0]

    # Linear scan (O(N))
    for num in nums[1:]:
        if num > max_val:
            max_val = num
            
    print(max_val)

if __name__ == "__main__":
    solve_max_element()