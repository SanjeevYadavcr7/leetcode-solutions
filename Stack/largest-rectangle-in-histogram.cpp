// Time: O(N)  |  Space: O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> stk;

        // To handle when bars are given in increasing order of height
        heights.push_back(0);

        for(int r_idx = 0; r_idx < heights.size(); r_idx++) {
            /* 
              Height of current bar is greater than the bar on in just right
              This means current bar area cannot extend hence calculate area
              for current bar
            */
            while(!stk.empty() && heights[stk.top()] > heights[r_idx]) {
                int currBarHeight = heights[stk.top()];
                stk.pop();

                // Getting bounday of current rectangle
                int l_boundary = stk.empty() ? -1 : stk.top();
                int currBarWidth = (r_idx - l_boundary - 1);

                // Area of current reactangle
                int areaByCurrBar = currBarHeight * currBarWidth;
                
                maxArea = max(maxArea, areaByCurrBar);    
            }

            stk.push(r_idx);
        }

        heights.pop_back();

        return maxArea;
    }
};