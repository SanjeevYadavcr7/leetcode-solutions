class Solution {
public:
    void processParenthesis(int openLeft, int closeLeft, string& current, vector<string>& result) {
        if(openLeft == 0 && closeLeft == 0) {
            result.push_back(current);
            return;
        }

        if(openLeft > 0) {
            current.push_back('(');
            processParenthesis(openLeft - 1, closeLeft, current, result);
            current.pop_back();
        }


        /* If openLeft < closeLeft this means, we can put more ")" because close brackets are still left.
           Don't confuse closeLeft with close. closeLeft tells how many closing brackets are still available
           for selection.
        */
        if(openLeft < closeLeft) {
            current.push_back(')');
            processParenthesis(openLeft, closeLeft - 1, current, result);
            current.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int openLeft = n, closeLeft = n;
        string current = "";

        processParenthesis(openLeft, closeLeft, current, result);
        return result;
    }
};
