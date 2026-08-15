/*----------------------------------------------------------------------------
Approach: DP (2D array)

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            int currWeight = wt[i - 1];
            int currVal = val[i - 1];
            
            for(int j = 1; j <= capacity; j++) {
                int skip = dp[i - 1][j];
                
                int take = 0;
                if(j >= currWeight) {
                    take = currVal + dp[i][j - currWeight];
                }
                
                dp[i][j] = max(skip, take);
            }
        }
        
        return dp[n][capacity];
    }
};
*/

/*----------------------------------------------------------------------------
Approach: Recursion + Memoization

class Solution {
    int getMaxProfit(int idx, int cap, vector<int>& val, vector<int>& wt, vector<vector<int>>& memo) {
        if(idx == val.size() || cap <= 0) return 0;
        
        if(memo[idx][cap] != -1) return memo[idx][cap];
        
        int skip = getMaxProfit(idx + 1, cap, val, wt, memo);
        
        int take = 0;
        if(cap >= wt[idx]) {
            take = val[idx] + getMaxProfit(idx, cap - wt[idx], val, wt, memo);   
        }
        
        return memo[idx][cap] = max(skip, take);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> memo(n + 1, vector<int>(capacity + 1, -1));
        
        return getMaxProfit(0, capacity, val, wt, memo);
    }
};
*/
