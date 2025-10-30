#include <iostream>
#include <vector>

using namespace std;

void solve_lower_triangle_sum() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return;

    // 1. Read and Store Matrix (O(N^2) Space)
    vector<vector<int>> matrix(N, vector<int>(N));
    long long lower_triangle_sum = 0;

    // 2. Combined Read and Sum (O(N^2) Traversal)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int element;
            if (!(cin >> element)) return;
            matrix[i][j] = element; // Store the matrix

            // Check the lower triangle condition: row index >= column index
            if (i >= j) {
                lower_triangle_sum += element;
            }
        }
    }

    cout << lower_triangle_sum << endl;
}

int main() {
    solve_lower_triangle_sum();
    return 0;
}