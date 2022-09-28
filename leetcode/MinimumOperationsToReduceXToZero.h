//
//  MinimumOperationsToReduceXToZero.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/20/22.
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

#ifndef MinimumOperationsToReduceXToZero_h
#define MinimumOperationsToReduceXToZero_h

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        int n = nums.size();
        int maxi = -1;
        int left = 0;
        int current = 0;

        for (int right = 0; right < n; right++) {
            // sum([left ,..., right]) = total - x
            current += nums[right];
            // if larger, move `left` to left
            while (current > total - x && left <= right) {
                current -= nums[left];
                left += 1;
            }
            // check if equal
            if (current == total - x) {
                maxi = max(maxi, right - left + 1);
            }
        }
        return maxi != -1 ? n - maxi : -1;
    }
};

void test(const vector<string>& input_strs) {
    vector<int> nums = ReadOneDimIntArray(input_strs[0]);
    int x = ReadOneInt(input_strs[1]);
    Solution sol = Solution();
    cout << sol.minOperations(nums, x) << endl;
}


#endif /* MinimumOperationsToReduceXToZero_h */


 
