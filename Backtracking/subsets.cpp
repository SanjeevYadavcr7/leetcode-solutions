// class Solution {
// public:
//     // Approach 1:
//     void generateSubsets(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& result) {
//         if(idx == nums.size()) return;

//         temp.push_back(nums[idx]);
//         result.push_back(temp);
//         for(int i = idx + 1; i < nums.size(); i++) {
//             generateSubsets(nums, i, temp, result);
//         }
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> result = {{}};
//         for(int i = 0; i < nums.size(); i++) {
//             vector<int> temp;
//             generateSubsets(nums, i, temp, result);
//         }
//         return result;
//     }


//     // Approach 2:
//     void generateSubsets(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& result) {
//         if(idx == nums.size()) {
//             result.push_back(subset);
//             return;
//         }

//         // Decision 1: Pick the current element
//         subset.push_back(nums[idx]);
//         generateSubsets(nums, idx+1, subset, result);

//         // BACKTRACK: Undo the decision before exploring the other branch
//         subset.pop_back();

//         // Decision 2: Do NOT pick the current element
//         generateSubsets(nums, idx+1, subset, result);
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> result;
//         vector<int> subset;
//         generateSubsets(nums, 0, subset, result);
//         return result;
//     }
// };

#include<iostream>
using namespace std;

void generateSubsets(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& result) {
    result.push_back(subset);

    for(int i = idx; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        generateSubsets(nums, i+1, subset, result);
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset = {};
    generateSubsets(nums, 0, subset, result);
    return result;    
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);
    for(auto it : result) {
        for(int num : it) {
            cout << num << " ";
        }
        cout << endl;
    }
}
