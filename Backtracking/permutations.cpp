class Solution {
public:
    void getPermutations(vector<int>& nums, unordered_map<int, bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if(current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!used[nums[i]]) {
                used[nums[i]] = true;
                current.push_back(nums[i]);

                getPermutations(nums, used, current, result);
                
                used[nums[i]] = false;
                current.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        unordered_map<int, bool> mp;
        getPermutations(nums, mp, current, result);
        return result;    
    }
};
