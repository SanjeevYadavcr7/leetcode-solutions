class Solution {
public:
    // Approach 1: Using additional space for checking
    // void getPermutations(vector<int>& nums, unordered_map<int, bool>& used, vector<int>& current, vector<vector<int>>& result) {
    //     if(current.size() == nums.size()) {
    //         result.push_back(current);
    //         return;
    //     }

    //     for(int i = 0; i < nums.size(); i++) {
    //         if(!used[nums[i]]) {
    //             used[nums[i]] = true;
    //             current.push_back(nums[i]);

    //             getPermutations(nums, used, current, result);
                
    //             used[nums[i]] = false;
    //             current.pop_back();
    //         }
    //     }
    // }

    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> result;
    //     vector<int> current;
    //     unordered_map<int, bool> mp;
    //     getPermutations(nums, mp, current, result);
    //     return result;    
    // }

    // Approach 2: No extra space | Modify original array
    void getPermutations(int idx, vector<int>& nums, vector<vector<int>>& result) {
        if(idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPermutations(idx + 1, nums, result);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        getPermutations(0, nums, result);
        return result;    
    }
};
