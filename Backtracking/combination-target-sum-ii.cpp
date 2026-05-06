class Solution {
public:
    void getCombinationSum(int idx, int target, vector<int>& nums , vector<int>& current, vector<vector<int>>& result) {
        if(target == 0) {
            result.push_back(current);
            return;
        }
        if(idx == nums.size()) return;

        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target) break;
            current.push_back(nums[i]);
            getCombinationSum(i + 1, target - nums[i], nums, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;

        getCombinationSum(0, target, candidates, current, result);
        return result;
    }
};
