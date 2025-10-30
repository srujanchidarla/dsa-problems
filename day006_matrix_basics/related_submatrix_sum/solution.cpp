#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to solve Submatrix Sum using the optimal 2D Prefix Sum technique
void solve_submatrix_sum() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return;

    int r1, c1, r2, c2; // i, j, k, l in problem description
    if (!(cin >> r1 >> c1 >> r2 >> c2)) return;

    // 1. Read and Store Matrix
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(cin >> matrix[i][j])) return;
        }
    }

    // 2. Pre-calculate 2D Prefix Sum Array (O(N^2) Preprocessing)
    // ps[i][j] stores the sum of the sub-matrix from (0, 0) to (i-1, j-1)
    vector<vector<int>> ps(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            ps[i][j] = matrix[i-1][j-1] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }

    // 3. Query the Submatrix Sum (O(1) Query)
    // The query is for the region [r1, c1] to [r2, c2].
    // ps is 1-indexed, so we use r2+1, c2+1, etc.
    long long total_sum = 0;
    
    // Sum(r1, c1, r2, c2) = PS[r2+1][c2+1] - PS[r1][c2+1] - PS[r2+1][c1] + PS[r1][c1]
    total_sum = ps[r2 + 1][c2 + 1] 
                - ps[r1][c2 + 1] 
                - ps[r2 + 1][c1] 
                + ps[r1][c1];

    cout << total_sum << endl;
}

// Optional: Brute force approach for comparison (O(N^2) per query)
long long submatrix_sum_brute(const vector<vector<int>>& matrix, int r1, int c1, int r2, int c2) {
    long long sum = 0;
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    solve_submatrix_sum();
    return 0;
}