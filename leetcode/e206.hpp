//
//  e206.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/28/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//  206. Reverse Linked List
//  Reverse a singly linked list.   A linked list can be reversed either iteratively or recursively. Could you implement both?

#ifndef e206_h
#define e206_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head);
    ListNode* reverseList_(ListNode* head);
};

ListNode* Solution::reverseList_(ListNode* head) {
    if(head == NULL) return head;
    ListNode* cur = head;
    ListNode* cur_ = cur->next;
    cur->next = NULL;
    while(cur_ != NULL) {
        ListNode* temp = cur_->next;
        cur_->next = cur;
        cur = cur_;
        cur_ = temp;
    }
    head = cur;
    return head;
}
ListNode* Solution::reverseList(ListNode* head) {
    if(head == NULL) return head;
    if(head->next == NULL) return head;
    else {
        ListNode* head_ = Solution::reverseList(head->next);
        ListNode* cur = head_;
        while(cur->next != NULL) cur = cur->next;
        cur->next = head;
        head->next = NULL;
        head = head_;
        return head;
    }
}
#endif /* e206_h */
