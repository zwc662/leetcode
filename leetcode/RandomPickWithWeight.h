//
//  RandomPickWithWeight.h
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
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

using namespace std;

#ifndef RandomPickWithWeight_h
#define RandomPickWithWeight_h

class Solution {
    private:
        int sum;
        vector<int> probs;
    public:
        Solution(vector<int>& w) ;
        int pickIndex();
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
void test(const vector<string>& input_strs) {
    vector<string> cmds = ReadOneDimStrArray(input_strs[0]);
    vector<vector<int>> args = ReadTwoDimIntArray(input_strs[1]);
    Solution sol(args[0]);
    int result = sol.pickIndex();
    cout << result << endl;
}

Solution::Solution(vector<int>& w) {
    for (auto n : w)    this->probs.push_back(n + (this->probs.empty()? 0 : this->probs.back()));
}

int Solution::pickIndex() {
    // generate a random number in the range of [0, 1]
    float randNum = (float) rand() / RAND_MAX;
    float target =  randNum * this->probs.back();
    // run a linear search to find the target zone
    for (int i = 0; i < this->probs.size(); ++i)
        if (target < this->probs[i])
            return i;
    return this->probs.size() - 1;
}


#endif /* RandomPickWithWeight_h */
