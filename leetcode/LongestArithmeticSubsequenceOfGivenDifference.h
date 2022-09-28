//
//  LongestArithmeticSubsequenceOfGivenDifference.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/3/22.
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
#ifndef LongestArithmeticSubsequenceOfGivenDifference_h
#define LongestArithmeticSubsequenceOfGivenDifference_h


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference);
};
#endif /* LongestArithmeticSubsequenceOfGivenDifference_h */

void test(const vector<string>& input_strs) {
    vector<int> arr = ReadOneDimIntArray(input_strs[0]);
    int difference = ReadOneInt(input_strs[1]);
    Solution sol;
    cout << sol.longestSubsequence(arr, difference) << endl;
}

int Solution::longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int, int> max_lens;
    int result = 1;
    for(auto it = arr.end() - 1; it >= arr.begin(); it--) {
        if(max_lens.find(*it + difference) == max_lens.end()) {
            max_lens[*it] = 1;
        } else {
            max_lens[*it] = max_lens[*it + difference] + 1;
            result = max_lens[*it] > result? max_lens[*it] : result;
        }
    }
    return result;
}
