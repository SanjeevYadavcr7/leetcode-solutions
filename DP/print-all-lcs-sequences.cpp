class Solution {
  private:
    unordered_map<string, vector<string>> memo;
    
    vector<string> solve(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        if(i == 0 || j == 0 || dp[i][j] == 0) {
            return {""};   
        }
        
        string key = to_string(i) + "," + to_string(j);
        if(memo.count(key)) return memo[key];
        
        set<string> unique_lcs;
        if(s1[i - 1] == s2[j - 1]) {
            vector<string> sub = solve(i - 1, j - 1, s1, s2, dp);
            for(string str : sub) unique_lcs.insert(str + s1[i - 1]);
        } else {
            if(dp[i][j] == dp[i - 1][j]) {
                vector<string> sub = solve(i - 1, j, s1, s2, dp);
                for(string str : sub) unique_lcs.insert(str);
            } 
            
            if(dp[i][j] == dp[i][j - 1]) {
                vector<string> sub = solve(i, j - 1, s1, s2, dp);
                for(string str : sub) unique_lcs.insert(str);
            } 
        }
        
        return memo[key] = vector<string>(unique_lcs.begin(), unique_lcs.end());
    }
  public:
    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        vector<string> result = solve(n, m, s1, s2, dp);
        sort(result.begin(), result.end());
        return result;
    }
};
