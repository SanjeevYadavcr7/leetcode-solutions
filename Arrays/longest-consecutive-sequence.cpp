/*
    Time: O(N)  
    Space: O(N)

    IMPORTANT:
    The key optimization is only starting a count if num - 1 is not present,
    this ensures each element is processed in linear time O(N) else solution will be of O(N^2)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq;

        for(int num:nums) seq.insert(num);
        
        int maxCount = 0;
        for(int num : seq){
            // If current num if starting of the sequence
            if(!seq.count(num - 1)){
                int count=0;

                while(seq.count(num)){
                    count++;
                    num++;
                }
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};
