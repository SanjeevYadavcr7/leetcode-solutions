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
    ListNode* mergeTwoLists(ListNode* curr1, ListNode* curr2) {
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        
        while(curr1 && curr2) {
            if(curr1->val <= curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }

        curr->next = curr1 ? curr1 : curr2;
        return dummy.next;
    }

    ListNode* merge(int beg, int end, vector<ListNode*>& lists) {
        if(beg == end) return lists[beg];

        int mid = beg + (end - beg) / 2;
        ListNode* head1 = merge(beg, mid, lists);
        ListNode* head2 = merge(mid+1, end, lists);
        ListNode* new_head = mergeTwoLists(head1, head2);
        return new_head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        int n = lists.size();
        ListNode* new_head = merge(0, n-1, lists);
        return new_head;
    }
};
