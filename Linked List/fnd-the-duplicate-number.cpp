#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int slow = nums[0], fast = nums[0];
    while(true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow == fast) break;
    }

    slow = nums[0];
    int slow2 = fast;
    while(slow != 0 && slow != slow2) {
        slow = nums[slow];
        slow2 = nums[slow2];
    }
    return slow;
}

int main() {
    vector<int> arr = {3,1,3,4,2};
    int dup_num = findDuplicate(arr);
    cout << "Duplicate = " << dup_num << endl;
    return 0;
}