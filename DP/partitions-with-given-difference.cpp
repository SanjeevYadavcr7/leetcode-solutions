/*
Approach: DP (1D array)
*/

class Solution {
      public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        // if two equal partition is not possible -> return 0
        if((sum + diff) & 1) return 0; 
        
        int target = (sum + diff) >> 1;
        vector<int> dp(target + 1, 0);
        
        // Only marking 0th index because array itself can have 0s which will increase count of first row
        dp[0] = 1;
        
        for(int& num : arr) {
            for(int t = target; t >= num; t--) {
                dp[t] = (dp[t] + dp[t - num]) % MOD;
            }
        }
        
        return dp[target];
    }
};

/*---------------------------------------------------------------------------
Approach: DP (2D array)

class Solution {
      public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        // if two equal partition is not possible -> return 0
        if((sum + diff) & 1) return 0; 
        
        int target = (sum + diff) >> 1;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // Only marking (0,0) because array itself can have 0s which will increase count of first row
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                int skip = dp[i - 1][j];
                
                int take = 0;
                if(arr[i - 1] <= j) {
                    take = dp[i - 1][j - arr[i - 1]];
                }
                
                dp[i][j] = skip + take;
            }
        }
        
        return dp[n][target];
    }
};
*/

/*---------------------------------------------------------------------------
Approach: Recursion + Memoization

class Solution {
  private:
    int solve(int idx, int target, vector<vector<int>>& dp, vector<int>& arr) {
        if(idx == arr.size()) {
            return target == 0 ? 1 : 0;
        }
        
        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }
        
        int take = 0;
        if(arr[idx] <= target) {
            take = solve(idx + 1, target - arr[idx], dp, arr);   
        }
        
        int skip = solve(idx + 1, target, dp, arr);
        
        return dp[idx][target] = (take + skip);
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if((sum + diff) & 1) return 0;
        
        int target = (sum + diff) >> 1;
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        
        return solve(0, target, dp, arr);
    }
};
*/
