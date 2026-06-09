/*
    Time: O(E.LogV)
    Space: O(V + E)

*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        
        // 1. Construct the adjacency list graph: {neighbor, weight}
        vector<vector<pair<int, int>>> graph(n);
        for(auto& road : roads) {
            int src = road[0];
            int dst = road[1];
            int time = road[2];
            graph[src].push_back({dst, time});
            graph[dst].push_back({src, time});
        }

        // 2. State Arrays
        vector<long long> time(n, LLONG_MAX);
        vector<long long> ways(n, 1);

        // 3. Min-Heap for Dijkstra: stores {accumulated_time, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

        q.push({0, 0});
        
        while(!q.empty()) {
            auto [currTime, node] = q.top();
            q.pop();

            // Optimization: Skip constly path
            if(currTime > time[node]) continue;

            for(auto [nbr, timeToNbr] : graph[node]) {
                long long time_taken = currTime + timeToNbr;
                
                // Case A: Found a strictly shorter path
                if(time_taken < time[nbr]) { 
                    time[nbr] = time_taken;
                    ways[nbr] = ways[node]; // Inherit ways
                    q.push({time_taken, nbr});
                }
                // Case B: Found an alternative path of equal minimum distance 
                else if(time_taken == time[nbr]) {
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD; // Accumulate ways
                } else continue;
            }
        }

        return ways[n-1];
    }
};
