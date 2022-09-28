//
//  NumberOfGoodWaysToSplitAString.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/30/22.
//  Copyright © 2022 Wei∑∑∑chao  Zhou. All rights reserved.
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

#ifndef NumberOfGoodWaysToSplitAString_h
#define NumberOfGoodWaysToSplitAString_h

class Solution {
public:
    int numSplits(string s);
};

void test(const vector<string>& input_strs) {
    string s = ReadOneStr(input_strs[0]);
    Solution sol;
    cout << sol.numSplits(s) << endl;
}

int Solution::numSplits(string s) {
    int lefts[26];
    int rights[26];
    int left_right = 0, tot = 0;
    for(int i = 0; i < 26; i++) {
        lefts[i] = 0;
        rights[i] = 0;
    }
    for(int i = 0; i < s.size(); i++) {
        rights[s.at(i) - 'a']++;
        if(rights[s.at(i) - 'a'] == 1) left_right--;
    }
    
    for(int i = 0; i < s.size(); i++) {
        char cur = s.at(i);
        lefts[cur - 'a']++;
        rights[cur - 'a']--;
        
        if(lefts[cur - 'a'] == 1 && rights[cur - 'a'] > 0) left_right++;
        else if(lefts[cur - 'a'] == 1 && rights[cur - 'a'] == 0) left_right += 2;
        else if(lefts[cur - 'a'] > 1 && rights[cur - 'a'] == 0) left_right++;
        if(left_right == 0) tot++;
    }
    return tot;
}


#endif /* NumberOfGoodWaysToSplitAString_h */
