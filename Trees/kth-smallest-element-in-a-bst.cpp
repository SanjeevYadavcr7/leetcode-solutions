class Solution {
public:
    int getKthSmallest(TreeNode* root, int& k) {
        if(!root) return -1;

        int smallest_node = getKthSmallest(root->left, k);
        if(smallest_node != -1) return smallest_node;
        k--;
        if(k == 0) return root->val;
        
        return getKthSmallest(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        return getKthSmallest(root, k);
    }
};
