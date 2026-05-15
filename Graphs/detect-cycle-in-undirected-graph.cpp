#include<iostream>
#include<vector>
using namespace std;

class Solution {
  private:
    bool cycleExistsInGraph(int node, int parent, vector<bool>& visited, vector<vector<int>>& graph) {
        if(visited[node]) return true;
        
        visited[node] = true;

        for(auto nbr : graph[node]) {
            if(nbr != parent) {
                if(cycleExistsInGraph(nbr, node, visited, graph)) return true;   
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        vector<bool> visited(V, false);
        
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for(int node = 0; node < V; node++) {
            if(!visited[node]) {
                if(cycleExistsInGraph(node, -1, visited, graph)) {
                    return true;
                }       
            }
        }
        return false;
    }
};

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> edges(e, vector<int>(2, 0));
    for(int i = 0; i < e; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> edges[i][j];
        }
    }

    Solution obj;
    string result = obj.isCycle(n, edges) ? "true" : "false";
    cout << result << endl;
}