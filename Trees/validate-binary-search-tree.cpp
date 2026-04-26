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
    // In-order traversal solution
    bool traverseAndCheckBST(TreeNode* root, TreeNode*& prev) {
        if(!root) return true;

        if(!traverseAndCheckBST(root->left, prev)) return false;
        if(prev && root->val <= prev->val) return false;
        prev = root;
        return traverseAndCheckBST(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        TreeNode* prev = nullptr;
        return traverseAndCheckBST(root, prev);
    }



    // Range based solution
    // bool isSubTreeBST(TreeNode* root, long long minVal, long long maxVal) {
    //     if(!root) return true;

    //     return (root->val > minVal && root->val < maxVal)
    //            && isSubTreeBST(root->left, minVal, root->val) 
    //            && isSubTreeBST(root->right, root->val, maxVal);
    // }

    // bool isValidBST(TreeNode* root) {
    //     return isSubTreeBST(root, LONG_MIN, LONG_MAX);
    // }
};
