import java.util.Arrays;

class SolutionBruteForce {
    // O((m+n) log(m+n)) time | O(1) space — copy nums2 into the tail, then sort.
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i < n; i++) nums1[m + i] = nums2[i];
        Arrays.sort(nums1);
    }
}

class Solution {
    // O(m+n) time | O(1) space — three pointers, merge from the end.
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
    }
}
