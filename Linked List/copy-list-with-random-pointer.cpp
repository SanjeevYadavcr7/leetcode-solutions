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
Node* copyRandomList(Node* head) {
    if(!head) return head;

    Node* curr = head;

    // Adding new cloned pointer
    while(curr) {
        Node* new_node = new Node(curr->val);
        new_node->next = curr->next;
        curr->next = new_node;
        curr = new_node->next;
    }

    // Attaching random pointer to cloned nodes
    curr = head;
    while(curr) {
        curr->next->random = curr->random ? curr->random->next : NULL;
        curr = curr->next->next;
    }

    // Attaching next pointer to cloned nodes
    curr = head;
    Node dummy(-1);
    Node* copyCurr = &dummy;
    while(curr) {
        Node* copy = curr->next;

        // Restore old list
        curr->next = copy->next;
        curr = curr->next;

        // Restore new list
        copyCurr->next = copy;
        copyCurr = copy;
    }
   
    return dummy.next;
}
