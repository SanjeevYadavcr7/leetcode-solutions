/*
    Time: O(N^2.LogN)
    There are a total of V = N^2 cells (vertices) in the graph. In the worst-case scenario, every cell is pushed and popped from the priority queue once. Each priority queue operation on an N^2 container takes O(log(N^2)) = O(2.log N) = O(log N) time.

    Space: O(N^2)
    Memory is consumed by the N * N explicit visited matrix tracking bitset arrays alongside the internal runtime storage footprint of the min-heap priority queue.
*/

class Solution {
private:
    bool isValidCell(int x, int y, int N) {
        return (x >= 0 && x < N && y >= 0 && y < N);
    }
public:
    using timeAndCoordinatePair = pair<int, pair<int, int>>;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();

        priority_queue<timeAndCoordinatePair, vector<timeAndCoordinatePair>, greater<timeAndCoordinatePair>> q;
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        q.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        while(!q.empty()) {
            auto [timeTaken, pos] = q.top();
            auto [r, c] = pos;
            q.pop();

            if(r == N - 1 && c == N - 1) return timeTaken;

            for(auto [x, y] : directions) {
                int new_r = r + x;
                int new_c = c + y;

                if(isValidCell(new_r, new_c, N) && !visited[new_r][new_c]) {
                    visited[new_r][new_c] = true;

                    int nextTime = max(timeTaken, grid[new_r][new_c]);
                    q.push({nextTime, {new_r, new_c}});
                }
            }
        }

        return -1;
    }
};
