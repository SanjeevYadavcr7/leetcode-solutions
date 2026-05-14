class Solution {
  public:
    vector<vector<int>> getComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); // adjacency list[]
        
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        queue<int> nodes;
        vector<int> visited(n, 0);
        vector<vector<int>> components;
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                vector<int> subComp;
                
                nodes.push(i);
                visited[i] = 1;
                
                while(!nodes.empty()) {
                    int node = nodes.front();
                    nodes.pop();
                    
                    subComp.push_back(node);
                    
                    for(auto& nbr : graph[node]) {
                        if(!visited[nbr]) {
                            nodes.push(nbr);
                            visited[nbr] = 1;
                        } 
                    }
                }
                if(subComp.size()) {
                    components.push_back(subComp);
                }
            }
        }
        return components;
    }
};
