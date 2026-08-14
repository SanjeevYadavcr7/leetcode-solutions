/*------------------------------------------------------------------------------------
Approach: Recursion + Memoization
Time Complexity: O(2^N), where N is number of elements in nums[]

class Solution {
private:
    int getWays(int idx, int target, vector<vector<int>>& memo, vector<int>& nums) {
        if(idx == nums.size()) {
            return target == 0 ? 1 : 0;
        } 
        
        if(target < 0) return 0;

        if(memo[idx][target] != -1) return memo[idx][target];
        
        int skip = getWays(idx + 1, target, memo, nums);
        int take = getWays(idx + 1, target - nums[idx], memo, nums);
        return memo[idx][target] = skip + take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > totalSum || ((totalSum + target) & 1))  return 0;

        int s1 = (totalSum + target) >> 1;
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(s1 + 1, -1));

        return getWays(0, s1, memo, nums);
    }
};
*/

/*------------------------------------------------------------------------------------
Approach: Naive Recursion
Time Complexity: O(2^N), where N is number of elements in nums[]

class Solution {
private:
    int getWays(int idx, int target, vector<int>& nums) {z
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
