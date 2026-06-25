/*
  Time: O(M.N)  -->  because each cell is visited at max once 
  Space: O(1)   -->  no extra space except recursion stack space
*/

class Solution {
private:
    bool isValidCell(int r, int c, int ROWS, int COLS) {
        return (r >= 0 && c >= 0 && r < ROWS && c < COLS);
    }

    int getIslandArea(int r, int c, int ROWS, int COLS, vector<vector<int>>& grid) {
        if(!isValidCell(r, c, ROWS, COLS) || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;

        int area = 1 + getIslandArea(r + 1, c, ROWS, COLS, grid) + getIslandArea(r - 1, c, ROWS, COLS, grid) + getIslandArea(r, c + 1, ROWS, COLS, grid) + getIslandArea(r, c - 1, ROWS, COLS, grid);
        
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int maxArea = 0;

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                // if current cell is part of land, calculate area of this island
                if(grid[r][c] == 1) {
                    int area = getIslandArea(r, c, ROWS, COLS, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
