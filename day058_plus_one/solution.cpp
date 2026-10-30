#include <vector>
#include <string>
using namespace std;

class SolutionBruteForce {
    // O(n) time | O(n) space — convert to a number, add 1, convert back.
    // (Uses long long; overflows for very long inputs — the naive idea.)
public:
    vector<int> plusOne(vector<int>& digits) {
        long long number = 0;
        for (int d : digits) number = number * 10 + d;
        number += 1;
        string s = to_string(number);
        vector<int> ans;
        for (char c : s) ans.push_back(c - '0');
        return ans;
    }
};

class Solution {
    // O(n) time | O(1) extra space — carry from the right.
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = (int)digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
