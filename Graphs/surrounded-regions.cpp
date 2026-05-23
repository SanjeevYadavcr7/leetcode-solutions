class Solution {
public:
  // Time: O(M.N) + Space: O(M.N)

    void markZeros(queue<pair<int, int>>& zerosIdx, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Marking first and last column zeros
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                zerosIdx.push({i, 0});
                board[i][0] = 'V';
            }
            if(board[i][n - 1] == 'O') {
                zerosIdx.push({i, n - 1});
                board[i][n-1] = 'V';
            }
        }

        // Marking first and last row zeros 
        for(int j = 1; j < n - 1; j++) {
            if(board[0][j] == 'O') {
                zerosIdx.push({0, j});
                board[0][j] = 'V';
            }
            if(board[m - 1][j] == 'O') {
                zerosIdx.push({m - 1, j});
                board[m-1][j] = 'V';
            }
        }
    }

    bool isInBoard(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    void markRegion(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'V') {
                    board[i][j] = 'O';  // not surrounded region
                } 
                else if(board[i][j] == 'O') {
                    board[i][j] = 'X';  // surrounded region
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> zerosIdx;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        markZeros(zerosIdx, board);

        while(!zerosIdx.empty()) {
            auto [r, c] = zerosIdx.front();
            zerosIdx.pop();

            for(auto [x, y] : directions) {
                int new_x = x + r;
                int new_y = y + c;
                if(isInBoard(new_x, new_y, m, n) && board[new_x][new_y] == 'O') {
                    zerosIdx.push({new_x, new_y});
                    board[new_x][new_y] = 'V';
                }
            }
        }

        markRegion(board);
    }
};
