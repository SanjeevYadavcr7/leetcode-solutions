/*
Time: O(M.N)
Space: O(M.N)
*/

class Solution {
private:
    int m, n;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isInsideGrid(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    void markNeighbourLands(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';

        for(auto& [x, y] : directions) {
            int new_x = x + i;
            int new_y = y + j;
            if(isInsideGrid(new_x, new_y) && grid[new_x][new_y] == '1') {
                markNeighbourLands(new_x, new_y, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int islandCount = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    markNeighbourLands(i, j, grid);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};
