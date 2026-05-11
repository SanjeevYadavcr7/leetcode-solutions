/*
    Graph is represented using 2 ways:
    1. Adjacency Matrix : This is a O(N^2) solution because we have to make a 2D matrix of size N
    2. Adjacency List : 
*/


// Representing graph using Adjacency List
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public: 
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

};