//
//  BinaryTreesWithFactors.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/22/22.
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

#ifndef BinaryTreesWithFactors_h
#define BinaryTreesWithFactors_h
class Solution {
public:
    unordered_map<int, vector<vector<int>>> parents;
    unordered_map<int, int> cnts;
    int modulo(long num) {
        return (int) (num % (int) (pow(10., 9.) + 7.));
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> poses;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i; j > 0; j--) {
                if(arr[j] < arr[j - 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                } else break;
            }
        }
        for(int i = 0; i < arr.size(); i++) poses[arr[i]] = i;

        for(int i = 0; i < arr.size(); i++) {
            for(int j = i; j < arr.size(); j++) {
                if(((long) arr[i] * arr[j]) > ((long) arr[arr.size() - 1])) continue;
                int prod = this->modulo(arr[i] * arr[j]);
                if(poses.find(prod) != poses.end()) {
                    if(this->parents.find(prod) == this->parents.end()) this->parents[prod] = vector<vector<int>>();
                    this->parents[prod].push_back(vector<int>{arr[i], arr[j]});
                }
            }
        }
        int res = 0;
        for(int i = 0; i < arr.size(); i++) {
            this->cnts[arr[i]] = this->modulo(this->count(arr[i]));
            res = this->modulo(res + this->cnts[arr[i]]);
        }
        return res;
    }
        
    int count(int parent) {
        if(this->cnts.find(parent) != this->cnts.end()) return this->cnts[parent];
        int tot = 1;
        if(this->parents.find(parent) == this->parents.end()) return tot;
        for(int i = 0; i < this->parents[parent].size(); i++) {
            int left = this->parents[parent][i][0];
            int right = this->parents[parent][i][1];
            if(left == right) tot = this->modulo(tot + this->modulo(((long) this->count(left)) * ((long) this->count(right))));
            else tot = this->modulo(tot + this->modulo(this->modulo(((long) this->count(left)) * ((long) this->count(right))) * 2));
        }
        return tot;
    }
};
void test(const vector<string>& input_strs) {
    vector<int> arr = ReadOneDimIntArray(input_strs[0]);
    Solution sol = Solution();
    cout << sol.numFactoredBinaryTrees(arr) << endl;
}
#endif /* BinaryTreesWithFactors_h */
