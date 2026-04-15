class Solution {
public:
    /* 
        Naive: O(N^2)
        Optmizied Approach: O(N) | O(N)
    */

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // Map : value -> index

        for(int i = 0; i < nums.size(); i++) {
            int req_num = target - nums[i];

            if(seen.find(req_num) != seen.end()) {
                return {seen[req_num], i};
            }

            seen[nums[i]] = i;
        }
        return {};
    }
};