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
    // BFS :: Time = O(N) | Space = O(W)
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> rightMostNodes;
    //     if(!root) return rightMostNodes;

    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()) {
    //         int size = q.size();
    //         for(int i = 0; i < size; i++) {
    //             TreeNode* node = q.front();
    //             q.pop();
    //             if(node->left) q.push(node->left);
    //             if(node->right) q.push(node->right);
    //             if(i == size - 1) rightMostNodes.push_back(node->val);
    //         }
    //     }
    //     return rightMostNodes;
    // }

    // DFS :: Time: O(N) | Space: O(N)
    void traverseTree(TreeNode* root, int &level, vector<int>& result) {
        if(!root) return;
        if(level > result.size()) result.push_back(root->val);

        level++;
        if(root->right) traverseTree(root->right, level , result);
        if(root->left) traverseTree(root->left, level, result);
        level--;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightMostNodes;
        if(!root) return rightMostNodes;
        
        int level = 1;
        traverseTree(root, level, rightMostNodes);
        return rightMostNodes;
    }
};
