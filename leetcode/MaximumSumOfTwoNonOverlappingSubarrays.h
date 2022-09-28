//
//  MaximumSumOfTwoNonOverlappingSubarrays.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/15/22.
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

#ifndef MaximumSumOfTwoNonOverlappingSubarrays_h
#define MaximumSumOfTwoNonOverlappingSubarrays_h

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen);
    int helper(vector<int>& nums, int firstLen, int secondLen);
};
#endif /* MaximumSumOfTwoNonOverlappingSubarrays_h */

void test(const vector<string>& input_strs) {
    vector<int> nums = ReadOneDimIntArray(input_strs[0]);
    int firstLen = atoi(input_strs[1].c_str());
    int secondLen = atoi(input_strs[2].c_str());
    /*
    cout << ">>>>>>>>>>Test case: " << endl;
   
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    cout << firstLen << " " << secondLen << endl;
    cout << "<<<<<<<<<<<" << endl;
    */
    Solution sol;
    int result = sol.maxSumTwoNoOverlap(nums, firstLen, secondLen);
    cout << result << endl;
}


int Solution::maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    if(nums.size() == firstLen + secondLen) {
        int tot = 0;
        for(int i = 0; i < nums.size(); i++) {
            tot += nums[i];
        }
        return tot;
    }
    
    int result1 = this->helper(nums, firstLen, secondLen);
     
    int result2 = this->helper(nums, secondLen, firstLen);
    
    return max(result1, result2);
}

int Solution::helper(vector<int>& nums, int firstLen, int secondLen) {
    int firstCur = 0;
    int secondCur = 0;
    
    int firstMax = 0;
    int secondMax = 0;
    for(size_t i = nums.size() - 1; i >= 0; i--) {
     
        //cout << i << endl;
        //cout << nums[i] << endl;
        if(i > nums.size() - secondLen) secondCur = secondCur + nums[i];
        else if(i == nums.size() - secondLen) {
            secondCur = secondCur + nums[i];
            secondMax = secondCur;
        } else if(i > nums.size() - firstLen - secondLen && i < nums.size() - secondLen) {
            firstCur = firstCur + nums[i];
            continue;
        } else if(i == nums.size() - firstLen - secondLen) {
            firstCur = firstCur + nums[i];
            firstMax = firstCur + secondMax;
        } else if(i < nums.size() - firstLen - secondLen) {
            firstCur += nums[i] - nums[i + firstLen];
            secondCur += nums[i + firstLen] - nums[i + firstLen + secondLen];
            secondMax = secondMax > secondCur? secondMax : secondCur;
            firstMax = (firstMax > firstCur + secondMax)? firstMax : (firstCur + secondMax);
        }
        if(i == 0)  break;
    }
    return firstMax;
}
