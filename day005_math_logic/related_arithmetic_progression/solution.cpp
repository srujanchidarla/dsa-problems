#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// O(N) Time, O(1) Space - Optimal/Brute
bool isArithmeticProgression(const vector<int>& nums) {
    int N = nums.size();
    
    // Trivial cases: 0, 1, or 2 elements always form an AP
    if (N <= 2) return true; 

    // Calculate the common difference (O(1))
    int diff = nums[1] - nums[0];

    // Check every consecutive difference (O(N))
    for (int i = 2; i < N; ++i) {
        if (nums[i] - nums[i-1] != diff) {
            return false;
        }
    }
    return true;
}

void solve_arithmetic_progression() {
    int N;
    // Assuming input format starts with N, followed by N integers
    if (!(cin >> N)) return; 

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> nums[i])) return;
    }

    if (isArithmeticProgression(nums)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    solve_arithmetic_progression();
    return 0;
}