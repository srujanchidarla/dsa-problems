#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// O(N) Time, O(1) Space - Optimal (Single Pass)
void calculateOddEvenSum_optimal(const vector<int>& nums) {
    long long odd_sum = 0;
    long long even_sum = 0;

    // Single Linear Pass (O(N))
    for (int num : nums) {
        if (num % 2 == 0) {
            even_sum += num;
        } else {
            odd_sum += num;
        }
    }
    
    // Output format: typically "odd_sum even_sum" or newline separated
    cout << odd_sum << endl;
    cout << even_sum << endl;
}

// O(N) Time, O(1) Space - Brute (Same logic, simple iteration is the "brute" baseline)
void calculateOddEvenSum_brute(const vector<int>& nums) {
    // The logic remains identical since complexity cannot be worse than O(N)
    calculateOddEvenSum_optimal(nums);
}

void solve_odd_even_sum() {
    int N;
    if (!(cin >> N)) return; 

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> nums[i])) return;
    }

    calculateOddEvenSum_optimal(nums);
}

int main() {
    solve_odd_even_sum();
    return 0;
}