// Problem Link: https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size();
        int N = p.size();

        // dp[i][j] = true if p[i...] matches s[j...]
        vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));

        // Base case: empty p matches empty s
        dp[N][M] = true;

        // Base case: empty s matches suffix of p only if trailing chars are '*'
        for(int i = N - 1; i >= 0; i--) {
            if(p[i] == '*') {
                dp[i][M] = dp[i + 1][M];
            }
        }

        for(int i = N - 1; i >= 0; i--) {
            for(int j = M - 1; j >= 0; j--) {
                char ch = p[i];
                if(p[i] == '*') {
                    // dp[i][j + 1]: '*' matches at least one character from s
                    // dp[i + 1][j]: '*' matches empty sequence
                    dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                } else if(p[i] == '?' || ch == s[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0];
    }
};
