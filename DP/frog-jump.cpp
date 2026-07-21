// General Solution for K steps:

class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> cost(n, INT_MAX);

        cost[0] = 0;
        cost[1] = abs(heights[0] - heights[1]);

        for(int i = 2; i < n; i++) {
            int minCost = INT_MAX;
            for(int j = 1; j <= k; j++) {
                int currJumpCost = abs(heights[i] - heights[i-j]) + cost[i-j];
                minCost = min(minCost, currJumpCost);
            }
            cost[i] = minCost;
        }

        return cost[n - 1];
    }
};



// --------------------------------------------------------------------------------------
// For 2 steps(i+1, i+2)

class Solution {
  public:
    int minCost(vector<int>& height) {
        
        int n = height.size();
        vector<int> cost(n);
        
        cost[0] = 0;
        cost[1] = abs(height[1] - height[0]);
        
        for(int i = 2; i < n; i++) {
            cost[i] = min(
                abs(height[i] - height[i - 1]) + cost[i - 1],
                abs(height[i] - height[i - 2]) + cost[i - 2]
                );
        }
        
        return cost[n - 1];
    }
};
