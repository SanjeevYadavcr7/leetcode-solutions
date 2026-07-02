/*
    Approach: Kruskal's Algorithm
      
*/
class Dsu {
private:
    vector<int> rank, parent;
public:
    Dsu(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    bool unite(int a, int b) {
        int parA = findUltimateParent(a);
        int parB = findUltimateParent(b);

        if(parA == parB) return false;

        if(rank[parA] < rank[parB]) {
            parent[parA] = parB;
        } else if(rank[parA] > rank[parB]) {
            parent[parB] = parA;
        } else {
            parent[parB] = parA;
            rank[parA]++;
        }
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n - 1 != edges.size()) return false;

        Dsu obj(n);

        for(auto& edge : edges) {
            if(!obj.unite(edge[0], edge[1])) {
                return false;
            }
        }
        return true;
    }
};


/*-------------------------------------------------------------------------------*/

/*
    Approach: DFS
    Time: O(N)
    Actual time complexity is O(N + E), where N = no. of nodes and E = no. of edges
    But in this question as E ~ V - 1 because it is a graph hence constant part in complexity 
    becomes negligible and overall time complexity is O(N + N) = O(2.N) = O(N)

    This is fine when N is small, but if N is large then it causes problem.
    Why?
    Because there are two phases in this approach:
    1. Build graph which takes O(N + E) ~ O(N)
    2. Actual DFS to find cycle, which again takes O(N + E) ~ O(N)

    Now, the overall time complexity will be still O(N) but the constant which is getting ignored
    is HUGGGGGGGEEEEEE. This is why this approach is not optimal solution and we use DSU as optimal
    solution for this question.
*/

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
