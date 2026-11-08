#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) space — check every pair.
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < (int)numbers.size(); i++) {
            for (int j = i + 1; j < (int)numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target) return {i + 1, j + 1};
            }
        }
        return {-1, -1};
    }
};

class Solution {
    // O(n) time | O(1) space — two pointers on the sorted array.
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = (int)numbers.size() - 1;
        while (left < right) {
            int total = numbers[left] + numbers[right];
            if (total == target) return {left + 1, right + 1};
            else if (total < target) left++;
            else right--;
        }
        return {-1, -1};
    }
};
