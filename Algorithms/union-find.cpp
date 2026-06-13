/*
    Union-Find is used to verify if two nodes are connected to each other by 
    verifying if they are part of same group(same ultimate parent).

    Union-Find uses two algorithms to do this: 
    1. Find Ultimate Parent
    2. Union nodes
        - By Rank
        - By Size
*/
#include <vector>
#include <numeric>

using namespace std;

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