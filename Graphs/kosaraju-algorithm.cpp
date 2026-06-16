/*
  Kosaraju Algorithm is used to find Strongly Connected Components.
  SCC -> maximal subgraph where every vertex is reachable from every other vertex within that same subgraph.

  Time Complexity  : O(V + E)
  Space Complexity : O(V + E) 
*/

class Solution {
private:
    // Combined DFS worker to keep the codebase DRY (Don't Repeat Yourself)
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& order, bool pushToStack) {
        visited[node] = true;
        
        for(int nbr : adj[node]) {
            if(!visited[nbr]) {
                dfs(nbr, adj, visited, order, pushToStack);
            }
        }
        
        if (pushToStack) {
            order.push(node);
        }
    }

    // Explicitly pass V to guarantee fixed-size boundaries
    stack<int> getComponentsOrder(int V, const vector<vector<int>>& graph) {
        stack<int> finishOrder;
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, graph, visited, finishOrder, true);
            }
        }
        return finishOrder;
    }
    
    vector<vector<int>> reverseGraphEdges(int V, const vector<vector<int>>& graph) {
        vector<vector<int>> reversedGraph(V);
        
        for(int node = 0; node < V; node++) {
            for(int nbr : graph[node]) {
                reversedGraph[nbr].push_back(node);
            }
        }
        return reversedGraph;
    }

public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        // Step 1: Construct Graph safely using fixed size V
        vector<vector<int>> graph(V);
        for(const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        // Step 2: Get Pseudo-Topological Order
        stack<int> pseudoTopoOrder = getComponentsOrder(V, graph);
        
        // Step 3: Reverse Graph Edges into a separate container (No deep copies)
        vector<vector<int>> reversedGraph = reverseGraphEdges(V, graph);
        
        // Step 4: Process components on reversed graph
        int sccCount = 0;
        vector<bool> visited(V, false);
        stack<int> dummyStack; // Unused container for the second pass
        
        while(!pseudoTopoOrder.empty()) {
            int node = pseudoTopoOrder.top();
            pseudoTopoOrder.pop();
            
            if(!visited[node]) {
                sccCount++;
                // Reusing the same DFS logic without pushing to a stack
                dfs(node, reversedGraph, visited, dummyStack, false);
            }
        }
        
        return sccCount;
    }
};
