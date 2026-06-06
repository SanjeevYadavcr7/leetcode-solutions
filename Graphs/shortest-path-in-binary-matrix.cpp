// Time: O(M.N)
// Space: O(M.N)

class Solution {
private: 
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    bool isClearPathCell(int x, int y, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0);
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] || grid[m-1][n-1]) return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto [x, y] : directions) {
                int new_x = x + i;
                int new_y = y + j;
                if(isClearPathCell(new_x, new_y, grid)) {
                    grid[new_x][new_y] = grid[i][j] + 1;
                    q.push({new_x, new_y});
                }
            }
        }
        
        return (grid[m-1][n-1] == 0 ? -1 : grid[m-1][n-1]);
    }
};
