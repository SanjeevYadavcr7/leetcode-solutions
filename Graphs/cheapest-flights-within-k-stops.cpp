/*
    Algorithm: Bellman-Ford (Custom)
    Time: O(K.E)
    Space: O(N)
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Relax edges at most k+1 times (k stops = k+1 edges)
        for(int i = 0; i <= k; i++) {
            /* 
                Temp array makes sure only level wise-relaxation happens.
                Use a copy so updates within this round don't cascade
                each round should only add ONE more edge to any path

                Use this example to understad: 
                0 -> 1 -> 2 -> 3 and src = 0, dst = 3, K = 1
            */
            vector<int> temp = dist;

            for(auto& flight : flights) {
                int src = flight[0], dst = flight[1], price = flight[2];
                if(dist[src] != INT_MAX && dist[src] + price < temp[dst]) {
                    temp[dst] = dist[src] + price;
                }
            }

            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};


/* ------------------------------------------------------------------------------------
    Total Work = Maximum Stops * Work per stop = (K + 1) * E
    
    Time: O(K.E)
    Space: O(N + M)
    where,
    N = number of cities
    M = number of flights
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        // Construct adjacency graph
        for(auto& flightInfo : flights) {
            int from = flightInfo[0];
            int to = flightInfo[1];
            int price = flightInfo[2];
            graph[from].push_back({to, price});
        }

        vector<int> minPrices(n, INT_MAX);
        minPrices[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});

        int stops = 0;

        while(!q.empty() && stops <= k) {
            int size = q.size();
            while(size--) {
                auto [from, priceTillNow] = q.front();
                q.pop();
                
                for(auto [to, price] : graph[from]) {
                    int nextPrice = price + priceTillNow;

                    if(minPrices[to] > nextPrice) {
                        minPrices[to] = nextPrice;
                        q.push({to, nextPrice});
                    }
                }
            }
            stops++;
        }
        return minPrices[dst] == INT_MAX ? -1 : minPrices[dst];
    }
};
