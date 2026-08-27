/*
Approach: DP(2D array)
The idea is to compare suffix of prefixes of both strings.

Example: 
s1 = "ABCD" | s2 = "BCD"

prefixes(s1) = { "A" ,"AB" ,"ABC" ,"ABCD" }
prefixes(s2) = { "B" ,"BC" ,"BCD" }

Common suffix = { "B", "BC", "BCD" }
Longest Common Suffix = "BCD"
*/
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        int maxLCSLen = 0;
        for(int i = 1; i <= n; i++) {
            char ch1 = s1[i - 1];
            for(int j = 1; j <= m; j++) {
                char ch2 = s2[j - 1];
                if(ch1 == ch2) dp[i][j] = 1 + dp[i - 1][j - 1];
                
                maxLCSLen = max(maxLCSLen, dp[i][j]);
            }
        }
        
        return maxLCSLen;
    }
};
