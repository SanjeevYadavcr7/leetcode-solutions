#include<iostream>
#include<vector>
using namespace std;

/*
    Time: O(V+E)  Space: O(V) // reuresion stack space
*/

class Solution {
private:
    void traversal(int node, vector<bool>& visited, vector<vector<int>>& graph, vector<int>& result) {
        result.push_back(node);
        visited[node] = true;

        for(auto& nbr : graph[node]) {
            if(!visited[nbr]) {
                traversal(nbr, visited, graph, result);
            }
        }
    } 

public: 
    vector<int> traversalDFS(int n, vector<vector<int>>& edges) {
        vector<int> result;
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);

        // creating adjacency list from input edges
        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i])
            traversal(i, visited, graph, result);
        }
        return result;
    }
};

int main() {
    int V = 5;

    // List of undirected edges
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,3}, {1,4}, {3,4}};

    Solution sol;
    vector<int> result = sol.traversalDFS(V, edges);
    for(int& i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}