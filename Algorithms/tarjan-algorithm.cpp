/*
  Time Complexity : O(V + E)
  Space Complexity: O(V)
*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TarjanSCC {
private:
    int globalTimer;
    
    void findComponentsDFS(int node, 
                           const vector<vector<int>>& adj,
                           vector<int>& discoveryTime, 
                           vector<int>& lowValue, 
                           vector<bool>& isOnStack, 
                           stack<int>& trackingStack,
                           vector<vector<int>>& totalSCCs) {
        
        // 1. Initialize node timestamps on entry
        discoveryTime[node] = lowValue[node] = ++globalTimer;
        trackingStack.push(node);
        isOnStack[node] = true;
        
        // 2. Iterate through outgoing edges
        for (int neighbor : adj[node]) {
            if (discoveryTime[neighbor] == -1) { // Neighbor is unvisited
                
                findComponentsDFS(neighbor, adj, discoveryTime, lowValue, 
                                  isOnStack, trackingStack, totalSCCs);
                
                // Post-order tracking: Minimize current lowValue with child's lowValue
                lowValue[node] = min(lowValue[node], lowValue[neighbor]);
                
            } else if (isOnStack[neighbor]) { // Back-edge found to an active ancestor
                
                // Core Tarjan Rule: Minimize with the neighbor's DISCOVERY time
                lowValue[node] = min(lowValue[node], discoveryTime[neighbor]);
            }
        }
        
        // 3. Head of an SCC Component block detected
        if (lowValue[node] == discoveryTime[node]) {
            vector<int> currentComponent;
            
            while (true) {
                int topNode = trackingStack.top();
                trackingStack.pop();
                isOnStack[topNode] = false;
                
                currentComponent.push_back(topNode);
                if (topNode == node) break; // We popped the head of the component loop
            }
            
            // Standard formatting step: Sort individual component items
            sort(currentComponent.begin(), currentComponent.end());
            totalSCCs.push_back(currentComponent);
        }
    }

public:
    vector<vector<int>> getStronglyConnectedComponents(int V, vector<vector<int>>& adj) {
        globalTimer = 0;
        
        vector<vector<int>> totalSCCs;
        stack<int> trackingStack;
        
        // Using -1 to track "unvisited" removes the need for a separate visited vector
        vector<int> discoveryTime(V, -1);
        vector<int> lowValue(V, -1);
        vector<bool> isOnStack(V, false);
        
        // Process each disconnected subgraph cluster
        for (int i = 0; i < V; i++) {
            if (discoveryTime[i] == -1) {
                findComponentsDFS(i, adj, discoveryTime, lowValue, 
                                  isOnStack, trackingStack, totalSCCs);
            }
        }
        
        // Sort final components array to provide predictable, uniform output
        sort(totalSCCs.begin(), totalSCCs.end());
        return totalSCCs;
    }
};
