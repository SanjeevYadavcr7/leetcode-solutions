class Solution {
public:
    void traverseTree(TreeNode* root, int& goodNodes, int maxValue) {
        if(!root) return;

        if(root->val >= maxValue) goodNodes++;
        maxValue = max(maxValue, root->val);
        traverseTree(root->left, goodNodes, maxValue);
        traverseTree(root->right, goodNodes, maxValue);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        int goodNodes = 0;
        traverseTree(root, goodNodes, root->val);
        return goodNodes;
    }
};
