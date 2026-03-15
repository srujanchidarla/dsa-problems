#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// BRUTE FORCE — O(n²) time | O(1) space
// ─────────────────────────────────────────────────────────────────────────
int findMaxBrute(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool isMax = true;
        for (int j = 0; j < n; j++) {       // compare arr[i] with everyone
            if (arr[j] > arr[i]) {
                isMax = false;
                break;
            }
        }
        if (isMax) return arr[i];
    }
    return arr[0];
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(n) time | O(1) space
// Single pass, track maximum as we go
// ─────────────────────────────────────────────────────────────────────────
int findMax(vector<int>& arr) {
    int maxVal = arr[0];                     // initialize to first element, NOT 0

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {               // found a new maximum
            maxVal = arr[i];                 // update our best
        }
    }
    return maxVal;
}

int main() {
    ios_base::sync_with_stdio(false);        // fast input
    cin.tie(NULL);

    int n;
    cin >> n;                                // read array size

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];                       // read each element
    }

    cout << findMax(arr) << endl;            // print the maximum
    return 0;
}