class Solution {
public:
    // Time: O(M⋅N⋅4^L)  |  Space: O(L)   |  L is word length
    bool searchWord(int x, int y, int idx, string& word,vector<vector<char>>& board) {
        if(idx == word.size()) return true;
        if(x < 0 || y < 0 || x == board.size() || y == board[0].size()) return false;
        if(board[x][y] != word[idx] || board[x][y] == '-') return false;

        char ch = board[x][y];
        board[x][y] = '-'; // converting to lowercase to mark this path as visited
        bool result = searchWord(x + 1, y, idx + 1, word, board) 
                    || searchWord(x, y + 1, idx + 1, word, board)
                    || searchWord(x - 1, y, idx + 1, word, board)
                    || searchWord(x, y - 1, idx + 1, word, board);
        board[x][y] = ch;
        
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(searchWord(i, j, 0, word, board)) return true;
            }
        }
        return false;
    }
};
