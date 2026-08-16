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
