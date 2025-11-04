#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Optimized: O(N) Time, O(1) Space - Use a fixed-size boolean array (hashing)
void solve_letter_coverage() {
    string S;
    if (!getline(cin, S)) return;

    // Fixed size array for a-z (O(1) space)
    vector<bool> seen(26, false);
    int unique_count = 0;

    for (char c : S) {
        char lower_c = tolower(c);
        
        if (lower_c >= 'a' && lower_c <= 'z') {
            int index = lower_c - 'a';
            
            if (!seen[index]) {
                seen[index] = true;
                unique_count++;
            }
        }
    }
    
    if (unique_count == 26) {
        cout << "Pangram: YES" << endl;
    } else {
        cout << "Pangram: NO" << endl;
    }
}

void solve_letter_coverage_brute() {
    // Brute: Checking each letter 'a' through 'z' individually using string::find (O(N*26) approx O(N))
    solve_letter_coverage(); 
}

int main() {
    solve_letter_coverage();
    return 0;
}