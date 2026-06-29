
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq; // Stores indices
        
        for (int i = 0; i < nums.size(); ++i) {
            // 1. Remove indices that are out of the current window bounds
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // 2. Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // 3. Add current element's index
            dq.push_back(i);
            
            // 4. Append the max of the current window to the result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};
