class Solution {
public:
    void transposeMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; i++) {
            for(int j=i; j<n; j++) {
                if(i != j) {
                    int temp = matrix[j][i];
                    matrix[j][i] = matrix[i][j];
                    matrix[i][j] = temp; 
                }
            }
        }
    }

    void reverseCols(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n/2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transposeMatrix(matrix);
        reverseCols(matrix);
    }
};
