class Solution {
public:
    // Approach 1:
    void generateSubsets(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& result) {
        if(idx == nums.size()) return;

        temp.push_back(nums[idx]);
        result.push_back(temp);
        for(int i = idx + 1; i < nums.size(); i++) {
            generateSubsets(nums, i, temp, result);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for(int i = 0; i < nums.size(); i++) {
            vector<int> temp;
            generateSubsets(nums, i, temp, result);
        }
        return result;
    }


    // Approach 2:
    void generateSubsets(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& result) {
        if(idx == nums.size()) {
            result.push_back(subset);
            return;
        }

        // Decision 1: Pick the current element
        subset.push_back(nums[idx]);
        generateSubsets(nums, idx+1, subset, result);

        // BACKTRACK: Undo the decision before exploring the other branch
        subset.pop_back();

        // Decision 2: Do NOT pick the current element
        generateSubsets(nums, idx+1, subset, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        generateSubsets(nums, 0, subset, result);
        return result;
    }
};
