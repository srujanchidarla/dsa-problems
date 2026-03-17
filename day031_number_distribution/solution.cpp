#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n) time | O(1) space
// Single pass — bucket each number into positive, negative, or zero
// ─────────────────────────────────────────────────────────────────────────
void distribute(vector<int>& arr) {
    int pos  = 0;                                // count of positive numbers
    int neg  = 0;                                // count of negative numbers
    int zero = 0;                                // count of zeros

    for (int num : arr) {
        if (num > 0)      pos++;                 // positive bucket
        else if (num < 0) neg++;                 // negative bucket
        else              zero++;                // zero bucket
    }

    cout << pos  << endl;                        // print positives
    cout << neg  << endl;                        // print negatives
    cout << zero << endl;                        // print zeros
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;                                    // read count

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];                           // read each number
    }

    distribute(arr);
    return 0;
}