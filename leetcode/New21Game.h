//
//  New21Game.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/25/22.
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

#ifndef New21Game_h
#define New21Game_h

class Solution {
public:
    double new21Game(int n, int k, int maxPts);
    double recur(int pts, int maxPts);
    vector<int> odds;
};

void test(const vector<string>& input_strs) {
    int n = ReadOneInt(input_strs[0]);
    int k = ReadOneInt(input_strs[1]);
    int maxPts = ReadOneInt(input_strs[2]);
    Solution sol;
    cout << sol.new21Game(n, k, maxPts) << endl;
}

 double Solution::new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double Wsum = 1.0, res = 0.0;
        // dp[i] is the probability of getting a total i
        // Wsum = dp[i - 1] + dp[i - 2] + ... + dp[i - W] or dp[0] if i < W
        // from each of dp[i - 1] ... dp[i - W], one needs to get point 1, 2, ..., W respectively to obtain an i,
        // the probabilities are the same for each of 1, 2, ..., W, i.e. 1/W
        // dp[i] = prob(1) * dp[i - 1] + prob(2) * dp[i - 2] + ... + prob(W) * dp[i - W]
        for (int i = 1; i <= N; ++i) {
            dp[i] = 1. / W * Wsum;
            if (i < K) Wsum += dp[i]; else res += dp[i];
            if (i - W >= 0) Wsum -= dp[i - W];
        }
        return res;
    }

#endif /* New21Game_h */
