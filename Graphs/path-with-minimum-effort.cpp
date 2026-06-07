
class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isValidCell(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        // use min-heap to pick effort in ascending order {currentEffort, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        minHeap.push({0, 0, 0});
        effort[0][0] = 0;

        while(!minHeap.empty()) {
            auto effortAndCellIdx = minHeap.top();
            minHeap.pop();

            int currEffort = effortAndCellIdx[0];
            int x = effortAndCellIdx[1];
            int y = effortAndCellIdx[2];

            if(x == m - 1 && y == n - 1) return currEffort;

            if(currEffort > effort[x][y]) continue;

            for(auto[i, j] : directions) {
                int new_x = x + i;
                int new_y = y + j;
                if(isValidCell(new_x, new_y, m, n)) {
                    int maxEffortTillNow = max(currEffort, abs(heights[new_x][new_y] - heights[x][y]));
                    if(maxEffortTillNow < effort[new_x][new_y]) {
                        effort[new_x][new_y] = maxEffortTillNow;
                        minHeap.push({maxEffortTillNow, new_x, new_y});
                    }
                }
            }
        }
        return 0;
    }
};
