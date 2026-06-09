/*
  Time: O(M.N)
  Space: O(M)
  where, 
  Max M unique numbers visited; each state processes N array numbers.
*/

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        
        // vector to keep track of minimum path
        vector<int> dist(1000, -1);
        dist[start] = 0;
        
        // BFS Queue
        queue<int> q;
        q.push(start);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int& num : arr) {
                int nbr = (node * num) % 1000;
                
                if(dist[nbr] == -1) {
                    dist[nbr] = dist[node] + 1;
                    
                    if(nbr == end) return dist[nbr];
                    
                    q.push(nbr);
                }
            }
        }
        
        return -1;
    }
};
