/*
Time: O(M.N)
Space: O(M.N)
*/

class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isVaildCell(int r, int c, int ROWS, int COLS) {
        return (r >= 0 && c >= 0 && r < ROWS && c < COLS);
    }

    void markIsland(int r, int c, int ROWS, int COLS, vector<vector<char>>& grid) {
        // Base case: out of bounds or water/visited
        if(!isVaildCell(r, c, ROWS, COLS) || grid[r][c] == '0') {
            return;
        }

        // Mark as visited inside the function instance
        grid[r][c] = '0';

        for(auto[x, y] : directions) {
            markIsland(x + r, y + c, ROWS, COLS, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int islands = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    markIsland(i, j, m, n, grid);
                }
            }
        }

        return islands;
    }
};
