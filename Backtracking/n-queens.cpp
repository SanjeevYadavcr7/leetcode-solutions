class Solution {
public:

    // Time: O(N!).O(N) 
    // Because isValidPosition takes O(N) time

    // bool isValidPosition(int rowIdx, int colIdx, int& n, vector<string>& current) {
    //     // Checking row straight to the left
    //     for(int j = 0; j <= colIdx; j++) {
    //         if(current[rowIdx][j] == 'Q') return false;
    //     }

    //     int r = rowIdx, c = colIdx;
    //     // Checking upper-left diagonal
    //     while(rowIdx > 0 && colIdx > 0) {
    //         if(current[rowIdx - 1][colIdx - 1] == 'Q') return false;
    //         rowIdx--, colIdx--;
    //     }

    //     rowIdx = r, colIdx = c;
    //     // Checking bottom-left diagonal
    //     while(rowIdx < n-1 && colIdx > 0) {
    //         if(current[rowIdx + 1][colIdx - 1] == 'Q') return false;
    //         rowIdx++, colIdx--;
    //     }

    //     return true;
    // }

    // void traverseBoard(int colIdx, int n, vector<string>& current, vector<vector<string>>& result) {
    //     if(colIdx == n) {
    //         result.push_back(current);
    //         return;
    //     }

    //     for(int rowIdx = 0; rowIdx < n; rowIdx++) {
    //         if(isValidPosition(rowIdx, colIdx, n, current)) {
    //             current[rowIdx][colIdx] = 'Q';
    //             traverseBoard(colIdx + 1, n, current, result);
    //             current[rowIdx][colIdx] = '.';
    //         }
    //     }
    // }

    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>> result;
    //     vector<string> current(n, string(n, '.'));
        
    //     traverseBoard(0, n, current, result);

    //     return result;
    // }



    // This approach uses constant time for checking board
    // whereas above approach was taking O(N) time
    void traverseBoard(int rowIdx, int& n, vector<string>& board, unordered_set<int>& col, unordered_set<int>& posDig, unordered_set<int>& negDig, vector<vector<string>>& result) {
        if(rowIdx == n) {
            result.push_back(board);
            return;
        }

        for(int colIdx = 0; colIdx < n; colIdx++) {
            if(col.count(colIdx) || posDig.count(rowIdx + colIdx) || negDig.count(rowIdx - colIdx)) {
                continue;
            }

            board[rowIdx][colIdx] = 'Q';
            col.insert(colIdx);
            posDig.insert(rowIdx + colIdx);
            negDig.insert(rowIdx - colIdx);

            traverseBoard(rowIdx + 1, n, board, col, posDig, negDig, result);

            // BACKTRACK: Clear old state before moving forward
            board[rowIdx][colIdx] = '.';
            col.erase(colIdx);
            posDig.erase(rowIdx + colIdx);
            negDig.erase(rowIdx - colIdx);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> col, posDig, negDig;

        traverseBoard(0, n, board, col, posDig, negDig, result);
        return result;
    }
};
