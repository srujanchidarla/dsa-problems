#include <numeric>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n * k) time | O(1) space — re-sum every window of size k.
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        for (int i = 0; i + k <= (int)arr.size(); i++) {
            int sum = accumulate(arr.begin() + i, arr.begin() + i + k, 0);
            if (sum / (double)k >= threshold) count++;
        }
        return count;
    }
};

class Solution {
    // O(n) time | O(1) space — sliding window; compare sum against k * threshold.
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int window = 0;
        for (int i = 0; i < k; i++) window += arr[i];
        int count = window >= k * threshold ? 1 : 0;
        for (int i = k; i < (int)arr.size(); i++) {
            window += arr[i] - arr[i - k];
            if (window >= k * threshold) count++;
        }
        return count;
    }
};
