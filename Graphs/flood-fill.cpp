#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int m, n;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isInsideImage(int x, int y) {
        return (x >= 0 && x < m) && (y >= 0 && y < n);
    }
public:
    void traverseImage(int x, int y, int color, vector<vector<int>>& image) {
        if(!isInsideImage(x, y) || image[x][y] == color) return;

        int prev_color = image[x][y];
        image[x][y] = color;
        for(auto [x_dir, y_dir]: directions) {
            int new_x = x + x_dir;
            int new_y = y + y_dir;
            if(isInsideImage(new_x, new_y) && image[new_x][new_y] == prev_color) {
                traverseImage(new_x, new_y, color, image);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        traverseImage(sr, sc, color, image);
        return image;
    }
};

int main() {
    vector<vector<int>> image = {{0,0,0}, {0,0,0}};
    int sr = 0;
    int sc = 0;
    int color = 0;

    Solution obj;

    image = obj.floodFill(image, sr, sc, color);
}