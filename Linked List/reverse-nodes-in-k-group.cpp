
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
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = NULL;
        ListNode* curr = node;
        ListNode* next_node = NULL;

        while(curr) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* new_head = NULL; // stores new head of linked list
        ListNode* prev_node = NULL; 
        while(curr) {
            ListNode* node = curr;
            ListNode* prev_head = curr;
            for(int i = 1; i < k && curr != NULL; i++) {
                curr = curr->next;
            }
            if(curr == NULL) break; // move K-1 positions and separate the list 
            
            ListNode* next_node = curr->next;
            curr->next = NULL;
            ListNode* rev_head = reverseList(node); // reverse left part list
            if(!new_head) {
                new_head = rev_head;
            }
            prev_head->next = next_node; // join the list
            if(prev_node) {
                prev_node->next = rev_head;
            }
            prev_node = prev_head;
            curr = next_node; // move curr pointer to starting of right part list
        }
        return new_head;
    }
};
