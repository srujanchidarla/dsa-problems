#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(N^2) Time, O(1) Space - Optimal: Transpose then Reverse
void rotateMatrix_optimal(vector<vector<int>>& matrix) {
    int N = matrix.size();

    // 1. Transpose (Swap A[i][j] with A[j][i])
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // 2. Reverse each row
    for (int i = 0; i < N; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// O(N^2) Time, O(N^2) Space - Brute Force (Extra Space)
vector<vector<int>> rotateMatrix_brute(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    vector<vector<int>> rotated(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // New row index is old column index (j)
            // New column index is N - 1 - old row index (i)
            rotated[j][N - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}