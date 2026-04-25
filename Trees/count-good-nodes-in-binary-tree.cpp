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
    // void traverseTree(TreeNode* root, int& goodNodes, int maxValue) {
    //     if(!root) return;

    //     if(root->val >= maxValue) goodNodes++;
    //     maxValue = max(maxValue, root->val);
    //     traverseTree(root->left, goodNodes, maxValue);
    //     traverseTree(root->right, goodNodes, maxValue);
    // }

    int getGoodNodes(TreeNode* root, int maxValue) {
        if(!root) return 0;

        maxValue = max(maxValue, root->val);
        return (root->val >= maxValue) + getGoodNodes(root->left, maxValue) + getGoodNodes(root->right, maxValue);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return getGoodNodes(root, root->val);
    }
};
