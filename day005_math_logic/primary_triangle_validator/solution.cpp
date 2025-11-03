#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// O(1) Time, O(1) Space
bool isTriangleValid_optimal(int a, int b, int c) {
    // Optimal: Direct application of the Triangle Inequality Theorem.
    if (a <= 0 || b <= 0 || c <= 0) return false;
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// O(1) Time, O(1) Space (Brute force is unnecessary here, but shown for structure)
bool isTriangleValid_brute(int a, int b, int c) {
    // Brute: Sort the sides and only check the condition for the largest side.
    // If a+b > c, the other two conditions (a+c > b and b+c > a) are automatically true.
    vector<int> sides = {a, b, c};
    sort(sides.begin(), sides.end());
    
    // Check if the sum of the two smaller sides is greater than the largest side.
    if (sides[0] <= 0) return false; // Check for positive lengths
    return sides[0] + sides[1] > sides[2];
}

void solve_triangle_validator() {
    int a, b, c;
    if (!(cin >> a >> b >> c)) return;

    if (isTriangleValid_optimal(a, b, c)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
}

int main() {
    solve_triangle_validator();
    return 0;
}