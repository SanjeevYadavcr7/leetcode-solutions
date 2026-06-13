/*
  Time: O(V^3)  -->  O(V.V.V)  --> Three explicit nested loops assessing every vertex as a middle milestone (K).
  Space: O(V^2)  -->  2D Matrix
*/

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FloydWarshall {
public:
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

    void shortestDistance(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of vertices

        // Phase 1: Pre-process the input matrix
        // Replace -1 placeholder values with a safe infinity upper bound
        int INF = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1 && i != j) {
                    matrix[i][j] = INF;
                }
            }
        }

        // Phase 2: Core Floyd-Warshall Loops
        // Loop K represents the allowed intermediate node
        for (int k = 0; k < n; k++) {
            // Loop i represents the source node
            for (int i = 0; i < n; i++) {
                // Loop j represents the destination node
                for (int j = 0; j < n; j++) {
                    // If paths through intermediate node 'k' exist, try to relax
                    if (matrix[i][k] != INF && matrix[k][j] != INF) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        // Phase 3: Post-process back to standard format
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INF) {
                    matrix[i][j] = -1; // Path is completely unreachable
                }
            }
        }
    }
};


int main() {
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 2},
                                 {1, 2, 3},
                                 {2, 3, 1}};
    
    FloydWarshall obj;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    
    obj.constructDistanceArray(edges, dist);

    obj.shortestDistance(dist);

    cout << "Result = \n";
    for(auto& row : dist) {
        for(int& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}