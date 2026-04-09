#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative Approach
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) return head;
    
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next_node = NULL;
    while(curr) {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
}

// Recursive Approach
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode* new_head = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}