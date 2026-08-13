/*------------------------------------------------------------------------------------
Approach: Naive Recursion
Time Complexity: O(2^N), where N is number of elements in nums[]

class Solution {
private:
    int getWays(int idx, int target, vector<int>& nums) {
        if(idx == nums.size()) return target == 0;

        int pos = getWays(idx + 1, target - nums[idx], nums);
        int neg = getWays(idx + 1, target + nums[idx], nums);
        return pos + neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return getWays(0, target, nums);
    }
};
*/
