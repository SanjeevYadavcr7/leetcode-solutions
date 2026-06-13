/*
  Algorithm: Floyd-Warshall
  Time: O(N^3)
  Space: O(N^2)  
*/
class Solution {
private: 
    void constructDistanceArray(vector<vector<int>>& edges, vector<vector<int>>& dist) {
        int n = dist.size();

        // Base cases: distance to self is 0
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Populate initial bidirectional edge values
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = dist[v][u] = w;
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Use a safe upper bound for infinity to prevent integer overflow when adding paths
        int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        constructDistanceArray(edges, dist);

        // Intermediate milestone 'mid' MUST be on the absolute outside
        for(int mid = 0; mid < n; mid++) {
            for(int src = 0; src < n; src++) {
                for(int dst = 0; dst < n; dst++) {
                    if(dist[src][mid] == INF || dist[mid][dst] == INF) continue;
                    
                    int distanceThroughMid = dist[src][mid] + dist[mid][dst];
                    if(distanceThroughMid < dist[src][dst]) {
                        dist[src][dst] = distanceThroughMid;
                    }
                }
            }
        }

        int resultCity;
        int minReachableCount = n;

        // Count valid reachable neighbors for each city
        for(int i = 0; i < n; i++) {
            int reachableCount = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            
            // Update result if we find a city with fewer neighbors,
            // or a larger city index in case of a tie (using <= handles the tie-break naturally)
            if(reachableCount <= minReachableCount) {
                minReachableCount = reachableCount;
                resultCity = i;
            }
        }
        return resultCity;
    }
};
