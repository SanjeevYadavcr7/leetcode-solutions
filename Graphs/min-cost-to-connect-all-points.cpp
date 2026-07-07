/*
Approach: Optimzed Prim's Algorithm(without using head)
Time: O(N^2)
*/


/*
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
