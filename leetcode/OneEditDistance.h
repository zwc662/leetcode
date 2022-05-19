//
//  OneEditDistance.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/18/22.
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

#ifndef OneEditDistance_h
#define OneEditDistance_h

class Solution {
public:
    bool isOneEditDistance(string s, string t);
};

void test(const vector<string>& input_strs) {
    string s = ReadOneStr(input_strs[0]);
    string t = ReadOneStr(input_strs[1]);
    Solution sol;
    cout << sol.isOneEditDistance(s, t) << endl;
}

bool Solution::isOneEditDistance(string s, string t) {
        if(s.size() == t.size()) {
            if(s.size() == 0) return false;
            bool result = false;
            for(int i = 0; i < s.size(); i++) {
                if(!result && (s.at(i) != t.at(i))) result = true;
                else if(result && (s.at(i) != t.at(i))) return false;
            }
            return result;
        }
    
    if(abs((long) (s.size() - t.size())) > 1) return false;
    if(s.size() == 0 || t.size() == 0) return true;
    bool flg = false;
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(j == t.size() && !flg) return true;
        else if(s.at(i) != t.at(j) && !flg) {
            if(s.size() < t.size() && j < t.size() - 1 && s.at(i) == t.at(j + 1)) {
                flg = true;
                j = j + 2;
            } else if(s.size() > t.size() && i < s.size() - 1 && s.at(i + 1) == t.at(j)) {
                flg = true;
            } else return false;
        } else if(s.at(i) == t.at(j)) j++;
        else return false;
    }
    return true;
}
    
 


#endif /* OneEditDistance_h */
