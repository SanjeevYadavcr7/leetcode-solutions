class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size();
        int N = t.size();

        // if "s" is smaller than "t" then its subsequence cannot form "t"
        if(M < N) return 0;

        vector<vector<unsigned long long>> dp(M + 1, vector<unsigned long long>(N + 1));

        // if "t" is empty and "s" is not then one subsequence(empty) is always possible
        for(int i = 0; i <= M; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= M; i++) {
            char ch1 = s[i - 1];
            for(int j = 1; j <= N; j++) {
                char ch2 = t[j - 1];
                if(ch1 == ch2) {
                    // even when both characters match, we search the same character again in "s"
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[M][N];
    }
};
