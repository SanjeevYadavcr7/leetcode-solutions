/*
Time: O(N) | Space: O(N)

First of all, whenever you see "Longest Reapeating...", "Longest Subsequnce....", etc. 
then high probability is that the problem is a sliding window type problem.


Sliding Window solution follows this pattern :
1. Moving right pointer to increase window size
2. Increase right until window is valid
3. If window is invalid, sequeeze the window by placing left pointer at a position which makes the window valid.

In this problem, we keep on moving right pointer until window becomes invalid i.e. (window_size - max_freq > k) i.e. (replacements > k)

IMPORTANT:
The key takeaway here is that once we have found a valid window, we don't need to decrease the size of it. 
The window keeps moving toward the right. At each step, even if the window becomes invalid, we never decrease its size. 
We increase the size only when we find a valid window of larger size.
*/

class Solution {
public:
    bool isWindowValid(int win_size, int max_freq, int k) {
        return (win_size - max_freq <= k);
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int max_len = 0;
        int max_freq = 0;
        unordered_map<char, int> char_freq_map;

        for(int right = 0; right < n; right++) {
            char ch = s[right];
            int window_size = right - left + 1;

            char_freq_map[ch]++;
            max_freq = max(max_freq, char_freq_map[ch]);

            if(!isWindowValid(window_size, max_freq, k)) {
                char_freq_map[s[left]]--;
                left++;
            } 
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
