//
//  SortList.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/23/22.
//  Copyright © 2022 Weichao  Zhou. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

using namespace std;
#ifndef SortList_h
#define SortList_h
/**
 * Definition for singly-linked list.
**/
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        if(head->next->next == nullptr) {
            if(head->val > head->next->val) {
                int tmp = head->next->val;
                head->next->val = head->val;
                head->val = tmp;
            }
            return head;
        }
 
        ListNode* cur = head;
        int length = 0;
        while(cur != nullptr) {
            length++;
            cur = cur->next;
        }
        cur = head;
        for(int i = 0; i < length / 2; i++) {
            cur = cur->next;
        }
        ListNode* head_ = cur->next;
        cur->next = nullptr;
        head = this->sortList(head);
        head_ = this->sortList(head_);
        
        ListNode* true_head;
        if(head == nullptr) true_head = head_;
        else if(head_ == nullptr) true_head = head;
        else if(head->val <= head_->val) {
            true_head = new ListNode(head->val);
            head = head->next;
        } else {
            true_head = new ListNode(head_->val);
            head_ = head_->next;
        }
        cur = true_head;
        while(head != nullptr && head_ != nullptr) {
            if(head->val <= head_->val) {
                cur->next = new ListNode(head->val);
                head = head->next;
            } else {
                cur->next = new ListNode(head_->val);
                head_ = head_->next;
            }
            cur = cur->next;
        }
        if(head == nullptr) cur->next = head_;
        else cur->next = head;
        return true_head;
    }
    
};

void test(const vector<string>& input_strs) {
    vector<int> arr = ReadOneDimIntArray(input_strs[0]);
    ListNode* head = new ListNode();
    ListNode* cur = head;
    for(int i = 0; i < arr.size(); i++) {
        cur->val = arr[i];
        if(i == arr.size() - 1) cur->next = nullptr;
        else cur->next = new ListNode();
        cur = cur->next;
    }
    
    Solution sol = Solution();
    ListNode* res = sol.sortList(head);
    while(res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }
}
#endif /* SortList_h */
