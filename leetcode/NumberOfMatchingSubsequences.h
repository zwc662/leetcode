//
//  NumberOfMatchingSubsequences.h
//  leetcode
//
//  Created by Weichao  Zhou on 4/27/22.
//  Copyright © 2022 Weichao  Zhou. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "utils.h"

using namespace std;


#ifndef NumberOfMatchingSubsequences_h
#define NumberOfMatchingSubsequences_h

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words);
};

void test(const vector<string>& input_strs) {
    string s = ReadOneStr(input_strs[0]);
    vector<string> words = ReadOneDimStrArray(input_strs[1]);
    Solution sol;
    cout << sol.numMatchingSubseq(s, words) << endl;
             
}
        
int Solution::numMatchingSubseq(string s, vector<string>& words) {
    int result = 0;
    unordered_set<string> wrong;
    unordered_set<string> right;
    for(auto word: words) {
        if(right.find(word) != right.end()) {
            result++;
            continue;
        }
        if(wrong.find(word) != wrong.end()) continue;
        
        int i = 0;
        int cur = 0;
        int last_result = result;
        while(i < s.length()) {
            if(word.at(cur) == s.at(i++)) cur++;
            if(cur == word.length()) {
                result++;
                break;
            }
        }
        if(last_result < result) right.insert(word);
        else wrong.insert(word);
    }
    return result;
}


#endif /* NumberOfMatchingSubsequences_h */
