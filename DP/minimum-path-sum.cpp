class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);
        dp[0] = grid[0][0]; // starting point

        for(int c = 1; c < n; c++) {
            dp[c] = dp[c - 1] + grid[0][c];
        }

        for(int r = 1; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(c == 0) {
                    dp[c] = dp[c] + grid[r][c];
                } else {
                    dp[c] = min(dp[c - 1], dp[c]) + grid[r][c];
                }
            }
        }

        return dp[n - 1];
    }
};
