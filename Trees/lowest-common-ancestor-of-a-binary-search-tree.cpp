/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Iterative Approach : Time = O(H)  Space = O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(root->val > p->val && root->val > q->val) root = root->left;
            else if(root->val < p->val && root->val < q->val) root = root->right;
            else return root;
        }
        return nullptr;
    }

    // Recursive Approach : Time = O(H)  Space = O(H)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } 
        else if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } 
        return root;
    }
};
