//
//  PlatesBetweenCandles.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/14/22.
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

#ifndef PlatesBetweenCandles_h
#define PlatesBetweenCandles_h

class Solution {
public:
   vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries);
   vector<int> platesBetweenCandles_sol1(string s, vector<vector<int>>& queries);
   
};
void test(const vector<string>& input_strs) {
    string s = input_strs[0].substr(1, s.length() - 1);
    vector<vector<int>> queries = ReadTwoDimIntArray(input_strs[1]);
    /*
    cout << ">>>>>>>>>>Test case: << endl;
    cout << s << endl;
    for(int i = 0; i < queries.size(); i++) {
        for(int j = 0; j < queries[i].size(); j++) {
            cout << queries[i][j] << ", ";
        }
        cout << endl;
    }
    cout << "<<<<<<<<<<<" << endl;;lp0-=
    */
    Solution sol;
    vector<int> results = sol.platesBetweenCandles(s, queries);
    for(int i = 0; i < results.size(); i++) cout << results[i] << endl;
}

vector<int> Solution::platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<int> A, res;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '|')
            A.push_back(i);
    for (int q = 0; q < queries.size(); ++q) {
        int i = lower_bound(A.begin(), A.end(), queries[q][0]) - A.begin();
        int j = upper_bound(A.begin(), A.end(), queries[q][1]) - A.begin() - 1;
        res.push_back(i < j ? (A[j] - A[i]) - (j - i) : 0);
    }
    return res;
}

vector<int> Solution::platesBetweenCandles_sol1(string s, vector<vector<int>>& queries) {
    vector<int> candles;
    unordered_map<int, int> left_candle;
    for(int i = 0; i < s.length(); i++) {
        //cout << s.at(i) << endl;
        if(s.at(i) == '|') candles.push_back(i);
        left_candle[i] = (int) candles.size() - 1;
    }
    vector<int> results;
    unordered_map<int, unordered_map<int, int>> mem;
    for(auto query: queries) {
        int start = query[0];
        int end = query[1];
        int left_idx = left_candle[start] + (s.at(start) == '*'? 1 : 0);
        int right_idx = left_candle[end];
        
        if(left_idx >= right_idx) results.push_back(0);
        else if(left_idx + 1 == right_idx) results.push_back(candles[right_idx] - candles[left_idx] - 1);
        else {
            if(mem.find(left_idx) == mem.end()) mem[left_idx] = unordered_map<int, int>{};
            else if(mem[left_idx].find(right_idx) != mem[left_idx].end()) {
                results.push_back(mem[left_idx][right_idx]);
                continue;
            }
            int i = left_idx;
            int tot = 0;
            while(i < right_idx) {
                tot += candles[i + 1] - candles[i] - 1;
                i++;
            }
            mem[left_idx][right_idx] = tot;
            results.push_back(tot);
        }
    }
    return results;
}

#endif /* PlatesBetweenCandles_h */
