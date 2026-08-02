/*
Approach: Recursion
Time Complexity: O(2^N) :: Space Complexity: O(N)

class Solution {
  private:
    bool solve(int idx, int target, vector<int>& arr) {
        if(target == 0) return true;
        
        if(idx >= arr.size() || target < 0) return false;
        
        bool take = solve(idx + 1, target - arr[idx], arr);
        bool skip = solve(idx + 1, target, arr);
        
        return (take || skip);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        return solve(0, sum, arr);
    }
};

*/
