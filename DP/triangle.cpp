/*
Approach: Dymanic-Programming
Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int maxCols = triangle[rows - 1].size();

        vector<int> minPathSum(maxCols, 0);

        minPathSum[0] = triangle[0][0];

        for(int r = 1; r < rows; r++) {
            vector<int> temp = minPathSum;
            for(int c = 0; c <= r; c++) {
                if(c == 0) {
                    temp[0] += triangle[r][0]; 
                } else if(c == r) {
                    temp[c] = minPathSum[c - 1] + triangle[r][c];
                } else {
                    temp[c] = min(minPathSum[c - 1], minPathSum[c]) + triangle[r][c];
                }
            }
            minPathSum = temp;
        }

        int minSum = *min_element(minPathSum.begin(), minPathSum.end());
        return minSum;
    }
};

/*
Approach: Recursion
Time Complexity: O(2^N)
Space Complexity: O(N)

class Solution {
private:
    int getMinPath(int row, int col, vector<vector<int>>& grid) {
        if(row == grid.size() - 1) {
            return grid[row][col];
        }

        return grid[row][col] + min(
            getMinPath(row + 1, col, grid), 
            getMinPath(row + 1, col + 1, grid));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return getMinPath(0, 0, triangle);
    }
};

*/
