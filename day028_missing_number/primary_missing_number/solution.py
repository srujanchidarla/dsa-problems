def find_missing_xor(arr):
    """
    Find missing number using XOR method.
    step 1: XOR all the numbers from 1 to n
    step 2: XOR all the elements in array
    step 3: XOR the results of step 1 and step 2 to get the missing number
    """

    n = 100

    xor_full = 0
    for i in range(1, n + 1):
        xor_full ^= i
    xor_arr = 0
    for num in arr:
        xor_arr ^= num
    missing_number = xor_full ^ xor_arr
    return missing_number


arr = list(map(int, input().split()))

print(find_missing_xor(arr))
