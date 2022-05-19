//
//  FindDuplicateSubtrees.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/1/22.
//  Copyright © 2022 Weichao  Zhou. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>

#ifndef FindDuplicateSubtrees_h
#define FindDuplicateSubtrees_h

## Use

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
        string pre_order_trav(TreeNode* root);
        unordered_map<string, vector<TreeNode*>> node_map;
        vector<TreeNode*> result;
};

void test(const vector<string>& input_strs) {
    string s = ReadOneStr(input_strs[0]);
    vector<string> words = ReadOneDimStrArray(input_strs[1]);
    Solution sol;
    cout << sol.numMatchingSubseq(s, words) << endl;
}

ector<TreeNode*> Solution::findDuplicateSubtrees(TreeNode* root) {
    this->pre_order_trav(root);
    
    
    vector<TreeNode*> result;
    for (auto it = this->node_map.begin(); it != this->node_map.end(); it++)
        if (it->second.size() > 1) result.push_back(it->second[0]);
    return result;
}

string Solution::pre_order_trav(TreeNode* root) {
 
    if(!root) return "";
    // "(" and ")" are important. Two different tree may have the same serielization results.
    string s = "(" + this->pre_order_trav(root->left) + to_string(root->val) + this->pre_order_trav(root->right) + ")";
    
    this->node_map[s].push_back(root);
    return s;
}

#endif /* FindDuplicateSubtrees_h */
