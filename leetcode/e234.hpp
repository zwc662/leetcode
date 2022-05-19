//
//  e234.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/28/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//  234. Palindrome Linked List
//  Given a singly linked list, determine if it is a palindrome.
//  Follow up:
//  Could you do it in O(n) time and O(1) space?

#ifndef e234_h
#define e234_h
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true;
        if(head->next->next == NULL) {
            if(head->val != head->next->val) return false;
            else return true;
        }
        int len = 1;
        ListNode* cur = head;
        ListNode* mid = head;
        while(cur->next != NULL) {
            if(len%2 == 1) mid = mid->next;
            cur = cur->next;
            len++;
        }
        if(len%2 == 1) {
            mid->val = mid->next->val;
            mid->next = mid->next->next;
        }
        
        cur = mid;
        ListNode* cur_ = cur->next;
        cur->next = NULL;
        while(cur_ != NULL) {
            ListNode* temp = cur_->next;
            cur_->next = cur;
            cur = cur_;
            cur_ = temp;
        }
        cur_ = head;
        while(cur->next != NULL) {
            if(cur_->val != cur->val) return false;
            else {
                cur = cur->next;
                cur_ = cur_->next;
            }
        }
        if(cur_->val == cur->val) return true;
        else return false;
    }
};

#endif /* e234_h */
