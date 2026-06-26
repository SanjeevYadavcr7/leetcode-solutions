/*
Time: O(N) | Space: O(1)


IMPORTANT:
The idea is to not think about previous or future day, but think about what you've today and maximize the profit based on that. 
Additionaly, maintain a state which will hold minimum price till current day.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int n = prices.size();
        int max_profit = 0;
        int min_price = prices[0];
        int today_profit = 0;
        
        for(const int& price: prices) {
            min_price = min(min_price, price);
            today_profit = price - min_price;
            max_profit = max(max_profit, today_profit);
        }
        return max_profit;
    }
}; 