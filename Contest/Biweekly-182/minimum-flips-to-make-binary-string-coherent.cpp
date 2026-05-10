class Solution {
public:
    int minFlips(string s) {
        if(s.size() < 3) return 0;
        
        int result;

        int zero_cnt = count(s.begin(), s.end(), '0');
        int one_cnt = s.size() - zero_cnt;

        // Either all 0s or all 1s
        result = min(zero_cnt, one_cnt); 
        
        // Only one 1 in string (1000..., ...00001, ...00100...)
        result = min(result, max(0, one_cnt - 1));

        // Two 1s on boundaries (1000....0001)
        int flipsForTwoOnes = one_cnt - (s[0] - '0') - (s[s.size() - 1] - '0');
        result = min(result, flipsForTwoOnes);
        return result;
    }
};