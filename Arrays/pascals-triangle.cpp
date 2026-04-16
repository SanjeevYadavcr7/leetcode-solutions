class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasTri;
        int row = 0;
        while(numRows--) {
            if(row == 0) pasTri.push_back({1});
            else if(row == 1) pasTri.push_back({1,1});
            else {
                vector<int> curr_row(row+1);
                curr_row[0] = curr_row[row] = 1;
                for(int i=1; i<row; i++) {
                    int curr_num = pasTri[row-1][i-1] + pasTri[row-1][i];
                    curr_row[i] = curr_num;
                }
                pasTri.push_back(curr_row);
            }
            row++;
        }
        return pasTri;   
    }
};
