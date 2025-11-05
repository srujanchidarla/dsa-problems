#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// O(N) Time, O(N) Space - Optimal (Single Pass with Counting)
void solve_compress_string() {
    string S;
    if (!getline(cin, S) || S.empty()) {
        cout << "" << endl;
        return;
    }

    stringstream compressed;
    int N = S.length();
    int i = 0;

    while (i < N) {
        char current_char = S[i];
        int count = 0;
        int j = i;

        // Count the consecutive run
        while (j < N && S[j] == current_char) {
            count++;
            j++;
        }
        
        // Append character and count
        compressed << current_char << count;
        
        // Move i to the start of the next run
        i = j;
    }
    
    cout << compressed.str() << endl;
}

void solve_compress_string_brute() {
    solve_compress_string();
}

int main() {
    solve_compress_string();
    return 0;
}