#include <algorithm>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O(n) time | O(n) space — build a reversed copy, then copy it back.
public:
    void reverseString(vector<char>& s) {
        vector<char> rev = s;
        reverse(rev.begin(), rev.end());
        s = rev;
    }
};

class Solution {
    // O(n) time | O(1) space — two pointers swap from both ends.
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
