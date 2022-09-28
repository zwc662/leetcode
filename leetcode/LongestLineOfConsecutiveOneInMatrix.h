//
//  LongestLineOfConsecutiveOneInMatrix.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/22/22.
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


#ifndef LongestLineOfConsecutiveOneInMatrix_h
#define LongestLineOfConsecutiveOneInMatrix_h

class Solution {
public:
    int longestLine(vector<vector<int>>& mat);
};

void test(const vector<string>& input_strs) {
    vector<vector<int>> mat = ReadTwoDimIntArray(input_strs[0]);
    Solution sol;
    cout << sol.longestLine(mat) << endl;
}

int Solution::longestLine(vector<vector<int>>& mat) {
    int result = 0;
    int mem[mat.size()][mat[0].size()][10];
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[i].size(); j++) {
            for(int k = 0; k < 10; k++) mem[i][j][k] = 0;
            if(mat[i][j] == 0) continue;
            
            for(int k = 0; k < 10; k++) mem[i][j][k] = 1;
            result = max(result, 1);
            for(int i_ = -1; i_ <= 0; i_++) {
                for(int j_ = -1; j_ <= 0; j_++) {
                    if(i + i_ < 0 || i + i_ > mat.size() - 1 || j + j_ < 0 || j + j_ > mat[0].size() - 1 || (i_ == 0 && j_ == 0)) continue;
                    mem[i][j][(i_ + 1) + (j_ + 1) * 3 ] = mem[i + i_][j + j_][(i_ + 1) + (j_ + 1) * 3] + 1;
                    result = max(result, mem[i][j][(i_ + 1)  + (j_ + 1) * 3]);
                }
            }
            if(i >= 1 && j < mat[i].size() - 1) mem[i][j][(- 1 + 1) + (1 + 1) * 3] = mem[i - 1][j + 1][(- 1 + 1) + (1 + 1)  * 3] + 1;
            result = max(result, mem[i][j][(-1 + 1) + (1 + 1) * 3]);
        }
    }
    return result;
}

#endif /* LongestLineOfConsecutiveOneInMatrix_h */
