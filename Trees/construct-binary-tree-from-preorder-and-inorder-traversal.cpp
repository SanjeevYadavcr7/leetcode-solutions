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
    // Time: O(N)  |  Space: O(N)
    TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>& inorderMap, int& idx, int start, int end) {
        if(idx >= preorder.size() || start > end) return NULL;
        
        int rootVal = preorder[idx++];
        int midVal = inorderMap[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTreeHelper(preorder, inorderMap, idx, start, midVal-1);
        root->right = buildTreeHelper(preorder, inorderMap, idx, midVal+1, end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;

        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        int idx = 0;
        return buildTreeHelper(preorder, inorderMap, idx, 0, preorder.size()-1);
    }
};
