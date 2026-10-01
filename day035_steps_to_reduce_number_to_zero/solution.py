import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# BRUTE FORCE — O(log n) time | O(1) space
# Simulate: even → divide by 2, odd → subtract 1
# ─────────────────────────────────────────────────────────────────────────


def number_of_steps_brute(num):
    steps = 0

    while num > 0:
        if num % 2 == 0:
            num //= 2                            # even → halve
        else:
            num -= 1                             # odd  → drop the last 1-bit
        steps += 1

    return steps


# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(1) time | O(1) space
# popcount + (bit length - 1)
# ─────────────────────────────────────────────────────────────────────────
def number_of_steps(num):
    if num == 0:
        return 0

    return bin(num).count("1") + num.bit_length() - 1


# ── Input ─────────────────────────────────────────────────────────────────
num = int(input())
print(number_of_steps(num))
