#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

void printInput(vector<string>& strs) {
    cout << "I/P = ";
    for(string str : strs) cout << str << " "; 
    cout << endl;
}

/*
  Time: O(N.KLogK) | Space: O(N)
*/
// vector<vector<string>> generateGrpAnagrams(vector<string>& strs) {
//     vector<vector<string>> grp_angrms;
//     unordered_map<string, vector<string>> str_mp;
//     for(string str : strs) {
//         string key = str;
//         sort(key.begin(), key.end());
//         str_mp[key].push_back(str);
//     }
    
//     for(auto pair : str_mp) grp_angrms.push_back(pair.second);
//     return grp_angrms;
// }

/*
  Time: O(N.K) | Space: O(N)
*/
string getKey(string str) {
    string key = "";
    vector<int> str_freq(26, 0);
    
    for(char& ch : str) str_freq[ch - 'a']++;

    for(int i=0; i<26; i++) {
        key += to_string(str_freq[i]) + "#";
    }
    return key;
}

vector<vector<string>> generateGrpAnagrams(vector<string>& strs) {
    vector<vector<string>> grp_angrms;
    unordered_map<string, vector<string>> str_mp;
    
    for(string &str : strs) {
        string key = getKey(str);
        cout << "Key = " << key << "\n";
        str_mp[key].push_back(str);
    }

    for(auto pair : str_mp) grp_angrms.push_back(pair.second);
    return grp_angrms;
}

int main() {
    // vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<string> strs = {"bdddddddddd","bbbbbbbbbbc"};
    printInput(strs);

    vector<vector<string>> grpd_agrms = generateGrpAnagrams(strs);
    cout << "O/P = ";
    for(vector<string> str_vec : grpd_agrms) {
        for(string str : str_vec) cout << str << " ";
        cout << "| ";
    }
    cout << endl;
}