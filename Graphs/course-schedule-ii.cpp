// Time: O(V+E) 
// Space: O(V+E) -> adjaceny list + queue
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto& edge : prerequisites) {
            int u = edge[0], v = edge[1];
            graph[v].push_back(u);
            inDegree[u]++;
        }

        queue<int> q;
        vector<int> order;

        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);
            
            for(int& nbr : graph[node]) {
                inDegree[nbr]--;
                if(inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        if(order.size() == numCourses) return order;
        return {};
    }
};
