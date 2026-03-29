#include <vector>
using namespace std;

/*
    Time: O(N^2)  |  Space: O(N^2)
    NOTE: 
    In this problem, we could've taken 2D vector as well but we chose 2D fixed array.
    Because fixed arrays are faster than dynamic arrays because fixed arrays are stored
    in Stack in a contiguous fashion(read is fast) and dynamic is stored on heap.
*/
bool isValidSudoku(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size(); 
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};

    for(int r=0; r<9; r++) {
        for(int c=0; c<9; c++) {
            if(board[r][c] == '.') continue;
            
            int val = board[r][c] - '1';
            int box_idx = (r / 3) * 3 + (c / 3);
            if(rows[r][val] || cols[c][val] || boxes[box_idx][val]) {
                return false;
            }

            rows[r][val] = cols[c][val] = boxes[box_idx][val] = true;
        }
    }
    return true;
}