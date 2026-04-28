
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // Time: O(N) | Space: O(H)
    int maxPathSumHelper(TreeNode* root, int& maxSum) {
        if(!root) return 0;

        int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
        int rightSum = max(0, maxPathSumHelper(root->right, maxSum));

        int currNodeSum = root->val + leftSum + rightSum;
        maxSum = max(currNodeSum, maxSum);

        return root->val + max(leftSum, rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;

        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }
};
