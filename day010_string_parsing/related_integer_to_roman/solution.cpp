#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Lookup tables must be ordered from largest to smallest for the greedy approach
    const vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

public:
    // O(1) Time, O(1) Space - Optimal (Greedy Lookup)
    string intToRoman_optimal(int num) {
        string result = "";
        
        // Iterate through the 13 defined values
        for (int i = 0; i < values.size() && num > 0; ++i) {
            // Greedily append the symbol as long as the value fits
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        return result;
    }
    
    // Brute Force: O(1) Time - The problem complexity is fixed, so this is the baseline.
    string intToRoman_brute(int num) {
        return intToRoman_optimal(num);
    }

    void solve() {
        int num;
        if (!(cin >> num)) return;
        cout << intToRoman_optimal(num) << endl;
    }
};

int main() {
    Solution().solve();
    return 0;
}