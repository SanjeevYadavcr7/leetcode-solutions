/*
  Approach: Multi-Source BFS
  Time  : O(M.N)  -->  Every cell is visited once
  Space : O(M.N)  -->  Space taken by queue in worst case when all the cells(M.N) have gates
*/  

class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isValidCell(int x, int y, int ROWS, int COLS) {
        return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int ROWS = rooms.size();
        int COLS = rooms[0].size();
        int INF = 2147483647;

        queue<pair<int, int>> q;

        // Check which cell has gate and store it
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(rooms[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            steps++;

            while(size--) {
                auto [x, y] = q.front();
                q.pop();

                if(rooms[x][y] == -1) continue;

                for(auto [r, c] : directions) {
                    int new_x = x + r;
                    int new_y = y + c;

                    // If room is not valid, gate or wall then ignore
                    // If room is not empty then it means the room is already visited and already has the shortest path to nearest gate
                    if(!isValidCell(new_x, new_y, ROWS, COLS) || rooms[new_x][new_y] != INF) continue;

                    // Add step from this room to next neighbour room
                    rooms[new_x][new_y] = rooms[x][y] + 1;

                    // Add in queue to find next neighbours
                    q.push({new_x, new_y});
                }
            }
        }
    }
};
