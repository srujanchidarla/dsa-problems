#include <iostream>
#include <vector>

using namespace std;

void solve_matrix_sums() {
    // Fast I/O is good practice
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    
    // Read N and M
    if (!(cin >> N >> M)) return;

    // O(M) Space: Initialize vector to store column sums
    vector<long long> col_sums(M, 0);
    
    // Vector to store row sums for the first required output format (Row Sums)
    vector<long long> row_sums_output;

    // --- Combined Input Pass (O(N*M)) ---
    for (int i = 0; i < N; ++i) {
        long long row_sum = 0; 
        
        for (int j = 0; j < M; ++j) {
            int element;
            if (!(cin >> element)) return; // Read the element

            // 1. Row Sum Calculation (Streaming)
            row_sum += element;

            // 2. Column Sum Calculation (Storage)
            col_sums[j] += element;
        }
        
        // Store Row Sum
        row_sums_output.push_back(row_sum);
    }

    // --- Print Row Sums (Output for Problem 1: Matrix Row Sum) ---
    for (long long sum : row_sums_output) {
        cout << sum << "\n";
    }

    // --- Print Column Sums (Output for Problem 2: Matrix Column Sum) ---
    // Note: Added separator for combined testing; remove for individual problem submission.
    cout << "--- Column Sums ---\n"; 
    for (long long sum : col_sums) {
        cout << sum << "\n";
    }
}

int main() {
    solve_matrix_sums();
    return 0;
}