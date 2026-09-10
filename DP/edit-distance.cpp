class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

        // if "word1" is empty then we have to insert "N" characters to get "word2"
        for(int i = 0; i <= M; i++) dp[i][0] = i;

        // if "word2" is empty then we have to delete "M" characters to get "word2"
        for(int j = 0; j <= N; j++) dp[0][j] = j;

        /* 
        The idea is when characters in "word1" and "word2" are same then we do not need to perform any operation. If characters are not same then we need to perform either of 3 operations(insert, delete, replace). The result will be whatever operations results in minimum operation to convert 
        to "word2"
        */
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int insertOp = dp[i][j - 1]; // inserted matching character hence "word2" pointer will move
                    int deleteOp = dp[i - 1][j]; // deleted character from "word1" hence "word1" pointer will move
                    int replaceOp = dp[i - 1][j - 1]; // replaced character to make it same, both pointers will move
                    dp[i][j] = 1 + min({ insertOp, deleteOp, replaceOp });
                }
            }
        }

        return dp[M][N];
    }
};
