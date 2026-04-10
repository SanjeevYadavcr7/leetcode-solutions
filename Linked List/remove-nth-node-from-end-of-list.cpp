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
