/*
	Time: O(V.E) --> V-1 * E + E
	Space: O(V) --> Distance vector 
*/

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class BellmanFord {
public:
    // times array format: {u, v, w} representing an edge from u to v with weight w
    bool getShortestPaths(int V, vector<vector<int>>& edges, int src, vector<int>& dist) {
        // Initialize distances from src to all other vertices as infinite
        dist.assign(V, INT_MAX);
        dist[src] = 0;

        // Step 1: Relax all edges (V - 1) times
        for (int i = 1; i <= V - 1; ++i) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];

                // If the source of the edge has been reached, check for a shortcut
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Step 2: The V-th iteration to detect negative weight cycles
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                // Distance is still decreasing! A negative cycle exists.
                return false; 
            }
        }

        return true; // Paths calculated successfully with no negative cycles
    }
};