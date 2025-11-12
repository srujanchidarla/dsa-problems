#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Helper function to count digits (O(log N))
int countDigits(long long n) {
    if (n == 0) return 1;
    n = abs(n);
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

// O(log N) Time, O(1) Space - Optimal
bool isPalindrome_optimal(long long n) {
    if (n < 0) return false;
    long long original = n;
    long long reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return original == reversed;
}

// O(log N) Time, O(1) Space - Optimal
bool isArmstrong_optimal(long long n) {
    if (n < 0) return false;
    int D = countDigits(n);
    long long original = n;
    long long sum = 0;
    
    while (n > 0) {
        int last_digit = n % 10;
        // Use pow() or loop D times for better precision/safety
        sum += round(pow(last_digit, D));
        n /= 10;
    }
    return original == sum;
}

void solve_palindrome_armstrong() {
    long long N;
    if (!(cin >> N)) return;
    
    cout << "Palindrome: " << (isPalindrome_optimal(N) ? "YES" : "NO") << endl;
    cout << "Armstrong: " << (isArmstrong_optimal(N) ? "YES" : "NO") << endl;
}

int main() {
    solve_palindrome_armstrong();
    return 0;
}