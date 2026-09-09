class Solution {
  private:
    int getLCSLen(string &s1, string &s2) {
        int N = s1.size();
        int M = s2.size();
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
        
        for(int i = 1; i <= N; i++) {
            char ch1 = s1[i - 1];
            for(int j = 1; j <= M; j++) {
                char ch2 = s2[j - 1];
                if(ch1 == ch2) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[N][M];
    }
  public:
    int minOperations(string &s1, string &s2) {
        int lcsLen = getLCSLen(s1, s2);
        int removeOp = s1.size() - lcsLen;
        int insertOp = s2.size() - lcsLen;
        return removeOp + insertOp;
    }
};
