// Approach: Bottom-Up(DP)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> money(n + 1); // Taking n + 1 to count money till house N

        // Base Case
        money[0] = 0;
        money[1] = nums[0];

        for(int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + money[i - 2];
            int skip = money[i - 1];
            money[i] = max(steal, skip);
        }

        return money[n];
    }
};

/* 
Approach: Bottom-Up + Memoization

class Solution {
private:
    int robHelper(int idx, vector<int>& memo, vector<int>& nums) {
        if(idx >= nums.size()) {
            return 0;
        }

        if(memo[idx] != 0) return memo[idx];

        int moneyIncludingCurrentHouse = nums[idx] + robHelper(idx + 2, memo, nums);
        int moneyExcludingCurrentHouse = robHelper(idx + 1, memo, nums);

        return memo[idx] = max(moneyIncludingCurrentHouse, moneyExcludingCurrentHouse);
    }

public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        return robHelper(0, memo, nums);
    }
};
*/

/* 
Approach: Bottom-Up Recursion

class Solution {
private:
    int robHelper(int idx, vector<int>& nums) {
        if(idx >= nums.size()) {
            return 0;
        }

        int moneyIncludingCurrentHouse = nums[idx] + robHelper(idx + 2, nums);
        int moneyExcludingCurrentHouse = robHelper(idx + 1, nums);
        return max(moneyIncludingCurrentHouse, moneyExcludingCurrentHouse);
    }

public:
    int rob(vector<int>& nums) {
        return robHelper(0, nums);
    }
};
*/
