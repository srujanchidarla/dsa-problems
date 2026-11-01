#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class SolutionBruteForce {
    // O((m+n) log(m+n)) time | O(m+n) space — merge, sort, pick the middle.
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = nums1;
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        sort(merged.begin(), merged.end());
        int n = (int)merged.size();
        if (n % 2 == 1) return merged[n / 2];
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};

class Solution {
    // O(log(min(m, n))) time | O(1) space — binary search the partition cut.
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search the shorter array.
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int m = (int)nums1.size(), n = (int)nums2.size();
        int half = (m + n + 1) / 2;
        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = (lo + hi) / 2;   // cut in nums1: i elements on the left
            int j = half - i;        // cut in nums2: j elements on the left
            double left1 = i > 0 ? nums1[i - 1] : -1e18;
            double right1 = i < m ? nums1[i] : 1e18;
            double left2 = j > 0 ? nums2[j - 1] : -1e18;
            double right2 = j < n ? nums2[j] : 1e18;
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 1) return max(left1, left2);
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else if (left1 > right2) {
                hi = i - 1;          // cut in nums1 is too far right
            } else {
                lo = i + 1;          // cut in nums1 is too far left
            }
        }
        return 0.0;
    }
};
