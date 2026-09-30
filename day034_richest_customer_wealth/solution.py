import sys
input = sys.stdin.readline

# ─────────────────────────────────────────────────────────────────────────
# OPTIMIZED — O(m × n) time | O(1) space
# Sum each row, keep a running max
# ─────────────────────────────────────────────────────────────────────────


def maximum_wealth(accounts):
    best = 0                                     # richest wealth so far

    for customer in accounts:
        wealth = sum(customer)                   # total for this customer
        best = max(best, wealth)                 # update running max

    return best


# ── Pythonic alternative (same complexity) ───────────────────────────────
def maximum_wealth_pythonic(accounts):
    return max(map(sum, accounts))


# ── Input ─────────────────────────────────────────────────────────────────
m, n = map(int, input().split())
accounts = [list(map(int, input().split())) for _ in range(m)]

print(maximum_wealth(accounts))
