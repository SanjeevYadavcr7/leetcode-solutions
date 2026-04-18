class Solution {
public:
    // Dutch National Flag Algorithm
    
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low, mid, high;

        low = mid = 0, high = n - 1;
        while(mid <= high) {
            if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else {
                if(nums[mid] == 0) {
                    swap(nums[low], nums[mid]);
                    low++;
                }
                mid++;
            }
        }
    }
};
