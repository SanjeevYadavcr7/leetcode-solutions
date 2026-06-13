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

class KruskalMST {
public:
    int spanningTree(int V, vector<vector<int>>& edgesList) {
        // Format of edgesList elements: {weight, u, v}
        // Step 1: Sort all edges globally from cheapest to most expensive
        sort(edgesList.begin(), edgesList.end());

        DisjointSet obj(V);

        int mstWeightSum = 0;
        int edgesSelectedCount = 0;

        for(auto& edge : edgesList) {
            int weight = edge[0];
            int node1 = edge[1];
            int node2 = edge[2];
            
            if(obj.unionByRank(node1, node2)) {
                mstWeightSum += weight;
                edgesSelectedCount++;

                if(edgesSelectedCount == V - 1) break;
            }
        }

        return mstWeightSum;
    }
};