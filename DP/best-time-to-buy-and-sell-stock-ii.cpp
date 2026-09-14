class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int totalProfit = 0;
        int buy = 0, sell = 0;

        for(int i = 0; i < N - 1; i++) {
            if(prices[i + 1] > prices[i]) {
                sell++;
            } else {
                int currProfit = prices[sell] - prices[buy];
                if(currProfit > 0) {
                    totalProfit += currProfit;
                }
                sell = buy = i + 1;
            }
        }

        int lastBuyProfit = prices[sell] - prices[buy];
        totalProfit += (lastBuyProfit > 0 ? lastBuyProfit : 0);

        return totalProfit;
    }
};
