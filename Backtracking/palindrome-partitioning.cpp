class Solution {
public:
    // Time: O(N⋅2^N), Space: O(N).

    bool isPalindrome(string str) {
        int n = str.size();
        for(int i = 0; i < n / 2; i++) {
            if(str[i] != str[n - i - 1]) return false;
        }
        return true;
    }

    void partition(int idx, string word, vector<string>& current, vector<vector<string>>& result) {
        if(idx == word.size()) {
            result.push_back(current);
            return;
        }

        for(int i = idx; i < word.size(); i++) {
            string str = word.substr(idx, i - idx + 1);
            if(isPalindrome(str)) {
                current.push_back(str);
                partition(i + 1, word, current, result);
                current.pop_back();
            } 
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;

        partition(0, s, current, result);
        return result;
    }
};
