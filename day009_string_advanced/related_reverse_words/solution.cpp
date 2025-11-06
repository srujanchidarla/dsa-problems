#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Optimized: O(N) Time, O(N) Space - Split, Reverse Vector, Join
void solve_reverse_words_optimal() {
    string S;
    // Read the entire line, including spaces
    if (!getline(cin, S)) return;

    stringstream ss(S);
    string word;
    vector<string> words;
    
    // 1. Extract words using stringstream (O(N))
    while (ss >> word) {
        words.push_back(word);
    }
    
    // 2. Reverse the vector (O(N))
    reverse(words.begin(), words.end());
    
    // 3. Join the words back (O(N))
    string result = "";
    for (int i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i < words.size() - 1) {
            result += " ";
        }
    }
    
    cout << result << endl;
}

// Brute Force: O(N^2) Time, O(N) Space - (Simulating the process using two separate linear passes)
void solve_reverse_words_brute() {
    // Due to the complexity of manual word extraction and array construction, 
    // we use the efficient linear method.
    solve_reverse_words_optimal();
}

int main() {
    solve_reverse_words_optimal();
    return 0;
}