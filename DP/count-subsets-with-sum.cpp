/*
Approach - DP (1D array)
*/
class Solution {
    public:
        int perfectSum(vector<int>& arr, int target) {
            int n = arr.size();
            const int MOD = 1e9 + 7;
            vector<int> dp(target + 1, 0);
            
            dp[0] = 1;
            
            for(int i = 0; i < n; i++) {
                for(int j = target; j >= arr[i]; j--) {
                    dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
                }
            }
    
            return dp[target];
        }
};

/*
Approach: DP (2D array)

class Solution {
    public:
        int perfectSum(vector<int>& arr, int target) {
            int n = arr.size();
            const int MOD = 1e9 + 7;
            vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
            
            dp[0][0] = 1;
            
            for(int i = 1; i <= n; i++) {
                for(int j = 0; j <= target; j++) {
                    int skip = dp[i - 1][j];
                    
                    int take = 0;
                    if(arr[i - 1] <= j) {
                        take = dp[i - 1][j - arr[i - 1]];
                    }
                    
                    dp[i][j] = (skip + take) % MOD;
                }
            }
 
            return dp[n][target];
        }
};
*/

/*-------------------------------------------------------------------------------- 
Approach: Recursion + Memoization

class Solution {
    private:
        int solve(int idx, int target, vector<vector<int>>& dp,vector<int>& arr) {
            if(idx == arr.size()) {
                return (target == 0) ? 1 : 0;
            }
            
            if(dp[idx][target] != -1) return dp[idx][target];
            
            int take = 0;
            if(arr[idx] <= target) {
                take = solve(idx + 1, target - arr[idx], dp, arr);
            }
            
            int skip = solve(idx + 1, target, dp, arr);
            return dp[idx][target] = take + skip;            
        }
    public:
        int perfectSum(vector<int>& arr, int target) {
            int n = arr.size();
            vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
            
            return solve(0, target, dp, arr);
        }
};
*/



/*-------------------------------------------------------------------------------- 
Approach: Recursion

class Solution {
    private:
        int solve(int idx, int target, vector<int>& arr) {
            if(idx == arr.size()) {
                return (target == 0) ? 1 : 0;
            }
            
            int take = 0;
            if(arr[idx] <= target) {
                take = solve(idx + 1, target - arr[idx], arr);
            }
            
            int skip = solve(idx + 1, target, arr);
            return take + skip;            
        }
    public:
        int perfectSum(vector<int>& arr, int target) {
            return solve(0, target, arr);
        }
};
*/
