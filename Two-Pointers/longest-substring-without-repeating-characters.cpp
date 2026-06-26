/*
Time: O(N) |  Space: O(N)

Appraoch: In this question, we need to use Sliding Window + Hashing technique.

Point to remember:
Whenever repeating charater encounters(means window is invalid), move the window(make window valid).
When using a map to store indices for jumping the left pointer, 
always verify that the stored index is within the current window (>= left). 
Otherwise, the pointer might move backward, leading to incorrect window sizes. 

Example: abba 
When right pointer comes to second "a", then window is already between [b,a] i.e. if we jump to index[first_a] + 1 (which is 0 + 1 = 1),
then it will be invalid because current window starts from second index.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int max_len = 0;
        unordered_map<char, int> char_idx_map;
        
        for(int right = 0; right < n; right++) {
            char ch = s[right];
            
            // Check if repeating character exists in current window.
            if(char_idx_map.find(ch) != char_idx_map.end() && char_idx_map[ch] >= left) {
                left = char_idx_map[ch] + 1;
            }
            
            char_idx_map[ch] = right;
            
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
