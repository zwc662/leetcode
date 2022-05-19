//
//  e203.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/28/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//203. Remove Linked List Elements
//     Remove all elements from a linked list of integers that have value val.
//     Example
//     Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//     Return: 1 --> 2 --> 3 --> 4 --> 5
//     Credits:
//     Special thanks to @mithmatt for adding this problem and creating all test cases.

#ifndef e203_h
#define e203_h
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL) {
            if(head->val == val) {
                head = head->next;
                continue;
            }
            ListNode* cur = head;
            while(cur->next != NULL) {
                if(cur->next->val == val) cur->next = cur->next->next;
                else cur = cur->next;
            }
            return head;
        }
        return head;
    }
};
#endif /* e203_h */
