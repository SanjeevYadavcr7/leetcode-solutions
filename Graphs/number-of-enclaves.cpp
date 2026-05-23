class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 1) {
            return;
        }

        board[i][j] = 0;
        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
    }

    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int totalEnclaves = 0;

        for(int i = 0; i < m; i++) {
            dfs(i, 0, board);
            dfs(i, n-1, board);
        }

        for(int j = 0; j < n; j++) {
            dfs(0, j, board);
            dfs(m-1, j, board);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1) {
                    totalEnclaves++;
                }
            }
        }
        return totalEnclaves;
    }
};
