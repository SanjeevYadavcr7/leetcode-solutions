/*
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
