#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, int> roman_map = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

public:
    // Optimized: O(N) Time, O(1) Space - Right-to-Left Traversal
    int romanToInt_optimal(string s) {
        if (s.empty()) return 0;
        
        int total = roman_map[s.back()]; // Start with the last character
        
        // Iterate from the second-to-last character backward
        for (int i = s.length() - 2; i >= 0; --i) {
            int current_val = roman_map[s[i]];
            int next_val = roman_map[s[i+1]];
            
            // Subtraction case (IV, IX, etc.)
            if (current_val < next_val) {
                total -= current_val;
            } else {
                total += current_val;
            }
        }
        return total;
    }

    // Brute Force: O(N) Time, O(1) Space - Left-to-Right Check (Requires careful skip logic)
    int romanToInt_brute(string s) {
        int total = 0;
        int N = s.length();

        for (int i = 0; i < N; ++i) {
            int current_val = roman_map[s[i]];
            
            if (i < N - 1) {
                int next_val = roman_map[s[i+1]];
                
                // If subtraction case, add the pair's difference and skip the next character
                if (current_val < next_val) {
                    total += (next_val - current_val);
                    i++; // Skip the next character as it was just accounted for
                    continue;
                }
            }
            // Default case: add the current character's value
            total += current_val;
        }
        return total;
    }

    void solve() {
        string s;
        if (!getline(cin, s)) return;
        
        int result = romanToInt_optimal(s);
        cout << result << endl;
    }
};

int main() {
    Solution().solve();
    return 0;
}