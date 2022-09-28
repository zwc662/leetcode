//
//  BinarySubarraysWithSum.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/24/22.
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

#ifndef BinarySubarraysWithSum_h
#define BinarySubarraysWithSum_h

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal);
};

void test(const vector<string>& input_strs) {
    vector<int> nums = ReadOneDimIntArray(input_strs[0]);
    int goal = ReadOneInt(input_strs[1]);
    Solution sol;
    cout << sol.numSubarraysWithSum(nums, goal) << endl;
}

int Solution::numSubarraysWithSum(vector<int>& nums, int goal) {
    deque<int> q;
        int sum = 0, head = 1, tail = 1, tot = 0;
    
        for(int i = 0; i < nums.size(); i++) {
            q.push_back(nums[i]);
            sum = sum + nums[i];
            
            if(sum == goal && nums[i] == 0) {
                tail++;
            } else if(sum == goal + 1) {
                if(goal == 0) {
                    q.clear();
                    tot = tot + tail * (tail - 1) / 2;
                    tail = 1;
                    sum = goal;
                    continue;
                }
                while(!q.empty() && q.front() != 1) {
                    q.pop_front();
                    head++;
                }
                tot = tot + head * tail;
                head = 1;
                tail = 1;
                sum = goal;
                q.pop_front();
            }
        }
        
        if(sum == goal) {
            if(goal == 0) {
                tot = tot + tail * (tail - 1) / 2;
            } else {
                while(!q.empty() && q.front() != 1) {
                    q.pop_front();
                    head++;
                }
                tot = tot + head * tail;
            }
        }
            
        return tot;
}

#endif /* BinarySubarraysWithSum_h */
