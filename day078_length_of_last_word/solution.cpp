#include <sstream>
#include <string>
using namespace std;

class SolutionBruteForce {
    // O(n) time | O(n) space — split into words and take the last one.
public:
    int lengthOfLastWord(string s) {
        istringstream ss(s);
        string word, last;
        while (ss >> word) last = word;
        return (int)last.size();
    }
};

class Solution {
    // O(n) time | O(1) space — walk backwards past trailing spaces, then count.
public:
    int lengthOfLastWord(string s) {
        int i = (int)s.size() - 1;
        while (i >= 0 && s[i] == ' ') i--;
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};
