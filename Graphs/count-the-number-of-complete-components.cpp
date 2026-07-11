/*
  Algorithm: Kruskal's Union-Find
  Time: O(V + E)  ->  O(V) : Loop to check complete components + O(E) : classic union find
  Space: O(V)
*/

class UnionFind {
private:
    vector<int> parent, size, edges;

public:
    UnionFind(int n) {
        size.resize(n, 1);
        edges.resize(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int getParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = getParent(parent[node]);
    }

    int getComponentSize(int node) {
        return size[node];
    }

    int getComponentEdges(int node) {
        return edges[node];
    }
    
    void unite(int nodeA, int nodeB) {
        int parentA = getParent(nodeA);
        int parentB = getParent(nodeB);
        
        // Both nodes have same parent means adding them would create cycle
        // No new node added but an edge is added
        if(parentA == parentB) {
            edges[parentA]++;
            return;
        }

        // Doing union by size -> to maintain nodes count in cycle
        // nodes count is used to generate expected edges in the cycle using
        // getTotalEdges()
        if(size[parentA] > size[parentB]) {
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
            edges[parentA] += edges[parentB] + 1;
        } else {
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
            edges[parentB] += edges[parentA] + 1;
        }
    }
};

class Solution {
private:
    int getTotalEdges(int nodesCnt) {
        return nodesCnt * (nodesCnt - 1) / 2;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int completeComps = 0;
        UnionFind obj(n);
        
        for(auto& edge : edges) {
            obj.unite(edge[0], edge[1]);
        }

        for(int node = 0; node < n; node++) {

            // Starting node of component is parent of itself
            // hence we can use this to check if current component
            // is complete component.
            if(obj.getParent(node) == node) {
                int nodesCount = obj.getComponentSize(node);
                int expectedEdges = getTotalEdges(nodesCount);
                if(obj.getComponentEdges(node) == expectedEdges) {
                    completeComps++;
                }
            }
        }

        return completeComps;
    }
};
