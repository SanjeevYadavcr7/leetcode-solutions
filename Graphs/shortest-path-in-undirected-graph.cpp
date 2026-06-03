// Time: O(V + E)
// Space: O(V + E) -> for creating graph

#include<iostream>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> graph(V);
        
        // Build the Adjacency List
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // Initialize the distance array with a placeholder for infinity
        vector<int> dist(V, 1e9);
        
        // Setup BFS Queue
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int& nbr : graph[node]) {
                if(dist[node] + 1 < dist[nbr]) {
                    dist[nbr] = dist[node]+1;
                    q.push(nbr);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
