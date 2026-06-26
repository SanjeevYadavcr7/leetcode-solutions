class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int max_len = 0;
        unordered_map<char, int> char_idx_map;
        
        for(int right = 0; right < n; right++) {
            char ch = s[right];
            if(char_idx_map.find(ch) != char_idx_map.end() && char_idx_map[ch] >= left) {
                left = char_idx_map[ch] + 1;
            }
            char_idx_map[ch] = right;
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
