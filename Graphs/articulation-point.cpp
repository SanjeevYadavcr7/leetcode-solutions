/*
  APs are nodes, not edges. Use a set to prevent duplicates. 
  Condition: low[nbr] >= disc[node]. 
  Root Node Exception: The root is only an AP if it has > 1 independent DFS children (use an internal counter inside the DFS), NOT just multiple edges!
*/

class Solution {
  private:
    int globalTimer = 1; // Start timer at 1 to avoid 0-index collisions
    
    void DFS(
        int node, 
        int parent, 
        vector<int>& disc,
        vector<int>& low,
        unordered_set<int>& points,
        vector<vector<int>>& graph) 
    {
        disc[node] = low[node] = globalTimer++;
        int children = 0; // Track independent DFS branches for the root
        
        for(int& nbr : graph[node]) {
            if(nbr == parent) continue;
            
            if(disc[nbr] == 0) { // Unvisited node (0 because arrays initialized to 0)
                children++;
                DFS(nbr, node, disc, low, points, graph);
                
                low[node] = min(low[node], low[nbr]);
                
                // Articulation Point Condition (for NON-ROOT nodes)
                if(low[nbr] >= disc[node] && parent != -1) {
                    points.insert(node);    
                }
            } else {
                // Back-edge found
                low[node] = min(low[node], disc[nbr]);
            }
        }
        
        // Articulation Point Condition (for ROOT node)
        if(parent == -1 && children > 1) {
            points.insert(node);
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for(auto& edge : edges) {
            int u = edge;
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // Initializing to 0 is fine ONLY IF globalTimer starts at 1
        vector<int> disc(V, 0);
        vector<int> low(V, 0);
        unordered_set<int> points;
        
        for(int i = 0; i < V; i++) {
            if(disc[i] == 0) {
                DFS(i, -1, disc, low, points, graph);
            }
        }
        
        if(points.size() == 0) return {-1};
        
        vector<int> result(points.begin(), points.end());
        sort(result.begin(), result.end()); // GFG requires sorted output
        
        return result;
    }
};
