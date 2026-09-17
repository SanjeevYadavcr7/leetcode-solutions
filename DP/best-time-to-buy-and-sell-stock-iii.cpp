class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<int> maxProfitToday(N);
        int result = 0;

        int minBuyPrice = prices[0];
        int maxProfitTillToday = 0;
        for(int i = 0; i < N; i++) {
            minBuyPrice = min(minBuyPrice, prices[i]);
            int todayProfit = prices[i] - minBuyPrice;
            maxProfitTillToday = max(maxProfitTillToday, todayProfit);
            maxProfitToday[i] = maxProfitTillToday;
        }

        int maxSellingPriceTillNow = 0;
        maxProfitTillToday = 0;
        for(int i = N - 1; i >= 0; i--) {
            maxSellingPriceTillNow = max(maxSellingPriceTillNow, prices[i]);
            int todayProfit = maxSellingPriceTillNow - prices[i];
            maxProfitTillToday = max(maxProfitTillToday, todayProfit);
            maxProfitToday[i] += maxProfitTillToday;
            result = max(result, maxProfitToday[i]);
        }

        return result;
    }
};
