/*
    Optimized Bottom-up in O(1) space and O(N) Time.
*/
class Solution {
private: 
    int robHelper(int start, int end, vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        for(int i = start; i <= end; i++) {
            int currMax = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = currMax;
        }

        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(robHelper(0, n - 2, nums), robHelper(1, n - 1, nums));
    }
};


/* -------------------------------------------------------------------------------
    Bottom-up in O(N) Space and Time.
*/
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
