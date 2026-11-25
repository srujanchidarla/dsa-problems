class SolutionBruteForce:
    """O(n * k) time | O(1) space — re-sum every window of size k."""

    def numOfSubarrays(self, arr: list[int], k: int, threshold: int) -> int:
        count = 0
        for i in range(len(arr) - k + 1):
            if sum(arr[i:i + k]) / k >= threshold:
                count += 1
        return count


class Solution:
    """O(n) time | O(1) space — sliding window; compare sum against k * threshold."""

    def numOfSubarrays(self, arr: list[int], k: int, threshold: int) -> int:
        window = sum(arr[:k])
        count = 1 if window >= k * threshold else 0
        for i in range(k, len(arr)):
            window += arr[i] - arr[i - k]
            if window >= k * threshold:
                count += 1
        return count
