#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public: 
    /*
        Traversal Technique: BFS
        Complexity: Time = O(V+E)  Space = O(V+E)
    */
    int countComponents(int n, vector<vector<int>>& edges) {
        int comp = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);

        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                queue<int> vertices;

                vertices.push(i);
                visited[i] = true;
                comp++;

                while(!vertices.empty()) {
                    int node = vertices.front();
                    vertices.pop();
                    
                    for(auto& nbr : graph[node]) {
                        if(!visited[nbr]) {
                            vertices.push(nbr);
                            visited[nbr] = true;
                        }
                    }
                } 
            }
        }
        return comp;
    }
};

int main() {
    // Number of vertices
    int V = 5;

    // List of undirected edges
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};

    Solution sol;

    cout << "Number of Connected Components: " 
         << sol.countComponents(V, edges) << endl;

    return 0;
}