#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Optimized: O(N) Time, O(1) Space (Fixed size array for a-z)
    int firstUniqChar_optimal(string s) {
        // Use a vector/array of size 26 for O(1) space/lookup
        vector<int> counts(26, 0);

        // Pass 1: Count frequencies (O(N))
        for (char c : s) {
            counts[c - 'a']++;
        }

        // Pass 2: Find the first character with count == 1 (O(N))
        for (int i = 0; i < s.length(); ++i) {
            if (counts[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

    // Brute Force: O(N^2) Time
    int firstUniqChar_brute(string s) {
        int N = s.length();
        for (int i = 0; i < N; ++i) {
            bool repeated = false;
            for (int j = 0; j < N; ++j) {
                if (i != j && s[i] == s[j]) {
                    repeated = true;
                    break;
                }
            }
            if (!repeated) {
                return i;
            }
        }
        return -1;
    }

    void solve() {
        string s;
        if (!getline(cin, s)) return;
        cout << firstUniqChar_optimal(s) << endl;
    }
};

int main() {
    Solution().solve();
    return 0;
}