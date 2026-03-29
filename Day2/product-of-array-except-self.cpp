#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int right_prod;
    vector<int> nums_prod(n,1);

    for(int i=1; i<n; i++) {
        nums_prod[i] = nums_prod[i-1] * nums[i-1];
    }

    right_prod = nums[n-1];
    for(int i=n-2; i>=0; i--) {
        nums_prod[i] = nums_prod[i] * right_prod;
        right_prod *= nums[i];
    }

    return nums_prod;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> nums_prod = productExceptSelf(arr);

    cout << "O/P = ";
    for(int& num : nums_prod) cout << num << " "; 
    cout << endl;
}