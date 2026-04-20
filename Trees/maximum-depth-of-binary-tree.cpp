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
    /*
        Talking about complexity.
        When using DFS : Time = O(N) and Space = O(N)
        When using BFS : Time = O(N) and Space = O(W)
        where N is the maximum number of nodes and W is maximum number of nodes at a level
    */
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int leftTreeHeight = maxDepth(root->left);
        int rightTreeHeight = maxDepth(root->right);
        int depth = 1 + max(leftTreeHeight, rightTreeHeight);
        return depth;
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while(!q.empty()) {
            int size = q.size(); 
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};