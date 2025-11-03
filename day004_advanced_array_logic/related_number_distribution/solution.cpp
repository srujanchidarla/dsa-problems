#include <iostream>
#include <vector>
#include <map> // Used for sorted output (like Java's TreeMap)
#include <algorithm> // Required for sorting

using namespace std;

// Optimized: O(N log K) Time, O(N) Space - Uses std::map for frequency count and sorted keys
void solve_number_distribution_optimal() {
    int N;
    if (!(cin >> N)) return; 

    // O(N) space map stores frequencies. map insertion is O(log K).
    map<int, int> counts; 
    
    for (int i = 0; i < N; ++i) {
        int num;
        if (!(cin >> num)) return;
        // If element exists, increment; otherwise, insert with count 1
        counts[num]++;
    }
    
    // Print the results (sorted by key due to std::map)
    for (const auto& pair : counts) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Brute Force: O(N log N) Time, O(N) Space - Sorts the array and iterates
void solve_number_distribution_brute() {
    int N;
    if (!(cin >> N)) return; 

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> nums[i])) return;
    }

    if (N == 0) return;

    // Sort the array (O(N log N))
    sort(nums.begin(), nums.end());

    int currentElement = nums[0];
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (nums[i] == currentElement) {
            count++;
        } else {
            cout << currentElement << ": " << count << endl;
            currentElement = nums[i];
            count = 1;
        }
    }
    // Print the last element's count
    cout << currentElement << ": " << count << endl;
}

int main() {
    // Choose the optimal solution for final submission
    solve_number_distribution_optimal(); 
    return 0;
}