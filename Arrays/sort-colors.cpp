class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeroIdx = 0, twoIdx = n-1;

        int idx = 0;
        while(idx <= twoIdx) {
            if(nums[idx] == 0) {
                swap(nums[idx], nums[zeroIdx]);
                zeroIdx++;
                idx++;
            } else if(nums[idx] == 2) {
                swap(nums[idx], nums[twoIdx]);
                twoIdx--;
            } else {
                idx++;
            }
        }
    }
};
