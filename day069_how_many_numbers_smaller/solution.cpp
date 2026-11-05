#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n^2) time | O(1) extra space — compare every pair.
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> answer;
        for (int i = 0; i < (int)nums.size(); i++) {
            int count = 0;
            for (int j = 0; j < (int)nums.size(); j++) {
                if (nums[j] < nums[i]) count++;
            }
            answer.push_back(count);
        }
        return answer;
    }
};

class Solution {
    // O(n) time | O(101) space — count values, then prefix sums.
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        for (int v : nums) count[v]++;
        vector<int> smaller(101, 0);
        int running = 0;
        for (int v = 0; v <= 100; v++) {
            smaller[v] = running;
            running += count[v];
        }
        vector<int> answer;
        for (int v : nums) answer.push_back(smaller[v]);
        return answer;
    }
};
