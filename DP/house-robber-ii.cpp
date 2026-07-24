
class Solution {
private:
    int robHelper(vector<int>& nums) {
        int n = nums.size();
        vector<int> money(n + 1);

        money[0] = 0;
        money[1] = nums[0];
        
        for(int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + money[i - 2];
            int skip = money[i - 1];
            money[i] = max(steal, skip);
        }

        return money[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();        
        if(n == 1) return nums[0];

        vector<int> temp1, temp2;

        for(int i = 0; i < n; i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }

        int moneyRobbed1 = robHelper(temp1);        
        int moneyRobbed2 = robHelper(temp2);

        return max(moneyRobbed1, moneyRobbed2);
    }
};
