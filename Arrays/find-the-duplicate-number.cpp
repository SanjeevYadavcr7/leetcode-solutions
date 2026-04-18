class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0], fast = nums[0];

        // Find cycle(using linked list comcept)
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        // move slow pointer from start and slow2 from intersection point
        slow = nums[0];
        int slow2 = fast;
        while(slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
