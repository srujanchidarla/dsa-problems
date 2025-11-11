#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// O(N^2) Time, O(N^2) Space - Optimal: Index Grouping
void diagonalTraversal_optimal(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;
    int R = matrix.size();
    int C = matrix[0].size();

    // Map: key = i + j (sum of indices), value = list of elements on that diagonal
    map<int, vector<int>> diagonals;

    // 1. Group elements by the sum of their indices (O(N^2))
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            diagonals[i + j].push_back(matrix[i][j]);
        }
    }

    // 2. Traverse the diagonals (O(N^2))
    // The problem often implies alternating direction. For simplicity, we reverse one direction.
    vector<int> result;
    bool direction_up = true; // Start direction (up-right)

    for (auto const& [sum, elements] : diagonals) {
        vector<int> current_diagonal = elements;
        
        // Reverse the diagonal if the problem requires alternating directions
        if (direction_up) {
            reverse(current_diagonal.begin(), current_diagonal.end());
        }
        
        // Add to result
        result.insert(result.end(), current_diagonal.begin(), current_diagonal.end());
        
        // Flip direction for the next diagonal
        direction_up = !direction_up;
    }
    
    // Print the space-separated output
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;
}

// Brute Force is identical to Optimal here, as O(N^2) is mandatory.