#include<iostream>
#include<vector>
using namespace std;

/*
    Time Complexity  : O(N^2)  
    Space Complexity : O(N)
*/

class Solution {
private: 
    void dfs(int node, int& n, vector<bool>& visited, vector<vector<int>>& isConnected) {
        visited[node] = true;
        
        for(int nbr = 0; nbr < n; nbr++) {
            if(isConnected[node][nbr] == 1 && !visited[nbr]) {
                dfs(nbr, n, visited, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                provinces++;
                dfs(i, n, visited, isConnected);
            }
        }
        return provinces;
    }

    // BFS Approach
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                queue<int> nodes;
                nodes.push(i);
                visited[i] = true;
                provinces++;

                while(!nodes.empty()) {
                    int node = nodes.front();
                    nodes.pop();

                    for(int nbr = 0; nbr < n; nbr++) {
                        if(isConnected[node][nbr] == 1 && !visited[nbr]) {
                            visited[nbr] = true;
                            nodes.push(nbr);
                        }
                    }
                }
            }   
        }
        return provinces;
    }
};