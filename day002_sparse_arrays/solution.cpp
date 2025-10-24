#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to find the matches using the Optimized Approach
vector<int> matchingStringsOptimized(const vector<string>& stringList, const vector<string>& queries) {
    // 1. Build Frequency Map (O(N))
    unordered_map<string, int> freqMap;
    for (const string& s : stringList) {
        freqMap[s]++;
    }

    // 2. Process Queries (O(M))
    vector<int> results;
    for (const string& q : queries) {
        // Look up the count in O(1) average time, defaulting to 0 if not found
        results.push_back(freqMap.count(q) ? freqMap.at(q) : 0);
    }

    return results;
}

// Function to find the matches using the Brute Force Approach
// Time Complexity: O(N * M)
// Space Complexity: O(1)
vector<int> matchingStringsBruteForce(const vector<string>& stringList, const vector<string>& queries) {
    vector<int> results;
    
    // Iterate through every query (O(M))
    for (const string& query : queries) {
        int count = 0;
        // For every query, iterate through every string in the list (O(N))
        for (const string& s : stringList) {
            if (query == s) {
                count++;
            }
        }
        results.push_back(count);
    }
    return results;
}

