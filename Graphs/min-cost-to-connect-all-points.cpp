/*
Approach: Optimzed Prim's Algorithm(without using head)
Time: O(N^2)
*/
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();

        vector<int> minDist(N, INT_MAX);
        vector<int> inMST(N, false);

        minDist[0] = 0;
        int totalMinCost = 0;

        for(int j = 0; j < N; ++j) {
            int currNode = -1;
            int currMinDist = INT_MAX;

            // Get neighbor node which has minimum distance from current node
            for(int i = 0; i < N; i++) {
                if(!inMST[i] && minDist[i] < currMinDist) {
                    currMinDist = minDist[i];
                    currNode = i;
                }
            }

            inMST[currNode] = true;
            totalMinCost += currMinDist;

            for(int i = 0; i < N; ++i) {
                if(!inMST[i]) {
                    int dis = abs(points[currNode][0] - points[i][0]) + abs(points[currNode][1] - points[i][1]);
                    if(dis < minDist[i]) {
                        minDist[i] = dis;
                    }
                }
            }
        }

        return totalMinCost;
    }
};



/*-----------------------------------------------------------------------------
  Approach: Use Prim's Algorithm
  Time: O(N^2.LogN)
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> graph(n);

        // Construct bi-directional weighted graph
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].push_back({j, dis});
                graph[j].push_back({i, dis});
            }
        }

        int minCost = 0;
        vector<bool> visited(n, false);
        
        // Using min-heap stores {cost, node} to find minimum cost edge
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        minHeap.push({0, 0});

        while(!minHeap.empty()) {
            auto [dis, node] = minHeap.top();
            minHeap.pop();

            if(visited[node]) continue;

            visited[node] = true;
            minCost += dis;

            for(auto[nbr, cost] : graph[node]) {
                if(!visited[nbr]) {
                    minHeap.push({cost, nbr});
                }
            }
        }

        return minCost;
    }
};
