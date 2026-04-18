class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;

        int end1 = m - 1, end2 = n - 1;
        int curr_last_idx = m + n - 1; // last index of nums1 array

        while(end1 >= 0 && end2 >= 0) {
            if(nums1[end1] >= nums2[end2]) {
                nums1[curr_last_idx--] = nums1[end1--];
            } else {
                nums1[curr_last_idx--] = nums2[end2--];
            }
        }

        while(end2 >= 0) {
                nums1[curr_last_idx--] = nums2[end2--];
        }
    }
};
