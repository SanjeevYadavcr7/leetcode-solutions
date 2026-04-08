#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(n <= 1) return n;

    int left = 0, right = 1;
    int max_len = 0;
    unordered_map<char, int> char_idx_map;
    
    char_idx_map[s[0]] = 0;
    while(left < right && right < n) {
        char ch = s[right];
        if(char_idx_map.find(ch) != char_idx_map.end()) {
            max_len = max(max_len, right - left);
            cout << left << ", " << right << ", " << max_len << endl;
            left = char_idx_map[ch] + 1;
        } 
        char_idx_map[ch] = right;
        right++;
    }
    if(right == n) max_len = max(max_len, right-left);
    return max_len;
}

int main() {
    string str;
    cin >> str;

    int max_len = lengthOfLongestSubstring(str);
    cout << "Len = " << max_len << endl;
}