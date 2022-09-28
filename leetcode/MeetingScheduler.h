//
//  MeetingScheduler.h
//  leetcode
//
//  Created by Weichao  Zhou on 6/3/22.
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

#ifndef MeetingScheduler_h
#define MeetingScheduler_h

bool compareInterval(vector<int> i1, vector<int> i2)
{
    return (i1[0] < i2[0]);
}

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration);
};

void test(const vector<string>& input_strs) {
    vector<vector<int>> slots1 = ReadTwoDimIntArray(input_strs[0]);
    vector<vector<int>> slots2 = ReadTwoDimIntArray(input_strs[1]);
    int duration = ReadOneInt(input_strs[2]);
    
    Solution sol;
    vector<int> res = sol.minAvailableDuration(slots1, slots2, duration);
    for(int i = 0; i < res.size(); i++) cout << res[i] << endl;
}

vector<int> Solution::minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
    int idx1 = 0, idx2 = 0;
    sort(slots1.begin(), slots1.end(), compareInterval);
    sort(slots2.begin(), slots2.end(), compareInterval);
    while(idx1 < slots1.size() && idx2 < slots2.size()) {
        vector<int> slot1 = slots1[idx1];
        vector<int> slot2 = slots2[idx2];
        if(slot1[0] >= slot2[1]) idx2++;
        else if(slot1[1] <= slot2[0]) idx1++;
        else if(slot1[0] <= slot2[0] && slot1[1] >= slot2[1]) {
            if(slot2[1] - slot2[0] >= duration) return vector<int>{slot2[0], slot2[0] + duration};
            else idx2++;
        } else if(slot2[0] <= slot1[0] && slot2[1] >= slot1[1]) {
            if(slot1[1] - slot1[0] >= duration) return vector<int>{slot1[0], slot1[0] + duration};
            else idx1++;
        } else if(min(slot1[1], slot2[1]) - max(slot2[0], slot1[0]) >= duration) {
            cout << min(slot1[1], slot2[1]) - max(slot2[0], slot1[0]) << endl;
            return vector<int>{max(slot2[0], slot1[0]), max(slot2[0], slot1[0]) + duration};
        }   else if(slot1[1] <= slot2[1]) idx1++;
        else idx2++;
    }
    return vector<int>{};
    
}
#endif /* MeetingScheduler_h */
