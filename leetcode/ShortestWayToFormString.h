//
//  ShortestWayToFormString.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/26/22.
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

#ifndef ShortestWayToFormString_h
#define ShortestWayToFormString_h

class Solution {
public:

    int shortestWay(string source, string target);
    int shortestWay_mysol(string source, string target);
    bool isSubSequence(string str1, string str2, int m, int n, int m_, int n_);
};

void test(const vector<string>& input_strs) {
    string source = ReadOneStr(input_strs[0]);
    string target = ReadOneStr(input_strs[1]);
    Solution sol;
    cout << sol.shortestWay(source, target) << endl;
}

bool Solution::isSubSequence(string str1, string str2, int m, int n, int m_, int n_)
{
    // Base Cases
    if (m == m_ && n != n_)
        return false;
    if (n == n_)
        return true;
    // If last characters of two
    // strings are matching
    if (str1.at(m - 1) == str2.at(n - 1))
        return this->isSubSequence(str1, str2, m - 1, n - 1, m_, n_);
    // If last characters are
    // not matching
    return this->isSubSequence(str1, str2, m - 1, n, m_, n_);
}

int Solution::shortestWay_mysol(string source, string target) {
    int mem[target.size()];
    int sub[target.size()][target.size()];
    
    for(int i = 0; i < target.size(); i++)  {
        mem[i] = -1;
        for(int j = 0; j < target.size(); j++) {
            sub[i][j] = 0;
        }
    }
    if(this->isSubSequence(source, target, source.size(), target.size(), 0, target.size() - 1)) mem[target.size() - 1] = 1;
    else return -1;
    for(int i = target.size() - 2; i >= 0; i--) {
        if(target.size() - i <= source.size() && this->isSubSequence(source, target, source.size(), target.size(), 0, i)) mem[i] = 1;
        if(mem[i] != -1) continue;
        
        int tot = target.size() + 1;
        for(int j = i + 1; j < target.size() && j - i <= source.size(); j++) {
            if(sub[i + 1][j] == -1) {
                sub[i][j] = -1;
                break;
            } else if(this->isSubSequence(source, target, source.size(), j, 0, i)) {
                sub[i][j] = 1;
                if(mem[j] == -1) return -1;
                tot = min(tot, 1 + mem[j]);
            } else break;
        }
        if(tot == target.size() + 1) return -1;
        else if(tot == -1) return -1;
        else mem[i] = tot;
    }
    return mem[0];
}


int Solution::shortestWay(string s, string t) {
  auto i = 0, j = 0, res = 0;
  while (i < t.size() && res <= i) {
    while (t[i] != s[j] && j < s.size()) ++j;
    if (j == s.size()) j = 0, ++res;
    else ++i, ++j;
  }
  return res <= i ? res + 1 : -1;
}
#endif /* ShortestWayToFormString_h */
