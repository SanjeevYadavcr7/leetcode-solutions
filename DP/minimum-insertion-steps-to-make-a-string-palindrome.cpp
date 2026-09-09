class Solution {
private:
    int getLongestPanlindromeSeqLen(string s) {
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));

        for(int gap = 0; gap < N; gap++) {
            for(int i = 0, j = gap; j < N; i++, j++) {
                if(gap == 0) dp[i][j] = 1;
                else if(gap == 1) dp[i][j] = (s[i] == s[j]) ? 2 : 1;
                else {
                    if(s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
                    else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][N - 1];
    }
public:
    int minInsertions(string s) {
        int longestPalLen = getLongestPanlindromeSeqLen(s);
        int insertions = s.size() - longestPalLen;
        return insertions;
    }
};
