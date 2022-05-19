//
//  StringsDifferByOneCharacter.h
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

#ifndef StringsDifferByOneCharacter_h
#define StringsDifferByOneCharacter_h

class Solution {
    public:
        bool differByOne_bak(vector<string>& dict);
        bool differByOne(vector<string>& dict) {
            int mod = 1000000007, n = dict.size(), m = dict[0].size();
            vector<int> hash(n);
            for (auto i = 0; i < n; ++i)
                for (auto j = 0; j < m; ++j)
                    hash[i] = (26l * hash[i] + (dict[i][j] - 'a')) % mod;
            for (int j = m - 1, mult = 1; j >= 0; --j) {
                unordered_map<int, vector<int>> m;
                for (auto i = 0; i < n; ++i) {
                    int h = (mod + hash[i] - (long)mult * (dict[i][j] - 'a') % mod) % mod;
                    auto it = m.find(h);
                    if (it != end(m))
                        for (int pi : it->second)
                            if (equal(begin(dict[i]), begin(dict[i]) + j, begin(dict[pi])) && equal(begin(dict[i]) + j + 1, end(dict[i]), begin(dict[pi]) + j + 1)) return true;
                    m[h].push_back(i);
                }
                mult = 26l * mult % mod;
            }
            return false;
        }
};

void test(const vector<string>& input_strs) {
    vector<string> dict = ReadOneDimStrArray(input_strs[0]);
   
    Solution sol;
    bool result = sol.differByOne(dict);
    cout << result << endl;
}

// This version does not work because the number can be too larget to fit any integer data type.
// Must use modulo and hash as in the solution
bool Solution::differByOne_bak(vector<string>& dict) {
    vector<long long> nums;
    for(int i = 0; i < dict.size(); i++) {
        long long num = 0;
        long long k = 1;
        for(int j = dict[i].length() - 1; j >= 0; j--) {
            num = num + (dict[i].at(j) - 'a') * k;
            k = k * 26;
        }
        nums.push_back(num);
    }
    
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            long num1 = nums[i];
            long num2 = nums[j];
            long diff = abs(nums[i] - nums[j]);
            while(diff % 26 == 0) {
                num1 = num1 / 26;
                diff = diff / 26;
                num2 = num2 / 26;
            }
            if(diff < 26 && min(num1, num2) % 26 + diff < 26) return true;
            else continue;
        }
    }
    
    return false;
}

#endif /* StringsDifferByOneCharacter_h */
