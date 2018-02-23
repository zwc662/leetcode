//
//  m2_addtwonumbers.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/8/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#ifndef m2_addtwonumbers_h
#define m2_addtwonumbers_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i = 0;
        ListNode* head = new ListNode(i);
        ListNode* l = head;
        while(l1 != NULL || l2 != NULL) {
            int x_1 = (l1 == NULL? 0 : l1->val);
            int x_2 = (l2 == NULL? 0 : l2->val);
            int o = x_1 + x_2 + i;
            
            l->next = new ListNode(o % 10);
            l = l->next;
            i = o/10;
            
            l1 = (l1 == NULL? NULL : l1->next);
            l2 = (l2 == NULL? NULL : l2->next);
        }
        if(i > 0) l->next = new ListNode(i);
        return head->next;
    }
    
    void test() {
        ListNode l1 = ListNode(2);
        ListNode l1_ = ListNode(4); l1.next = &l1_;
        ListNode l1__ = ListNode(3); l1_.next = &l1__;
        l1__.next = NULL;
        
        ListNode l2 = ListNode(5);
        ListNode l2_ = ListNode(6); l2.next = &l2_;
        ListNode l2__ = ListNode(4); l2_.next = &l2__;
        l2__.next = NULL;
        
        ListNode* l3 = addTwoNumbers(&l1, &l2);
        std::cout<< "print l3 " << l3->val << std::endl;
        while(l3 != NULL) {
            std::cout<< "l3 is not NULL" << std::endl;
            std::cout<< l3->val << std::endl;
            l3 = l3->next;
            //if(l3 == NULL) std::cout<< "l3 is NULL" << std::endl;
        }
        
    }
};
#endif /* m2_addtwonumbers_h */
