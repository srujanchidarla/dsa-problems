def find_max_pythonic(arr):
    """
    Using Python's built-in max() function. Internally does the same 0(n) comparison.
    """
    if not arr:
        return None
    return max(arr)


n = int(input("Enter number of elements: "))
arr = list(map(int, input().split()))

print(find_max_pythonic(arr))
