
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void serializdString(TreeNode* root, ostringstream& out) {
        if(!root) {
            out << "# ";
            return;
        } 

        out << root->val << " ";
        serializdString(root->left, out);
        serializdString(root->right, out);
    }
    
    string serialize(TreeNode* root) {
        ostringstream out;
        serializdString(root, out);
        string data = out.str();
        cout << "Data = " << data;
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserializeData(istringstream& in) {
        string val;
        in >> val;
        if(val == "#") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeData(in);
        root->right = deserializeData(in);
        return root;
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeData(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
