
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);

        for(auto& edge : prerequisites) {
            int u = edge[0], v = edge[1];
            graph[v].push_back(u);
            inDegree[u]++;
        }

        queue<int> q;
        int finishedCourses = 0;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) { 
                cout << i << " ";
                q.push(i); // push courses with no deps
                finishedCourses++;
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int& nbr : graph[node]) {
                inDegree[nbr]--;
                if(inDegree[nbr] == 0) {
                    finishedCourses++; // mark this course as finished
                    q.push(nbr);
                }
            }
        }

        return finishedCourses == numCourses;
    }
};
