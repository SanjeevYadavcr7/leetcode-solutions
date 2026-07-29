/* 
Recursive Solution:

class Solution {
  private:
    int cols = 3;
    int getMaxPoints(int row, int lastUsedCol, vector<vector<int>>& mat) {
        if(row == 0) {
            int maxPoint = 0;
            for(int j = 0; j < cols; j++) {
                if(j != lastUsedCol) {
                    maxPoint = max(maxPoint, mat[row][j]);    
                }
            }
            return maxPoint;
        }
        
        int maxPoint = 0;
        
        for(int j = 0; j < cols; j++) {
            if(j != lastUsedCol) {
                int currPoint = mat[row][j] + getMaxPoints(row - 1, j, mat);
                maxPoint = max(maxPoint, currPoint);   
            }
        }
        return maxPoint;
    }

  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int rows = mat.size();
        return getMaxPoints(rows - 1, 3, mat);
    }
};
*/
