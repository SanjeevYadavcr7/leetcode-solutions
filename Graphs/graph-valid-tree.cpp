
class Solution {
private:
    void dfs(int node, unordered_set<int>& visited, vector<vector<int>>& graph) {
        if(visited.find(node) != visited.end()) return;

        visited.insert(node);

        for(int& nbr : graph[node]) {
            dfs(nbr, visited, graph);
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> graph(n);

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_set<int> visited;

        dfs(0, visited, graph);

        return visited.size() == n;
    }
};
