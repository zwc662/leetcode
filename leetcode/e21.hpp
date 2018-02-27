//
//  e21.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/27/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//21. Merge Two Sorted Lists
//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//Example:
//Input: 1->2->4, 1->3->4
//Output: 1->1->2->3->4->4


#ifndef e21_h
#define e21_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        ListNode *head = new ListNode(l1->val < l2->val? l1->val : l2->val);
        if(head->val == l1->val) l1 = l1->next;
        else l2 = l2->next;
        ListNode *cur = head;
        while(l1 != NULL && l2 != NULL) {
            cur->next = new ListNode(l1->val < l2->val? l1->val : l2->val);
            if(cur->next->val == l1->val) l1 = l1->next;
            else l2 = l2->next;
            cur = cur->next;
        }
        if(l1 == NULL) cur->next = l2;
        else cur->next = l1;
        return head;
    }
};
#endif /* e21_h */
