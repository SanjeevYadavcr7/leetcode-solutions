#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int evalRPN(vector<string>& tokens) {
    if(tokens.empty()) return 0;
    stack<int> stk;    
    int res;    
    for(string& ch : tokens) {
        if(ch == "+" || ch == "-" || ch == "*" || ch == "/") {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
    
            res = 0;
            if(ch == "+") res += (num1 + num2);
            else if(ch == "-") res += (num2 - num1);
            else if(ch == "*") res += (num1 * num2);
            else res += (num2 / num1);

            cout << "Num1 = " << num1 << " | Num2 = " << num2 << " | ";
            cout << "Temp res = " << res << endl;

            stk.push(res);
        } else {
            stk.push(stoi(ch));
        }
    }
    return res;
}

int main() {
    vector<string> str = {"4","13","5","/","+"};
    cout << "Evaluating...";
    int result = evalRPN(str);
    cout << "Result = " << result << endl;
    return 0;
}