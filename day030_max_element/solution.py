import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# BRUTE FORCE — O(n²) time | O(1) space
# For each element, check if any other element is bigger
# ─────────────────────────────────────────────────────────────────────────


def find_max_brute(arr):
    n = len(arr)
    for i in range(n):
        is_max = True
        # compare arr[i] with every element
        for j in range(n):
            if arr[j] > arr[i]:
                is_max = False               # found something bigger
                break
        if is_max:
            return arr[i]                    # nothing bigger → this is the max
    return arr[0]


# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(n) time | O(1) space
# Single pass, track maximum as we go
# ─────────────────────────────────────────────────────────────────────────
def find_max(arr):
    # IMPORTANT: init to arr[0], never 0
    max_val = arr[0]
    # arr could be all negatives!
    for num in arr[1:]:                      # check from second element onward
        if num > max_val:                    # found a new maximum
            max_val = num                    # update our best
    return max_val


# ─────────────────────────────────────────────────────────────────────────
# PYTHONIC — O(n) time | O(1) space
# Built-in max() does the same linear scan internally
# ─────────────────────────────────────────────────────────────────────────
def find_max_builtin(arr):
    return max(arr)                          # clean one-liner, same complexity


# ── Input ─────────────────────────────────────────────────────────────────
n = int(input())
arr = list(map(int, input().split()))        # read all elements in one line
print(find_max(arr))
