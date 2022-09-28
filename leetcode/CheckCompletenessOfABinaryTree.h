//
//  CheckCompletenessOfABinaryTree.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/15/22.
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
#ifndef CheckCompletenessOfABinaryTree_h
#define CheckCompletenessOfABinaryTree_h

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
    TreeNode* BuildTree(vector<int> tree);
    bool isCompleteTree(TreeNode* root);
};

void test(const vector<string>& input_strs) {
    vector<int> tree = ReadOneDimIntArray(input_strs[0]);
    
    /*
    cout << ">>>>>>>>>>Test case: " << endl;
   
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    cout << firstLen << " " << secondLen << endl;
    cout << "<<<<<<<<<<<" << endl;
    */
    Solution sol;
    TreeNode* root = sol.BuildTree(tree);
    
    cout << sol. isCompleteTree(root) << endl;
}
#endif /* CheckCompletenessOfABinaryTree_h */

TreeNode* Solution::BuildTree(vector<int> tree) {
    queue<TreeNode*> q;
    TreeNode root = TreeNode(tree[0]);
    q.push(&root);
    for(int i = 1; i < tree.size(); i++) {
        if(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            cur = new TreeNode(tree[i]);
            //cout << i << " " << cur << endl;
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return &root;
    
}

bool Solution::isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
 
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if(cur->left == nullptr) {
            if(cur->right != nullptr) return false;
            else break;
        } else q.push(cur->left);
        if(cur->right == nullptr) break;
        else q.push(cur->right);
    }
    
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if(cur->left != nullptr) return false;
        if(cur->right != nullptr) return false;
    }
        
    return true;
}
