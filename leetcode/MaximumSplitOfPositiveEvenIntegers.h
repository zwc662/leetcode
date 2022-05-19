//
//  MaximumSplitOfPositiveEvenIntegers.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/3/22.
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
#include "utils.h"

using namespace std;
#ifndef MaximumSplitOfPositiveEvenIntegers_h
#define MaximumSplitOfPositiveEvenIntegers_h


class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum);
    vector<long long> maximumSplit(long long finalSum);
};
#endif /* MaximumSplitOfPositiveEvenIntegers_h */


void test(const vector<string>& input_strs) {
    long long finalSum = ReadOneLongLong(input_strs[0]);
    Solution sol;
    
    vector<long long> results = sol.maximumEvenSplit(finalSum);
    for(int i = 0; i < results.size(); i++) cout << results[i] << endl;
}

vector<long long> Solution::maximumEvenSplit(long long finalSum) {
    if(finalSum % 2 != 0) return vector<long long>{};
    finalSum = finalSum / 2;
    vector<long long> result_ = this->maximumSplit(finalSum);
    vector<long long> result;
    for(int i = 0; i < result_.size(); i++) result.push_back(2 * result_[i]);
    return result;
}

vector<long long> Solution::maximumSplit(long long finalSum) {
   
    long long i = 1;
    long long sum = 0;
    vector<long long> result{};
    while(i + sum < finalSum) {
        result.push_back(i);
        sum = sum + (i++);
    }
    if(sum == finalSum) return result;
    if(sum + i == finalSum) {
        result.push_back(i);
        return result;
    }
    result[result.size() - 1] =  finalSum - sum + i - 1;
    return result;
}
