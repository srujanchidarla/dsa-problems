#include <cstdlib>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) extra space — check every value 1..n by scanning.
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> answer;
        for (int x = 1; x <= (int)nums.size(); x++) {
            bool found = false;
            for (int v : nums) if (v == x) { found = true; break; }
            if (!found) answer.push_back(x);
        }
        return answer;
    }
};

class Solution {
    // O(n) time | O(1) extra space — mark seen values by flipping signs.
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int v : nums) {
            int i = abs(v) - 1;
            if (nums[i] > 0) nums[i] = -nums[i];   // value (i + 1) is present
        }
        vector<int> answer;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] > 0) answer.push_back(i + 1);
        }
        return answer;
    }
};
