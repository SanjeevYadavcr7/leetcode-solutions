
class Solution {
public:
    // Time: O(M.N)  
    // Space: O(1) Using input array to mark visited nodes

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int, int>> nodes;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0) {
                    nodes.push({i, j}); // Push nodes to queue for Multi-source BFS
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        while(!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop();

            for(auto [u, v] : directions) {
                int new_x = x + u;
                int new_y = y + v;
                if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && mat[new_x][new_y] == -1) {
                    mat[new_x][new_y] = mat[x][y] + 1;
                    nodes.push({new_x, new_y});
                }
            }
        }

        return mat;
    }
};
