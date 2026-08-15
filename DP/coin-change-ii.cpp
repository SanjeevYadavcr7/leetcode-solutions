/*
Approach: Recursion + Memoization

NOTE: Using pick and non-pick approach we make sure that permutations are not formed.

class Solution {
private:
    int getWays(int idx, int amount, vector<vector<int>>& memo, vector<int>& coins) {
        if(amount == 0) return 1;

        if(idx == coins.size() || amount < 0) return 0;

        if(memo[idx][amount] != -1) return memo[idx][amount];

        int skip = getWays(idx + 1, amount, memo, coins);
        
        int take = 0;
        if(coins[idx] <= amount) {
            take = getWays(idx, amount - coins[idx], memo, coins);
        }

        return memo[idx][amount] = skip + take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(n + 1, vector<int>(amount + 1, -1));
        return getWays(0, amount, memo, coins);
    }
};
*/
