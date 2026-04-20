class Solution {
public:
    int traverseTree(TreeNode* root, int &max_diameter) {
        if(!root) return 0;

        int leftTreeHeight = traverseTree(root->left, max_diameter);
        int rightTreeHeight = traverseTree(root->right, max_diameter);
        max_diameter = max(max_diameter, leftTreeHeight + rightTreeHeight);
        return 1 + max(leftTreeHeight, rightTreeHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        traverseTree(root, max_diameter);
        return max_diameter;
    }
};
