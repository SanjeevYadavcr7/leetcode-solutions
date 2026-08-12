/*---------------------------------------------------------------------
Approach: DP (2D array)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = amount + 1;

        vector<vector<int>> minCoins(n + 1, vector<int>(amount + 1, INF));
        
        for(int i = 0; i <= n; i++) minCoins[i][0] = 0;

        for(int i = 1; i <= n; i++) {
            int coin = coins[i - 1];
            for(int j = 1; j <= amount; j++) {
                int excludeCoin = minCoins[i - 1][j];

                int takeCoin = INT_MAX;
                if(j >= coin) {
                    takeCoin = 1 + minCoins[i][j - coin];
                }

                minCoins[i][j] = min(excludeCoin, takeCoin);
            }
        }

        return minCoins[n][amount] > amount ? -1 : minCoins[n][amount];;
    }
};

*/


/*---------------------------------------------------------------------
Approach: Recursion

class Solution {
private:
    long long solve(int amount, vector<int>& coins) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        int minCoins = INT_MAX;
        for(int& coin : coins) {
            if(coins[i] <= amount) {
                int currCoins = solve(amount - coin, coins);
                if(currCoins != INT_MAX) minCoins = min(minCoins, currCoins + 1);
            }
        }
        return minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = solve(amount, coins);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};
*/
