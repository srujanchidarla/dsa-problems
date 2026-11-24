#include <unordered_map>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n * k) time | O(1) space — for each index, check the next k positions.
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= i + k && j < n; j++) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};

class Solution {
    // O(n) time | O(n) space — map each value to its latest index.
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> last;
        for (int i = 0; i < (int)nums.size(); i++) {
            auto it = last.find(nums[i]);
            if (it != last.end() && i - it->second <= k) return true;
            last[nums[i]] = i;
        }
        return false;
    }
};
