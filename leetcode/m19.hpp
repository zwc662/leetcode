//
//  m19.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/27/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
// Remove Nth Node From End of List \
Given a linked list, remove the nth node from the end of list and return its head.  \
For example,    \
Given linked list: 1->2->3->4->5, and n = 2.    \
After removing the second node from the end, the linked list becomes 1->2->3->5.

#ifndef m19_h
#define m19_h

// Definition for singly-linked list.
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
    ListNode* removeNthFromEnd_(ListNode* head, int n);
};

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    int size = 1;
    ListNode* cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
        size++;
    }
    
    if(n > size) return head;
    else if(n == size) return head->next;
    else {
        size = size - n;
        cur = head;
        while(size > 1) {
            cur = cur->next;
            size--;
        }
        if(cur->next != NULL){
            if(cur->next == NULL) return NULL;
            else if(cur->next->next != NULL)  cur->next = cur->next->next;
            else cur->next = NULL;
        }
        return head;
    }
}

ListNode* removeNthFromEnd_(ListNode* head, int n){
    ListNode* cur = head;
    ListNode* tail = new ListNode(0);
    tail->next = head;
    int len = 1;
    while(cur->next != NULL) {
        cur = cur->next;
        len++;
        if(len > n) tail = tail->next;
    }
    printf("%d\n", tail->next->val);
    if(tail->next->next != NULL) tail->next = tail->next->next;
    else tail->next = NULL;
    if(len == n) return tail->next;
    return head;
}

#endif /* m19_h */
