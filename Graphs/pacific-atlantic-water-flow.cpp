/*

Time : O(M.N)  -->  Standard DFS(each cell gets visited constant number of times)
Space: O(M.N)  -->  Visited array

This problem can be solved using BFS(Multi-Source BFS) or DFS.

APPROACH:
1. Instead of thinking to go to border(ocean) from every cell, invert the problem.
2. Go from border(which are already touching sea) to the possible cells from where water can flow in.
3. Mark the cells where both pacific and atlantic water can reach.
4. Check and return the cells where both waters can reach.
*/

class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool isValidCell(int r, int c, int ROWS, int COLS) {
        return (r >= 0 && r < ROWS && c >= 0 && c < COLS);
    }

    void dfs(int r, int c, int ROWS, int COLS, int prevHeight, vector<vector<bool>>& visited, vector<vector<int>>& heights) {
        if(!isValidCell(r, c, ROWS, COLS) || visited[r][c] || heights[r][c] < prevHeight) return;

        visited[r][c] = true;

        for(auto[x, y] : directions) {
            dfs(r + x, c + y, ROWS, COLS, heights[r][c], visited, heights);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        if(ROWS == 0 || COLS == 0) return {};

        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        // Flow water from top(pacific) and bottom(atlantic)
        for(int c = 0; c < COLS; c++) {
            dfs(0, c, ROWS, COLS, heights[0][c], pacific, heights);
            dfs(ROWS - 1, c, ROWS, COLS, heights[ROWS - 1][c], atlantic, heights);
        }

        for(int r = 0; r < ROWS; r++) {
            dfs(r, 0, ROWS, COLS, heights[r][0], pacific, heights);
            dfs(r, COLS - 1, ROWS, COLS, heights[r][COLS - 1], atlantic, heights);
        }

        vector<vector<int>> result;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
