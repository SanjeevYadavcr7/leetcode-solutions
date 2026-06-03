// Time : O(V + E)
// Space: O(V + E)  -> for building new graph

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numNodes = graph.size(); 
        vector<int> inDegree(numNodes, 0);
        vector<vector<int>> reversedGraph(numNodes);

        // reverse graph and maintain inDegree array
        for(int node = 0; node < numNodes; node++) {
            for(int& nbr : graph[node]) {
                reversedGraph[nbr].push_back(node);
                inDegree[node]++;
            }
        }

        vector<int> safeStates;
        queue<int> q;

        for(int i = 0; i < numNodes; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                safeStates.push_back(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int& nbr : reversedGraph[node]) {
                inDegree[nbr]--;
                if(inDegree[nbr] == 0) {
                    q.push(nbr);
                    safeStates.push_back(nbr);
                }
            }
        }

        sort(safeStates.begin(), safeStates.end());
        return safeStates;
    }
};
