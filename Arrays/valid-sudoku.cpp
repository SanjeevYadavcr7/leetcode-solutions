
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        bool rows[9][9];
        bool columns[9][9];
        bool subBoxes[9][9];

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(board[r][c] == '.') continue;

                int num = board[r][c] - '1';
                int boxId = (r / 3) * 3 + (c / 3);
                if(rows[r][num] || columns[c][num] || subBoxes[boxId][num]) return false;

                rows[r][num] = columns[c][num] = subBoxes[boxId][num] = true;
            }
        }

        return true;
    }
};
