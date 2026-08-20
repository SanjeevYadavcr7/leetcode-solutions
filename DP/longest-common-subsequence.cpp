/*---------------------------------------------------------
Approach: Recursive
Time Complexity: O(2 ^ (M + N))
Space Complexity(recursion stack): O(M + N) 

class Solution {
private:
    int lcsHelper(int idx1, int idx2, string text1, string text2) {
        if(idx1 == text1.size() || idx2 == text2.size()) return 0;

        if(text1[idx1] == text2[idx2]) {
            return 1 + lcsHelper(idx1 + 1, idx2 + 1, text1, text2);
        }

        return max(lcsHelper(idx1 + 1, idx2, text1, text2), lcsHelper(idx1, idx2 + 1, text1, text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcsHelper(0, 0, text1, text2);
    }
};
*/
