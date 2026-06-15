/*
  Time : O(N^2)  -->  O(N^2) when marking islands + O(N^2) when replacing 0 with 1
  Space: O(N^2)  -->  Max entries in islandID -> size map
*/

class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool isValidCell(int r, int c, int N) {
        return (r >= 0 && r < N && c >= 0 && c < N);
    }

    int getIslandSize(int row, int col, int& islandID, vector<vector<int>>& grid) { 
        int size = 1;
        grid[row][col] = islandID;

        for(auto [x, y] : directions) {
            int nbr_row = row + x;
            int nbr_col = col + y;
            if(isValidCell(nbr_row, nbr_col, grid.size()) && grid[nbr_row][nbr_col] == 1) {
                size += getIslandSize(nbr_row, nbr_col, islandID, grid);
            }
        }
        return size;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int N = grid.size();

        // starting assigned ID to island. Cannot use 0 and 1 to mark island because those are already used
        int islandID = 2;
        int maxIslandArea = 0;
        unordered_map<int, int> islandIDToArea;

        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N; c++) {
                // If current cell is a land, mark all the neighbouring lands 
                if(grid[r][c] == 1) {
                    int islandSize = getIslandSize(r, c, islandID, grid);
                    islandIDToArea[islandID] = islandSize;  // store current island area in a map

                    // what if there are no zeros --> we only have one island which has maximum area
                    maxIslandArea = max(maxIslandArea, islandSize);

                    islandID++;
                }
            }
        }

        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N; c++) {
                if(grid[r][c] == 0) {

                    /* 
                        Using this set to uniquely pick islandIDs
                        Suppose we have --> left and top 1(part of same island) and in middle zero 
                        then that 1(island area) will add left and top 2 times
                    */
                    unordered_set<int> uniqueNbrIslands;

                    for(auto [x, y] : directions) {
                        int new_r = r + x;
                        int new_c = c + y;
                        if(isValidCell(new_r, new_c, N) && grid[new_r][new_c] > 1) {
                            uniqueNbrIslands.insert(grid[new_r][new_c]);
                        }
                    }

                    int currIslandSize = 1;
                    for(auto islandID : uniqueNbrIslands) {
                        currIslandSize += islandIDToArea[islandID]; 
                    }
                    maxIslandArea = max(maxIslandArea, currIslandSize);
                }
            }
        }

        return maxIslandArea;
    }
};
