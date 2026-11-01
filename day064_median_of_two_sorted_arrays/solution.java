class SolutionBruteForce {
    // O((m+n) log(m+n)) time | O(m+n) space — merge, sort, pick the middle.
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[] merged = new int[m + n];
        System.arraycopy(nums1, 0, merged, 0, m);
        System.arraycopy(nums2, 0, merged, m, n);
        java.util.Arrays.sort(merged);
        int total = m + n;
        if (total % 2 == 1) return merged[total / 2];
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    }
}

class Solution {
    // O(log(min(m, n))) time | O(1) space — binary search the partition cut.
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // Always binary search the shorter array.
        if (nums1.length > nums2.length) {
            int[] tmp = nums1; nums1 = nums2; nums2 = tmp;
        }
        int m = nums1.length, n = nums2.length;
        int half = (m + n + 1) / 2;
        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = (lo + hi) / 2;   // cut in nums1: i elements on the left
            int j = half - i;        // cut in nums2: j elements on the left
            double left1 = i > 0 ? nums1[i - 1] : Double.NEGATIVE_INFINITY;
            double right1 = i < m ? nums1[i] : Double.POSITIVE_INFINITY;
            double left2 = j > 0 ? nums2[j - 1] : Double.NEGATIVE_INFINITY;
            double right2 = j < n ? nums2[j] : Double.POSITIVE_INFINITY;
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 1) return Math.max(left1, left2);
                return (Math.max(left1, left2) + Math.min(right1, right2)) / 2.0;
            } else if (left1 > right2) {
                hi = i - 1;          // cut in nums1 is too far right
            } else {
                lo = i + 1;          // cut in nums1 is too far left
            }
        }
        return 0.0;
    }
}
