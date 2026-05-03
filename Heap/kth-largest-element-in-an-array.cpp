class Solution {
public:

    int partition(vector<int>& nums, int beg, int end) {
        // 1. Pick a random index between beg and end
        int randomIdx = beg + rand() % (end - beg + 1);
        
        // 2. Swap it to the 'end' position so the rest of your logic stays exactly the same
        swap(nums[randomIdx], nums[end]);
        
        int pivot = nums[end];
        int i = beg - 1;
        for(int j = beg; j < end; j++) {
            if(nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[end]);
        return (i+1);
    }

    int quickSelect(vector<int>& arr, int low, int high, int k) {
        if (low <= high) {
            int pivotIdx = partition(arr, low, high);

            if (pivotIdx == arr.size() - k) return arr[pivotIdx];
            else if(pivotIdx < arr.size() - k) return quickSelect(arr, pivotIdx + 1, high, k);
            else return quickSelect(arr, low, pivotIdx - 1, k);
        }
        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int beg = 0, end = nums.size() - 1;
        return quickSelect(nums, beg, end, k);
    }
};
