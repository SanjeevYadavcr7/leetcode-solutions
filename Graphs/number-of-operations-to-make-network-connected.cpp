class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int V) {
        parent.resize(V);
        rank.resize(V, 0);

        // Initially - all nodes are itself ultimate parent
        for(int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }

    int getTotalGroups(int n) {
        int groups = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i) {
                groups++;
            }
        }

        return groups;
    }

    // Find operation with Path Compression optimization
    int findUltimateParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        
        // Path Compression: directly connect node to its ultimate root
        return parent[node] = findUltimateParent(parent[node]);
    }

    // Union operation by Rank
    bool unionByRank(int u, int v) {
        int root_u = findUltimateParent(u);
        int root_v = findUltimateParent(v);
        
        if(root_u == root_v) {
            return false;
        }

        if(rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if(rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_u] = root_v;
            rank[root_v]++;
        }

        return true; // Successfully merged two disjoint components
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;

        DisjointSet obj(n);

        int edgesSelected = 0;
        for(auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if(obj.unionByRank(u, v)) {
                edgesSelected++;
            }
        }

        int groups = n - edgesSelected - 1;
        return groups;
    }
};
