#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
using customPair = pair<int, int>;

/*
Time: O(N + MLogM) | Space: O(N)
*/
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq_map;
    vector<customPair> freq_nums;
    vector<int> top_k_freq_nums;

    for(int& num : nums) freq_map[num]++; // O(N)
    for(auto& i: freq_map) freq_nums.push_back({i.second, i.first}); // O(M) => M: unique elements
    
    sort(freq_nums.begin(), freq_nums.end()); // O(M.LogM)
    
    int n = freq_nums.size();
    for(int i=n-1; i>n-1-k; i--) {
        top_k_freq_nums.push_back(freq_nums[i].second);
    }
    return top_k_freq_nums;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> top_k_freq_nums = topKFrequent(arr, k);

    cout << "O/P = ";
    for(int& num : top_k_freq_nums) cout << num << " "; 
    cout << endl;
}