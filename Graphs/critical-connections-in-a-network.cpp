class Solution {
private:
    int timer = 1;

    void findBridgesDFS(int node, int parent, const vector<vector<int>>& adj,
                        vector<int>& discoveryTime, vector<int>& lowValue,
                        vector<vector<int>>& criticalEdges) {
        
        // 1. Initialize discovery time and low value tracking arrays on node entry
        discoveryTime[node] = lowValue[node] = timer++;
        
        for (int neighbor : adj[node]) {
            // Case 1: The neighbor is the immediate parent vertex we just came from
            if (neighbor == parent) continue;
            
            if (discoveryTime[neighbor] == 0) { // Neighbor is unvisited
                
                // Recurse down the DFS tree path
                findBridgesDFS(neighbor, node, adj, discoveryTime, lowValue, criticalEdges);
                
                // Post-order step: Update current node's low value based on the child's path
                lowValue[node] = min(lowValue[node], lowValue[neighbor]);
                
                // THE GOLDEN BRIDGE CONDITION:
                // If the child cannot reach any node at or above 'node', 
                // then the edge connecting them is a vital structural bridge.
                if (lowValue[neighbor] > discoveryTime[node]) {
                    criticalEdges.push_back({node, neighbor});
                }
                
            } else {
                // Case 3: Neighbor is already visited (Back-edge cycle shortcut discovered)
                // Minimize current lowValue with the ancestor's discovery time boundary
                lowValue[node] = min(lowValue[node], discoveryTime[neighbor]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // 1. Construct the unweighted, undirected adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // 2. Initialize tracking vectors (0 indicates a vertex is unvisited)
        vector<int> discoveryTime(n, 0);
        vector<int> lowValue(n, 0);
        vector<vector<int>> criticalEdges;
        
        // 3. Kick off the primary tracking pass from root node 0
        findBridgesDFS(0, -1, adj, discoveryTime, lowValue, criticalEdges);
        
        return criticalEdges;
    }
};
