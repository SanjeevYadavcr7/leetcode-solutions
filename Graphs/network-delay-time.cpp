/*
  Time: O(E.LogV)
  O(V.LogV) --> to pop vertices from PQ
  O(E.LogV) --> to add neighbours in PQ
  
  Space: O(V + E)  -->  max space is taken by graph 

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // Construct Graph(adjacency list)
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto& it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            graph[u].push_back({v, w});
        }

        // Best-seen-so-far tracker array
        vector<int> time(n + 1, INT_MAX);
        time[k] = 0;

        // Using min-heap to always pick least cost path  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});

        while(!q.empty()) {
            auto [currTime, node] = q.top();
            q.pop();

            // Current path is costly than already discovered path
            if(currTime > time[node]) continue;

            // Exploring optimal paths
            for(auto& [nbr, timeToNbr] : graph[node]) {

                // Time taken to reach to neighbour node
                int timeTaken = currTime + timeToNbr;

                if(timeTaken < time[nbr]) {
                    time[nbr] = timeTaken;
                    q.push({timeTaken, nbr});
                }
            }
        }

        int timeTaken = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(time[i] == INT_MAX) {
                return -1;
            }
            timeTaken = max(timeTaken, time[i]);
        }
        return timeTaken;
    }
};
