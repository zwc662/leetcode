//
//  e83.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/28/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//  83. Remove Duplicates from Sorted List
//  Given a sorted linked list, delete all duplicates such that each element appear only once.
//  For example,
//  Given 1->1->2, return 1->2.
//  Given 1->1->2->3->3, return 1->2->3.

#ifndef e83_h
#define e83_h
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* cur = head;
        while(cur->next != NULL) {
            while(cur->next->val == cur->val) {
                cur->next = cur->next->next;
                if(cur->next == NULL) return head;
            }
            if(cur->next != NULL) cur = cur->next;
        }
        return head;
    }
    
    ListNode* deleteDuplicates_(ListNode* head) {
        if(head == NULL) return head;
        ListNode* cur = head;
        if(cur->next == NULL) return head;
        while(cur->next->next != NULL) {
            if(cur->next->val == cur->val) {
                cur->next = cur->next->next;
                continue;
            }
            cur = cur->next;
        }
        if(cur->next->val == cur->val) cur->next = NULL;
        return head;
    }
};


#endif /* e83_h */
