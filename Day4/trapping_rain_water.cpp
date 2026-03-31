class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int leftMax = height[0], rightMax = height[n-1];
        int trappedWater = 0;

        while(left < right) {
            if(leftMax < rightMax) {
                trappedWater += leftMax - min(leftMax, height[left]);
                left++;
                leftMax = max(height[left], leftMax);
            } else {
                trappedWater += rightMax - min(rightMax, height[right]);
                right--;
                rightMax = max(height[right], rightMax);
            }
        }
        return trappedWater;
    }
};