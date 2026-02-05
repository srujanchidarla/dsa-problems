def find_duplicate_hashset(arr):
    """
    Use set to track seen numbers.

    Step 1: Initialize empty set
    Step 2: For each number, check if already in set
    Step 3: If yes, it's duplicate. If no, add to set
    """
    seen = set()

    for num in arr:
        # If already seen, it's the duplicate
        if num in seen:
            return num
        # Add to set
        seen.add(num)

    return None
