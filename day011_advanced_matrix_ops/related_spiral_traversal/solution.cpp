#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(N^2) Time, O(1) Space - Optimal: Boundary Pointers
void spiralTraversal_optimal(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;
    int R = matrix.size();
    int C = matrix[0].size();
    
    // Initialize boundary pointers
    int top = 0, bottom = R - 1;
    int left = 0, right = C - 1;

    while (top <= bottom && left <= right) {
        // 1. Traverse Right (Top row)
        for (int j = left; j <= right; ++j) {
            cout << matrix[top][j] << " ";
        }
        top++;

        // 2. Traverse Down (Right column)
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        right--;

        // 3. Traverse Left (Bottom row) - Check if row still exists
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                cout << matrix[bottom][j] << " ";
            }
            bottom--;
        }

        // 4. Traverse Up (Left column) - Check if column still exists
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

// Brute Force: O(N^2) Time, O(N^2) Space - Using a 'visited' array
// (Not implemented, as the problem requests the O(1) space solution)