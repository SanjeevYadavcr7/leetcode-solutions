class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end()); // sorting nums to use 2-pointers

        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while(left < right) {
                    long long sum  = 0L + nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int left_num = nums[left];
                        int right_num = nums[right];
                        while(left < right && nums[left] == left_num) left++;
                        while(left < right && nums[right] == right_num) right--;
                    } 
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }
        return res;
    }
};
