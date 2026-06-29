class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2) return false;
        
        vector<int> char_freq_1(26, 0);
        vector<int> char_freq_2(26, 0);
        
        for(char& ch : s1) char_freq_1[ch - 'a']++;
        for(int i = 0; i < n1; i++) char_freq_2[s2[i] - 'a']++;

        if(char_freq_1 == char_freq_2) return true;

        for(int i = n1; i < n2; i++) {
            char left_idx = s2[i-n1] - 'a';
            char right_idx = s2[i] - 'a';
            
            char_freq_2[left_idx]--; // removing character that is out of window.
            char_freq_2[right_idx]++; // adding new character in window
            if(char_freq_1 == char_freq_2) return true;
        }
        
        return false;
    }
};
