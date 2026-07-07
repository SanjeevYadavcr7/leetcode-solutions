/*
  Time  : O(E.LogE)  -->  because of use of priority queue
  Space : O(V + E)   -->  graph size
*/

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> itinerary;

    void dfs(string node) {
        while(!graph[node].empty()) {
            string nbr = graph[node].top();
            graph[node].pop();
            dfs(nbr);
        }

        itinerary.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Map destinations to respective source + Sort in lexographical order 
        for(auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        // Perform DFS to construct itinerary
        dfs("JFK");

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};
