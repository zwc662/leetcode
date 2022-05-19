//
//  CountWordsObtainedAfterAddingALetter.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/4/22.
//  Copyright © 2022 Weichao  Zhou. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

using namespace std;

#ifndef CountWordsObtainedAfterAddingALetter_h
#define CountWordsObtainedAfterAddingALetter_h

class Solution {
    public:
        int wordCount_sol1(vector<string>& startWords, vector<string>& targetWords);
        int wordCount_sol2(vector<string>& startWords, vector<string>& targetWords);
};

void test(const vector<string>& input_strs) {
    vector<string> startWords = ReadOneDimStrArray(input_strs[0]);
    vector<string> targetWords = ReadOneDimStrArray(input_strs[1]);
    Solution sol;
    int result = sol.wordCount_sol2(startWords, targetWords);
    cout << result << endl;
}

int Solution::wordCount_sol1(vector<string>& startWords, vector<string>& targetWords) {
    vector<int*> startNums;
    vector<int*> targetNums;
    unordered_map<int, vector<int>> containNum;
    for(int i = 0; i < targetWords.size(); i++) {
        targetNums.push_back(new int[targetWords[i].size()]);
        for(int j = 0; j < targetWords[i].size(); j++) {
            targetNums[i][j] = targetWords[i].at(j) - 'a';
            containNum[targetNums[i][j]].push_back(i);
        }
    }
    int tot = 0;
    for(int i = 0; i < startWords.size(); i++) {
        startNums.push_back(new int[startWords[i].size()]);
        vector<int> matches(startWords[i].size());
        auto start = matches.begin();
        auto end = matches.begin();
     
        for(int j = 0; j < startWords[i].size(); j++) {
            int num = startWords[i].at(j) - 'a';
            vector<int> nums_j = containNum[num];
            if(start == end) {
                start = nums_j.begin();
                end = nums_j.end();
            } else {
                if(nums_j.begin() == nums_j.end()) break;
                end = set_intersection(nums_j.begin(), nums_j.end(), start, end, start);
            }
            if(start == end) break;
            
        }
        
        if(start == end) continue;
        else {
            for(auto it = start; it < end; it++) {
                if(targetWords[*it].size() == startWords[i].size() + 1) {
                    tot++;
                    break;
                }
            }
        }
    }
    return tot;
}

int Solution::wordCount_sol2(vector<string>& startWords, vector<string>& targetWords) {
    struct Trie {
        Trie* ch[26] = {};
        bool end = false;
        void insert(string &s, int p = 0) {
            if (p < s.size()) {
                int idx = s[p] - 'a';
                if (ch[idx] == nullptr)
                    ch[idx] = new Trie();
                ch[idx]->insert(s, p + 1);
            }
            else
                end = true;
        }
        bool find(string &s, int p = 0, bool skipped = false) {
            if (p == s.size())
                return skipped && end;
            int idx = s[p] - 'a';
            return(ch[idx] != nullptr ? ch[idx]->find(s, p + 1, skipped) : false) || (skipped ? false : find(s, p + 1, true));
        }
    };
    Trie t;
    for (auto &w : startWords) {
        sort(begin(w), end(w));
        t.insert(w);
    }
    int res = 0;
    for (auto &w : targetWords) {
        sort(begin(w), end(w));
        res += t.find(w);
    }
    return res;
}

#endif /* CountWordsObtainedAfterAddingALetter_h */
