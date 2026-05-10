class Solution {
public:
    bool isValidPosition(int rowIdx, int colIdx, int& n, vector<string>& current) {
        // Checking row straight to the left
        for(int j = 0; j <= colIdx; j++) {
            if(current[rowIdx][j] == 'Q') return false;
        }

        int r = rowIdx, c = colIdx;
        // Checking upper-left diagonal
        while(rowIdx > 0 && colIdx > 0) {
            if(current[rowIdx - 1][colIdx - 1] == 'Q') return false;
            rowIdx--, colIdx--;
        }

        rowIdx = r, colIdx = c;
        // Checking bottom-left diagonal
        while(rowIdx < n-1 && colIdx > 0) {
            if(current[rowIdx + 1][colIdx - 1] == 'Q') return false;
            rowIdx++, colIdx--;
        }

        return true;
    }

    void traverseBoard(int colIdx, int n, vector<string>& current, vector<vector<string>>& result) {
        if(colIdx == n) {
            result.push_back(current);
            return;
        }

        for(int rowIdx = 0; rowIdx < n; rowIdx++) {
            if(isValidPosition(rowIdx, colIdx, n, current)) {
                current[rowIdx][colIdx] = 'Q';
                traverseBoard(colIdx + 1, n, current, result);
                current[rowIdx][colIdx] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> current(n, string(n, '.'));
        
        traverseBoard(0, n, current, result);

        return result;
    }
};
