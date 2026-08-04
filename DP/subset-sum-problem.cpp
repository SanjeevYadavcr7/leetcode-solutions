/*
Approach: Memoization

class Solution {
  private:
    bool solve(int idx, int target, vector<vector<int>>& memo, vector<int>& arr) {
        if(target == 0) return true;
        
        if(idx >= arr.size() || target < 0) return false;
        
        if(memo[idx][target] != -1) return memo[idx][target];
        
        bool take = solve(idx + 1, target - arr[idx], memo, arr);
        bool skip = solve(idx + 1, target, memo, arr);
        
        return memo[idx][target] = (take || skip);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
        
        return solve(0, sum, memo, arr);
    }
};
*/

/* --------------------------------------------------------------------------------
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
