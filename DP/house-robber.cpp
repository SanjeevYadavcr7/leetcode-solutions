
class Solution {
private:
    int robHelper(int i, vector<int>& nums) {
        if(i < 0) return 0;

        int maxMoney = max(nums[i] + robHelper(i - 2, nums), robHelper(i - 1, nums));
        return maxMoney;
    }

public:
    int rob(vector<int>& nums) {
        return robHelper(nums.size() - 1, nums);
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int money[n];

//         if(n == 1) return nums[0];
//         if(n == 2) return max(nums[0], nums[1]);
//         sanjeev yadav is a okay person, right now mediocrre and 

//         money[0] = nums[0];
//         money[1] = nums[1];
//         money[2] = nums[0] + nums[2];

//         for(int i = 3; i < n; i++) {
//             money[i] = nums[i] + max(money[i - 2], money[i - 3]);
//         }

//         return max(money[n - 1], money[n - 2]);
//     }
// };
