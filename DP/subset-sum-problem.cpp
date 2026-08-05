/*
Approach: DP
Time Complexity: O(N.Sum) :: Space Complexity: O(N.Sum)
*/
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        for(int i = 0; i <= n; i++) dp[i][0] = true;
        
        
        for(int i = 1; i <=n; i++) {
            for(int j = 1; j <= sum; j++) {
                
                // Don't take current element
                bool skip = dp[i - 1][j];
                
                bool take = false;
                if(arr[i - 1] <= j) {
                    // Take current element
                    take = dp[i - 1][j - arr[i - 1]];
                }
                
                dp[i][j] = (skip || take);
            }
        }
        
        return dp[n][sum];
    }
};


/*-----------------------------------------------------------------------------
Approach: Memoization

class Solution {
  private:
    bool solve(int idx, int target, vector<vector<int>>& memo, vector<int>& arr) {
        if(target == 0) return true;
        
        if(idx >= arr.size() || target < 0) return false;
        
        if(memo[idx][target] != -1) return memo[idx][target];
        
        bool take = solve(idx + 1, target - arr[idx], memo, arr);
        bool skip = solve(idx + 1, target, memo, arr);
        
        return memo[idx][target] = (take || skip);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
        
        return solve(0, sum, memo, arr);
    }
};
*/

/* --------------------------------------------------------------------------------
Approach: Recursion
Time Complexity: O(2^N) :: Space Complexity: O(N)

class Solution {
  private:
    bool solve(int idx, int target, vector<int>& arr) {
        if(target == 0) return true;
        
        if(idx >= arr.size() || target < 0) return false;
        
        bool take = solve(idx + 1, target - arr[idx], arr);
        bool skip = solve(idx + 1, target, arr);
        
        return (take || skip);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        return solve(0, sum, arr);
    }
};

*/
