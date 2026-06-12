// Time: O((V+E).LogV)
// Space: O(V + E) + O(V) + O(V) = O(V + E)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // 1. Construct graph(adjacency list)
        vector<vector<pair<int, int>>> graph(V);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            graph[u].push_back({v, weight});
        }
        
        // 2. Create a distance vector
        vector<int> dist(V, 1e9);
        
        // 3. Setup BFS Queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        dist[0] = 0;
        
        while(!q.empty()) {
            auto [currentDist, node] = q.top();
            q.pop();
            
            // Optimization: If we found a shorter path to this node already, 
            // skip processing its stale, longer distance version.
            if(currentDist > dist[node]) continue;
            
            for(auto& [nbrNode, nbrWeight] : graph[node]) {
                if(dist[node] + nbrWeight < dist[nbrNode]) {
                    dist[nbrNode] = dist[node] + nbrWeight;
                    q.push({dist[nbrNode], nbrNode});
                }
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
