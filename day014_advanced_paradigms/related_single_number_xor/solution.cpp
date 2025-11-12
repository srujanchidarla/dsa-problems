#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Optimized: O(N) Time, O(1) Space - XOR Application
    int singleNumber_optimal(const vector<int>& nums) {
        int result = 0;
        // XOR all elements together
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }

    // Brute Force: O(N) Time, O(N) Space - Hash Map/Set
    int singleNumber_brute(const vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        for (auto const& [num, count] : counts) {
            if (count == 1) {
                return num;
            }
        }
        return -1; // Should not happen
    }
};