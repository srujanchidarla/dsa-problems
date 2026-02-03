def number_distribution_pythonic(arr):
    """
    Using sum() with generator expressions.
    Clean and readable but makes 3 passes
    """

    zeros = arr.count(0)
    positives = sum(1 for num in arr if num > 0)
    negatives = sum(1 for num in arr if num < 0)

    return zeros, positives, negatives


n = int(input())
arr = list(map(int, input().split()))

zeros, positives, negatives = number_distribution_pythonic(arr)

print(f"Zeros: {zeros} \nPositives: {positives} \nNegatives: {negatives}")
