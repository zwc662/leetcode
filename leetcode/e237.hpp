//
//  e237.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/28/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//  237. Delete Node in a Linked List
//  Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//  Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

#ifndef e237_h
#define e237_h
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

#endif /* e237_h */
