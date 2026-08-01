// Approach: Recursion Solution
// Time Complexity: O(N.M^2)

class Solution {
  private:
    int solve(
        int r, int c1, int c2, 
        vector<vector<int>>& grid, 
        vector<vector<vector<int>>>& dp) {
        
        if(c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size()) {
            return INT_MIN;
        }
        
        if(r == grid.size() - 1) {
            if(c1 == c2) return grid[r][c1];
            else return grid[r][c1] + grid[r][c2];
        }
        
        if(dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }
        
        int currPickup = (c1 == c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]);
        
        int maxPickup = INT_MIN;
        for(int col1 = -1; col1 <= 1; col1++) {
            for(int col2 = -1; col2 <= 1; col2++) {
                int pickup = solve(r + 1, c1 + col1, c2 + col2, grid, dp);
                maxPickup = max(maxPickup, pickup);
            }
        }
        
        return dp[r][c1][c2] = currPickup + maxPickup;
    }
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        
        return solve(0, 0, cols - 1, grid, dp);
    }
};
