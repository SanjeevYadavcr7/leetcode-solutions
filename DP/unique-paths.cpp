
// Dynamic Programming Solution:

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        dp[0][0] = 1;
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

/*
Recursive Solution:

class Solution {
private:
    int traverseGrid(int row, int col, int m, int n) {
        if(row >= m || col >= n) return 0;
        
        if(row == m - 1 && col == n - 1) return 1;
        
        return traverseGrid(row + 1, col, m, n) + traverseGrid(row, col + 1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
        return traverseGrid(0, 0, m, n);
    }
};
*/
