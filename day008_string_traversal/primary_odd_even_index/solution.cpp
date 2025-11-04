#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// O(N) Time, O(N) Space - Optimal (Single Pass)
void solve_odd_even_index() {
    string S;
    // Read the entire line as the string
    if (!getline(cin, S)) return;

    string even_chars = "";
    string odd_chars = "";

    // Single Linear Pass (O(N))
    for (int i = 0; i < S.length(); ++i) {
        if (i % 2 == 0) {
            even_chars += S[i];
        } else {
            odd_chars += S[i];
        }
    }
    
    cout << even_chars << endl;
    cout << odd_chars << endl;
}

// O(N) Time, O(N) Space - Brute (Same fundamental approach)
void solve_odd_even_index_brute() {
    solve_odd_even_index(); 
}

int main() {
    solve_odd_even_index();
    return 0;
}