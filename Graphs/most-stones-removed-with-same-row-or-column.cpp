class DisjointSet {
private:
    vector<int> parent, rank;
    int components = 0;
public:
    DisjointSet(int N) {
        parent.resize(N);
        rank.resize(N, 0);

        for(int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }

    int getComponents() {
        return components;
    }

    int getUltimateParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = getUltimateParent(parent[node]);
    }

    void connectNodes(int u, int v) {
        int root_u = getUltimateParent(u);
        int root_v = getUltimateParent(v);

        if(root_u == root_v) return;

        if(rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v; 
        } else if(rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else {
            rank[root_v]++;
            parent[root_u] = root_v;
        }
        components--;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;

        for(auto& edge : stones) {
            maxRow = max(maxRow, edge[0]);
            maxCol = max(maxCol, edge[1]);
        }

        int N = maxRow + maxCol + 2;
        DisjointSet obj(N);
        
        unordered_set<int> activeNodes;
        
        for(auto& edge : stones) {
            int x = edge[0];
            int y = edge[1] + maxRow + 1;

            obj.connectNodes(x, y);
            activeNodes.insert(x);
            activeNodes.insert(y);
        }

        unordered_set<int> groups;
        for(int node : activeNodes) {
            groups.insert(obj.getUltimateParent(node));
        }

        int max_removed_stones = stones.size() - groups.size();
        return max_removed_stones;
    }
};
