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
