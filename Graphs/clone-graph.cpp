/*
  Time: O(V + E)  ->  Standard BFS
*/

class Solution {
    // unordered_map<Node*, Node*>
    // Ideally we should use node pointer
    // Why? This prevents program from failing when nodes do not have unique values.
    unordered_map<int, Node*> nodesMap;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(nodesMap.find(node->val) != nodesMap.end()) return nodesMap[node->val];

        Node* copyNode = new Node(node->val);
        nodesMap[node->val] = copyNode;
        
        for(Node* nbrNode : node->neighbors) {
            copyNode->neighbors.push_back(cloneGraph(nbrNode));
        }

        return copyNode;
    }
};



/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
