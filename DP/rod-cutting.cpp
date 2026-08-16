/*
Approach - DP (1D array)

maxPrice[i] = maximum value can be obtained by selling upto length "i + 1"

So the recurrence relation is:
    maxPrice[i] = max(maxPrice[i], (maxPrice[beg] + maxPrice[end]));

This means for length 4:
    maxPrice = max((0 + 4), (1 + 3), (2 + 2))
*/
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        int maxPrice[n + 1];
        
        maxPrice[0] = 0;
        maxPrice[1] = price[0];
        for(int i = 2; i <= n; i++) {
            maxPrice[i] = price[i - 1];
            
            int beg = 1, end = i - 1;
            while(beg <= end) {
                maxPrice[i] = max(maxPrice[i], (maxPrice[beg] + maxPrice[end]));
                beg++, end--;
            }
        }

        return maxPrice[n];
    }
};
