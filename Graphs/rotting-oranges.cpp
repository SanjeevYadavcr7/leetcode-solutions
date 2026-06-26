/*

Time : O(M.N) | Space : O(M.N)

Appraoch: MULTI-SOURCE BFS

The idea is to store all rotten oranges in the queue and keep rottening neighbour oranges until NO fresh oranges are present.

IMPORTANT: 
It is possible that there could be an orange which will never get rotten, 
to handle this scenario, in starting itself we would need to count fresh oranges and in the end check if all fresh oranges got rotten.

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> rotten;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    rotten.push({i, j}); // storing rotten oranges
                }
                if(grid[i][j] == 1) {
                    fresh++; // counting fresh oranges
                }
            }
        }

        if(fresh == 0) return 0; // No fresh oranges already
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!rotten.empty() && fresh > 0) {
            int size = rotten.size();
            minutes++;

            while(size--) {
                auto [x, y] = rotten.front();
                rotten.pop();

                for(auto& it : directions) {
                    int new_x = x + it.first;
                    int new_y = y + it.second;

                    // Check in all directions
                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 1) {
                            rotten.push({new_x, new_y});
                            grid[new_x][new_y] = 2;
                            fresh--;
                    }
                }
            }
        }
        return (fresh == 0) ? minutes : -1;
    }
};
