class Solution {
public:
    int findPivot(vector<int>& nums) {
        int pivot = -1;
        for(int i = nums.size()-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        return pivot;
    }

    void reverse(vector<int>& nums, int beg, int end) {
        while(beg < end) {
            int temp = nums[beg];
            nums[beg] = nums[end];
            nums[end] = temp;
            beg++, end--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return;

        int pivot = findPivot(nums);
        if(pivot == -1) { // nums is in descending order
            reverse(nums, 0, n-1);
            return;
        }
        
        int j = n - 1;
        while (nums[j] <= nums[pivot]) {
            j--;
        }
        swap(nums[pivot], nums[j]);

        reverse(nums, pivot + 1, n-1);
    }
};
