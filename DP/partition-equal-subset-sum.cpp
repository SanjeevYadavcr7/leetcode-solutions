/*
Approach: DP
Time Complexity: O(N.SUM/2)
Space Complexity: O(N.SUM/2)
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for(int i = 0; i <= n; i++) dp[i][0] = true;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];

                if(j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};


/* ------------------------------------------------------------------------------------------------
Approach: Recursion + Memoization
Time Complexity: O(2^N)
Space Complexity: O(N)

class Solution {
private:
    bool canPartitionHelper(int idx, int sumLeft, vector<vector<bool>>& dp, vector<int>& nums) {
        if(sumLeft == 0) return true;
        if(idx >= nums.size() || sumLeft < 0) return false;

        if(dp[idx][sumLeft]) return true;

        dp[idx][sumLeft] = (canPartitionHelper(idx + 1, sumLeft - nums[idx], dp, nums) || 
        canPartitionHelper(idx + 1, sumLeft, dp, nums));

        return dp[idx][sumLeft];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        return canPartitionHelper(0, target, dp, nums);
    }
};

*/
