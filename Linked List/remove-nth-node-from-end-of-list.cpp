/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || (!head->next && n == 1)) return NULL;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *left = dummy;
        ListNode *right = dummy;
        
        // move right pointer N+1 step;
        for(int i = 0; i < n+1 && right != NULL; i++) {
            right = right->next;
        }
        // if right is NULL, that means head pointer is going to be deleted
        if(!right) {
            head = head->next;
            return head;
        }

        while(right != NULL) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return head;
    }
};


// This problem can be solved in 3 ways(Time = O(N)) : 

// 1. Store all nodes in a vector and directly access Nth code and remove it  // Space = O(N)
// 2. Find list length, then find L-N node  // Space = O(1) + Take Two-pass
// 3. Move right pointer by N position, then move left pointer until right is NULL  // Space = O(1) + Single Pass 

// Proof: 

// Let, size of list  =  L

// Keep right and left at a node which points to head.
// ```

// -1   ->  1  ->  2  ->  3  ->  4  ->  /0
//         head
// ```

// ```
// If we move, right by N+1 position then right will be at N.
// Now, total distance remainig L-N

// So, now move left and right together until right = NULL.

// This means right will move more L-N,
// which means Left will move by L-N from beginning which is exactly one position before the node we want to delete.
// ```
