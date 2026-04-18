class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> candidates;
        int count1 = 0, candidate1 = INT_MIN;
        int count2 = 0, candidate2 = INT_MIN;

        for(const int& num : nums) {
            if(count1 == 0 && num != candidate2) {
                count1++;
                candidate1 = num;
            } else if(count2 == 0 && num != candidate1) {
                count2++;
                candidate2 = num;
            } else if(num == candidate1) {
                count1++;
            }
            else if(num == candidate2) {
                count2++;
            } else {
                count1--, count2--;
            }
        }

        count1 = count2 = 0;
        for(const int& num : nums) {
            if(num == candidate1) count1++;
            if(num == candidate2) count2++;
        }

        if(count1 > nums.size()/3) candidates.push_back(candidate1);
        if(count2 > nums.size()/3) candidates.push_back(candidate2);
        return candidates;
    }
};
