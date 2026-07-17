class Solution {
public:
    int climbStairs(int n) {
        int ways[n + 1];

        ways[0] = 1, ways[1] = 1;  // Base Case

        for(int i = 2; i <= n; i++) {       // Overlapping Subproblems
            ways[i] = ways[i - 1] + ways[i - 2];  // Optimal Structure
        }

        return ways[n];
    }
};