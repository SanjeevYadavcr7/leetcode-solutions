class Solution {
public:
    // Helper function returns height if balanced, or -1 if unbalanced
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int leftH = checkHeight(node->left);
        if (leftH == -1) return -1; // If left height is -1, that means left tree is unbalanced

        int rightH = checkHeight(node->right);
        if (rightH == -1) return -1; // If right height is -1, that means right tree is unbalanced

        // Current node check
        if (abs(leftH - rightH) > 1) return -1;

        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
