/*
    In this problem, we can use upper bound instead of writing binary search,
    because upper bound internally uses binary search to find the element
*/


#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

using timeStampValuePair = pair<int, string>;
class TimeMap {
public:
    unordered_map<string, vector<timeStampValuePair>> timeMap;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value}); // O(1)
    }
    
    string get(string key, int timestamp) {
        if(timeMap.find(key) == timeMap.end()) return "";  // if key is not present

        auto& v = timeMap[key]; // taken reference to avoid copying the vector all together
        auto it = upper_bound(v.begin(), v.end(), timestamp, [](int t, const timeStampValuePair& pair){
            return t < pair.first;
        });

        if(it == v.begin()) return "";

        return prev(it)->second;
    }
};