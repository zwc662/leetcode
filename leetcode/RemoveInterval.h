//
//  RemoveInterval.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/14/22.
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

#ifndef RemoveInterval_h
#define RemoveInterval_h

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved);
};

void test(const vector<string>& input_strs) {
    vector<vector<int>> intervals = ReadTwoDimIntArray(input_strs[0]);
    vector<int> toBeRemoved = ReadOneDimIntArray(input_strs[1]);
    Solution sol;
    vector<vector<int>> result = sol.removeInterval(intervals, toBeRemoved);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i][0] << ", " << result[i][1] << endl;
    }
}

vector<vector<int>> Solution::removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
    vector<vector<int>> result;
    for(int i = 0; i < intervals.size(); i++) {
        int left = intervals[i][0];
        int right = intervals[i][1];
        if(left >= toBeRemoved[1] || right <= toBeRemoved[0]) result.push_back(intervals[i]);
        else if(left < toBeRemoved[0] && right > toBeRemoved[1]) {
            result.push_back(vector<int>{left, toBeRemoved[0]});
            result.push_back(vector<int>{toBeRemoved[1], right});
        }
        else if(left >= toBeRemoved[0] && right <= toBeRemoved[1]) continue;
        else if(left < toBeRemoved[0]) result.push_back(vector<int>{left, toBeRemoved[0]});
        else if(right > toBeRemoved[1]) result.push_back(vector<int>{toBeRemoved[1], right});
        else result.push_back(intervals[i]);
    }
    return result;
}

#endif /* RemoveInterval_h */
