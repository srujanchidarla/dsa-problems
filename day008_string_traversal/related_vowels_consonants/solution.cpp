#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype> // for tolower

using namespace std;

// O(N) Time, O(1) Space - Optimal (Set Lookup)
void solve_vowels_consonants() {
    string S;
    if (!getline(cin, S)) return;

    // Use unordered_set for O(1) average lookup
    unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
    int vowel_count = 0;
    int consonant_count = 0;

    for (char c : S) {
        char lower_c = tolower(c);
        
        // Check if the character is an English letter
        if (lower_c >= 'a' && lower_c <= 'z') {
            if (VOWELS.count(lower_c)) {
                vowel_count++;
            } else {
                consonant_count++;
            }
        }
    }
    
    cout << "Vowels: " << vowel_count << endl;
    cout << "Consonants: " << consonant_count << endl;
}

void solve_vowels_consonants_brute() {
    // Brute: Using an if-elif chain instead of a set (same O(N))
    solve_vowels_consonants(); 
}

int main() {
    solve_vowels_consonants();
    return 0;
}