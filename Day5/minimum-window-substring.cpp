#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

string minWindow(string s, string t) {
    if(t.empty()) return "";

    unordered_map<char, int> countT, window;
    for(char& ch : t) countT[ch]++;

    int have = 0, need = countT.size(); 
    int res_start = 0, min_len = INT_MAX;
    int left = 0;
    for(int right = 0; right < s.size(); right++) {
        char ch = s[right];
        window[ch]++;

        if(countT.count(ch) && window[ch] == countT[ch]) have++;

        cout << "Have = " << have << " | window[ch] = " << window[ch] << endl;

        while(have == need) {
            int curr_len = right - left + 1;
            if(curr_len < min_len) {
                min_len = curr_len;
                res_start = left;
            }
            
            window[s[left]]--;
            if(countT.count(s[left]) && window[s[left]] < countT[s[left]]) have--;
            left++;
        }
    }
    return min_len == INT_MAX ? "" : s.substr(res_start, min_len);
}

int main() {
    string s,t;
    cin >> s;
    cin >> t;

    cout << "S = " << s << " | T = " << t << endl;

    string min_sub_str = minWindow(s,t);
    cout << min_sub_str << endl;
}