
class Solution {
private:
    bool isGraphBipartite(int start_node, vector<int>& nodeColor, vector<vector<int>>& graph) {
        queue<int> q;

        q.push(start_node);
        nodeColor[start_node] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int& nbr : graph[node]) {
                if(nodeColor[nbr] == -1) {
                    int color = 1 - nodeColor[node];
                    nodeColor[nbr] = color;
                    q.push(nbr);
                } 
                else {
                    if(nodeColor[nbr] == nodeColor[node]) return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> nodeColor(n, -1);

        for(int i = 0; i < n; i++) {
            if(nodeColor[i] == -1) {
                if(!isGraphBipartite(i, nodeColor, graph)) return false;
            }
        }
        return true;
    }
};
