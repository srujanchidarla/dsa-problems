import sys

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(n) time | O(1) space
# Two pointers: copy every non-val element to the write position
# ─────────────────────────────────────────────────────────────────────────


def remove_element(nums, val):
    write = 0                                    # next slot for a kept value

    for read in range(len(nums)):
        if nums[read] != val:                    # keep it
            nums[write] = nums[read]
            write += 1

    return write                                 # count of kept elements


# ── Input ─────────────────────────────────────────────────────────────────
# read all tokens so an empty array (n = 0, no second line) still works
data = list(map(int, sys.stdin.read().split()))
n, val = data[0], data[1]
nums = data[2:2 + n]

k = remove_element(nums, val)
print(k)
print(*nums[:k])
