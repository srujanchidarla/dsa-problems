#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n) time | O(n) space — collect non-zeroes, then pad with zeroes.
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> kept;
        for (int x : nums) if (x != 0) kept.push_back(x);
        kept.resize(nums.size(), 0);
        nums = kept;
    }
};

class Solution {
    // O(n) time | O(1) space — read/write pointers, fill tail with 0.
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        for (int read = 0; read < (int)nums.size(); read++)
            if (nums[read] != 0) nums[write++] = nums[read];
        for (int i = write; i < (int)nums.size(); i++) nums[i] = 0;
    }
};
