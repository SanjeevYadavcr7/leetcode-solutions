class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(V);
        
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        
        int mstCost = 0;
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        q.push({0, 0});
        
        while(!q.empty()) {
            auto[weight, node] = q.top();
            q.pop();
            
            if(visited[node]) continue;
            
            visited[node] = true;
            mstCost += weight;
            
            for(auto[nbr, nbrWeight] : graph[node]) {
                if(!visited[nbr]) {
                    q.push({nbrWeight, nbr});    
                }
            }
        }
        
        return mstCost;
    }
};
