/*
Approach 1: Use map to store and create new pointers 
Time: O(N) :: Space: O(N)
*/
Node* copyRandomList(Node* head) {
    if(!head) return head;

    unordered_map<Node*, Node*> nodeMap;
    Node *node = head;
    
    while(node) {
        nodeMap[node] = new Node(node->val);
        node = node->next;
    }

    node = head;
    while(node) {
        Node *currNode = nodeMap[node];
        currNode->next = nodeMap[node->next];
        currNode->random = nodeMap[node->random];
        node = node->next;
    }

    return nodeMap[head];
}

/*
Approach 2: Add cloned pointer in original list. No EXTRA space needed
Time: O(N) :: Space: O(1)
*/
