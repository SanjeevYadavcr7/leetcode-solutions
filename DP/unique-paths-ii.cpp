/*
Approach: DP Using 1D array
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If starting or ending cell is blokced -> No way
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        vector<int> dp(n);

        // Base Case: Starting from first cell
        dp[0] = 1;

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(obstacleGrid[r][c] == 1) {
                    dp[c] = 0;
                } else if(c > 0) {
                    // because we have to take left column so always pick from first column
                    dp[c] = dp[c] + dp[c - 1];
                }
            }
        }

        return dp[n - 1];
    }
};



/* ----------------------------------------------------------------------------------
Approach: DP Using 2D array

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1) return 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++) {
            if(obstacleGrid[i][0] == 1) break;
            dp[i][0] = 1;
        }

        for(int j = 1; j < cols; j++) {
            if(obstacleGrid[0][j] == 1) break;
            dp[0][j] = 1;
        }

        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                dp[i][j] = (obstacleGrid[i - 1][j] == 1 ? 0 : dp[i - 1][j]) + 
                (obstacleGrid[i][j - 1] == 1 ? 0 : dp[i][j - 1]);
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
*/


/* ----------------------------------------------------------------------------------
Approach: Recursive Solution

class Solution {
    int rows, cols;

    int getUniquePaths(int row, int col, vector<vector<int>>& grid) {
        // If robot is going out of boundary or current cell is blocked
        if(row >= rows || col >= cols || grid[row][col] == 1) return 0;

        // If robot reaches bottom-right corner
        if(row == rows - 1 && col == cols - 1) return 1;

        return getUniquePaths(row + 1, col, grid) + getUniquePaths(row, col + 1, grid);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rows = obstacleGrid.size();
        cols = obstacleGrid[0].size();

        // If starting or ending cell has an obstacle, no path exists
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        return getUniquePaths(0, 0, obstacleGrid);
    }
};
*/
