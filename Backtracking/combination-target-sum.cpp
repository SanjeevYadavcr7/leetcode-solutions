class Solution {
public:
    void getCombinationSum(int idx, int sum, int& target, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        if(sum == target) {
            result.push_back(current);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            if(sum + nums[i] > target) break;

            current.push_back(nums[i]);
            getCombinationSum(i, sum + nums[i], target, nums, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Sorting enables the break optimization
        vector<vector<int>> result;
        vector<int> current;

        getCombinationSum(0, 0, target, nums, current, result);
        return result;
    }
};
