/*
Time: O(N^2)  |  Space: O(N^2)

Box ID Formula = (r / 3) * 3 + (c / 3)

The idea main idea in this question that we divide whole 9 * 9 grid into 9 smaller sub-grids of size 3 * 3. This is done to find BOX ID.
We find it by mapping the row and columns ID to 1D array value.
Normally if we have to find the cell value of a given row and column we use this formula: Index=(Row×Total Columns)+Column
Now in our case, we have divided whole grid into 9 smaller grids(each with ID 0, 1, 2, ....) so boxID formula becomes Box ID=(r/3)×3+(c/3)
*/

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
