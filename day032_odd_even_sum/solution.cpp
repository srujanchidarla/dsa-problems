#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n) time | O(1) space
// Single pass — add each number to odd or even accumulator
// ─────────────────────────────────────────────────────────────────────────
void oddEvenSum(vector<int>& arr) {
    long long oddSum  = 0;                       // sum of all odd numbers
    long long evenSum = 0;                       // sum of all even numbers

    for (int num : arr) {
        if (abs(num % 2) == 1) {                 // abs handles negative numbers
            oddSum  += num;                      // odd bucket
        } else {
            evenSum += num;                      // even bucket
        }
    }

    cout << oddSum  << endl;                     // print odd sum
    cout << evenSum << endl;                     // print even sum
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    oddEvenSum(arr);
    return 0;
}