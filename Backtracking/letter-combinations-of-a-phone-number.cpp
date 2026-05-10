
class Solution {
public:
    /*
       Time Complexity: O(3^N.4^M), 
       where N is the number of digits that map to 3 letters (like 2, 3, 4, 5, 6, 8)
       M is the number of digits that map to 4 letters (7, 9).
       
       Space Complexity: O(N+M) for the recursion stack.
    */

    void initializeMap(vector<string>& numMap) {
        numMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    }

    void getLetterCombination(int idx, string& digits, string& current, vector<string>& result, vector<string>& numMap) {
        if(idx == digits.size()) {
            result.push_back(current);
            return;
        }
        
        string letters = numMap[digits[idx] - '0'];
        for(char ch : letters) {
            current.push_back(ch);
            getLetterCombination(idx+1, digits, current, result, numMap);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> result;
        string current = "";
        vector<string> numMap;

        initializeMap(numMap);
        getLetterCombination(0, digits, current, result, numMap);
        return result;
    }
};
