#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    int out_ptr, left, right;
    vector<vector<int>> triplets;

    sort(nums.begin(), nums.end()); // sorting input to search triplet
    for(int i=0; i<n-2; i++) {
        if(nums[i] > 0) continue;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        left = i+1, right = n-1;
        while(left < right) {
            long long sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                triplets.push_back({nums[i], nums[left], nums[right]});
                int leftVal = nums[left];
                int rightVal = nums[right];
                while(left < right && nums[left] == leftVal) left++;
                while(left < right && nums[right] == rightVal) right--;
            } 
            else if(sum < 0) left++;
            else right--; 
        }
    }

    return triplets;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<vector<int>> nums_prod = threeSum(arr);

    cout << "O/P = ";
    for(auto& it: nums_prod) {
        cout << "{ ";
        for(int& num : it) cout << num << " "; 
        cout << "}, ";
    }
    cout << endl;
}