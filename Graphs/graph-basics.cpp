/*
    Graph is represented using 2 ways:
    1. Adjacency Matrix : This is a O(V^2) solution because we have to make a 2D matrix of size N
    2. Adjacency List : This is O(V+E) solution
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public: 
    // Representing undirected graph using Adjacency Matrix
    vector<vector<int>> getAdjacencyMatrix(int n, vector<pair<int, int>> edges) {
        vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 0));
        
        for(auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
        return adjMatrix;
    }

    // Representing undirected graph using Adjacency List
    vector<vector<int>> getAdjacencyList(int n, vector<pair<int, int>> edges) {
        vector<vector<int>> adjList(n + 1);
        
        for(auto& edge : edges) {
            auto [u, v] = edge;
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return adjList;
    }
};
