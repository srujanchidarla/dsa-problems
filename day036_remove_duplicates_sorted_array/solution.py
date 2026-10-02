import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(n) time | O(1) space
# Two pointers: read scans, write marks the next unique slot
# ─────────────────────────────────────────────────────────────────────────


def remove_duplicates(nums):
    write = 1                                    # nums[0] is always unique

    for read in range(1, len(nums)):
        if nums[read] != nums[write - 1]:        # new value found
            nums[write] = nums[read]             # place it at write
            write += 1

    return write                                 # count of unique elements


# ── Input ─────────────────────────────────────────────────────────────────
n = int(input())
nums = list(map(int, input().split()))

k = remove_duplicates(nums)
print(k)
print(*nums[:k])
