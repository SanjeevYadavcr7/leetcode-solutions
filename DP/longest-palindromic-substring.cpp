// DP Solution - Time: O(N^2) + Space: O(N^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        if(N <= 1) return s;

        vector<vector<bool>> dp(N, vector<bool>(N, false));

        int maxLen = 1, start = 0;

        for(int i = N - 1; i >= 0; i--) {
            dp[i][i] = true;
            
            for(int j = i + 1; j < N; j++) {
                if(s[i] == s[j]) {
                    if(j - i == 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if(j - i + 1 > maxLen) {
                            maxLen = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
        }

        string LPS = s.substr(start, maxLen);
        return LPS;
    }
};
