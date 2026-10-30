#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — count occurrences of each element.
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int x : nums) {
            int count = 0;
            for (int y : nums) if (y == x) count++;
            if (count > n / 2) return x;
        }
        return -1; // unreachable: majority is guaranteed to exist
    }
};

class Solution {
    // O(n) time | O(1) space — Boyer-Moore majority vote.
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int x : nums) {
            if (count == 0) candidate = x;
            count += (x == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
