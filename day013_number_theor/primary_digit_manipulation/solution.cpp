#include <iostream>
#include <algorithm>

using namespace std;

// O(log N) Time, O(1) Space
void solve_digit_manipulation() {
    long long N;
    if (!(cin >> N)) return;

    long long original_n = N;
    long long num = abs(N); 

    // --- 1. Count Digits ---
    long long temp_count = num;
    int count = 0;
    
    if (num == 0) { // Edge case: count is 1 for number 0
        count = 1;
    } else {
        while (temp_count > 0) {
            temp_count /= 10;
            count++;
        }
    }
    cout << "Count: " << count << endl;

    // --- 2. Reverse Number ---
    long long temp_reverse = num;
    long long reversed_num = 0;
    
    while (temp_reverse > 0) {
        int last_digit = temp_reverse % 10;
        // Important: check for overflow here in production code
        reversed_num = reversed_num * 10 + last_digit;
        temp_reverse /= 10;
    }
    
    if (original_n < 0) {
        reversed_num *= -1;
    }
        
    cout << "Reversed: " << reversed_num << endl;
}

int main() {
    solve_digit_manipulation();
    return 0;
}