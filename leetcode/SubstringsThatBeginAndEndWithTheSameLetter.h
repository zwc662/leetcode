//
//  SubstringsThatBeginAndEndWithTheSameLetter.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/28/22.
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

#ifndef SubstringsThatBeginAndEndWithTheSameLetter_h
#define SubstringsThatBeginAndEndWithTheSameLetter_h

class Solution {
public:
    unordered_map<long long, long long> combs;
    long long comb(long long diff);
    long long numberOfSubstrings(string s);
};

void test(const vector<string>& input_strs) {
    string s = ReadOneStr(input_strs[0]);
    Solution sol;
    cout << sol.numberOfSubstrings(s) << endl;
}

long long Solution::comb(long long diff) {
    if(diff == 0) return 1;
    if(this->combs.find(diff) != this->combs.end()) return this->combs[diff];
    long long tot = 0;
    long long tot_last = diff;
    for(long long i = 1; i < diff; i++) {
        tot = tot + tot_last;
        tot_last = tot_last * (diff - i) / (i + 1);
    }
    this->combs[diff] = tot;
    return tot;
}


long long Solution::numberOfSubstrings(string s) {
    long long tot = 0;
    unordered_map<int, vector<long long>> locs;
    for(long long i = 0; i < s.size(); i++) {
        tot++;
        int cur = s.at(i) - 'a';
        if(locs.find(cur) == locs.end()) locs[cur] = vector<long long>{i};
        else locs[cur].push_back(i);
    }
    
    for(int i = 0; i < 26; i++) {
        if(locs.find(i) == locs.end()) continue;
        for(long long j = 0; j < locs[i].size() - 1; j++) {
            for(long long k = j + 1; k < locs[i].size(); k++) {
                long long diff = locs[i][k] - locs[i][j] - 1;
                tot += 1; //this->comb(diff);
            }
        }
    }
    return tot;
}

#endif /* SubstringsThatBeginAndEndWithTheSameLetter_h */
