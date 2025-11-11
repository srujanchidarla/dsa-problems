#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // For std::min

using namespace std;

// O(N) Time, O(1) Space - Greedy Local Minimization
void solve_ternary_array_cost() {
    int N;
    if (!(cin >> N)) return;

    long long min_total_cost = 0;
    
    // Iterate and process elements one by one
    for (int i = 0; i < N; ++i) {
        int A_i;
        if (!(cin >> A_i)) return;

        // Possible ternary values
        const int TERNARY[] = {0, 1, 2};
        long long min_local_cost = -1; // Use -1 as a flag for uninitialized

        for (int B_i : TERNARY) {
            // Constraint check: A[i] != B[i]
            if (A_i != B_i) {
                // Calculate cost: |A[i] - B[i]|
                long long cost = abs((long long)A_i - B_i);
                
                // Update the minimum local cost
                if (min_local_cost == -1 || cost < min_local_cost) {
                    min_local_cost = cost;
                }
            }
        }
        
        if (min_local_cost != -1) {
            min_total_cost += min_local_cost;
        }
    }

    cout << min_total_cost << endl;
}

int main() {
    // Note: Due to the high range of A[i], use long long for the total cost.
    solve_ternary_array_cost();
    return 0;
}