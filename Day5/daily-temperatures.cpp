#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> warmer_temp(n);
    stack<int> stk;

    for(int i = 0; i < n; i++) {
        while(!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
            warmer_temp[stk.top()] = i - stk.top();
            stk.pop();
        }
        cout << "Warmer[] = ";
        for(int& temp : warmer_temp) cout << temp << " ";
        cout << endl;

        stk.push(i);
    }
    return warmer_temp;
}

int main() {
    vector<int> arr = {73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(arr);
    cout << "\nRes = ";
    for(int& temp : res) cout << temp << " ";
    cout << endl;

    return 0;
}