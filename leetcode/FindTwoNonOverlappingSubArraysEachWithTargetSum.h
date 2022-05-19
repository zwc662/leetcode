//
//  FindTwoNonOverlappingSubArraysEachWithTargetSum .h
//  leetcode
//
//  Created by Weichao  Zhou on 5/8/22.
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

#ifndef FindTwoNonOverlappingSubArraysEachWithTargetSum__h
#define FindTwoNonOverlappingSubArraysEachWithTargetSum__h

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target);
    int minSumOfLengths_myans(vector<int>& arr, int target);
};

void test(const vector<string>& input_strs) {
    vector<int> arr = ReadOneDimIntArray(input_strs[0]);
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << endl;
    int target = ReadOneInt(input_strs[1]);
    Solution sol;
    int result = sol.minSumOfLengths(arr, target);
    cout << result << endl;
}

 
int Solution::minSumOfLengths(vector<int>& arr, int target) {
/*
I would like to provide a more General solution here:

Denote dp[i][j] as:
We are only using arr[1,2,...,i], and we have found j non-overlapping sub-arrays with target sum. The value of dp[i][j] is the minimum sum of the lengths of two of the sub-arrays.

Then we have the equation:

 
dp[i][j] = min(dp[i-1][j], dp[d][j-1] + i - d)
The d here is the index satisfying sum(arr[i-d+1,...,i]) = target. This sub-array has length = i-d.
Explanation:

dp[i][j] <= dp[i-1][j]:
This is because, we are considering more elements than before, hence the result can only be better (the length is smaller).
dp[d][j-1] + i - d:

To ensure the sub-arrays don't overlap, the rest of the sub-arrays must use index <= d, hence this is why we use dp[d][j-1] here.
To quickly find such d, use a unordered_map to keep track of the prefix sum.
In the code:
Notice that we are using index from 1 to n, hence we can easily use index 0 to prevent extra checking.
Also notice that we are initializing dp[i][0] = 0, because if we can't find any subarray, the sum of length must be 0.

Then, the answer is given bydp[n][j]. In this problem,j = 2.
 */
 
        int dp[100005][3];  //if asking for n subarrays, change 3 to n+1
        unordered_map<int,int> sm;  // keep track of (prefixsum : index)
        
        int n = arr.size(), cursum = 0;
        sm[0] = 0;
        memset(dp, 127, sizeof(dp));  //initialize to INF
        for (int i = 0; i < 100005; i++) dp[i][0] = 0;  //if we doesn't find a subarray, len = 0
        
        for (int i = 1; i <= n; i++) {
            int d = -1;  //initialize to -1
            cursum += arr[i-1];
            sm[cursum] = i;
            if (sm.count(cursum - target)) d = sm[cursum-target];
            // cursum is the current sum of arr[0,1,...,i-1]
            // sum[j] stores the current sums of each j
            // find the index d s.t. sum[d] = cursum - target
            // so that arr[d+1,d+2,...,i-1] sum up to target
            // if arr contains negative numbers, d can be a set of indices
            
            for (int j = 1; j <= 2; j++) {  // if asking for n subarrays, change 2 to n
                dp[i][j] = min(dp[i][j], dp[i-1][j]);  //dp[i][j] must <= dp[i-1][j]
                if (d != -1) dp[i][j] = min(dp[i][j],dp[d][j-1] + i - d);
            }
        }
        if (dp[n][2] > 1e9) return -1;   // if asking for n subarrays, change 2 to n
        return dp[n][2];   // if asking for n subarrays, change 2 to n
    }
 

int Solution::minSumOfLengths_myans(vector<int>& arr, int target) {
    int starts[arr.size()];
    int ends[arr.size()];
    int end = 1;
    int start = 0;
    int lens[arr.size()];
    
    while(start < arr.size()) {
        if(arr[start] == target) {
            lens[start] = 1;
            start++; end++;
        }
        else if(arr[start] > target) {
            start++;
            end++;
        }
        else {
            int sum = arr[start];
            end = start + 1;
            while(end <= arr.size()) {
                if(end == arr.size()) {
                    break;
                }
                if(arr[end] > target) {
                    start = end++;
                    break;
                }
                sum = sum + arr[end++];
                while(sum >= target) {
                    if(sum == target) {
                        lens[start] = end - start;
                    }
                    sum = sum - arr[start++];
                    continue;
                }
            }
        }
    }
    int result = arr.size();
    int mem_1[arr.size()];
    int mem_2[arr.size()];
    for(int i = arr.size(); i >= 0; i--) {
        if(lens[i] > 0) {
            if(mem_1[i + 1] > 0) mem_1[i] = min(mem_1[i + 1], lens[i]);
            else {
                mem_1[i] = lens[i];
                continue;
            }
            int j = i + lens[i];
            if(j < arr.size() && mem_1[j] > 0) {
                if(mem_2[i + 1] > 0) mem_2[i] = min(mem_2[i + 1], lens[i] + mem_1[j]);
                else mem_2[i] = lens[i] + mem_1[j];
            }
        } else {
            mem_1[i] = mem_1[i + 1];
            mem_2[i] = mem_2[i + 2];
        }
        result = min(result, mem_2[i]);
    }
    
    
    return result;
}

#endif /* FindTwoNonOverlappingSubArraysEachWithTargetSum__h */
