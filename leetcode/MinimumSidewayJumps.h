//
//  MinimumSidewayJumps.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/17/22.
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
#ifndef MinimumSidewayJumps_h
#define MinimumSidewayJumps_h

class Solution {
public:
    int minSideJumps(vector<int>& obstacles);
};

void test(const vector<string>& input_strs) {
    vector<int> obstacles = ReadOneDimIntArray(input_strs[0]);
    for(auto ob: obstacles) {
        cout << ob << endl;
    }
    Solution sol;
    int result = sol.minSideJumps(obstacles);
    cout << result << endl;
}


#endif /* MinimumSidewayJumps_h */

int Solution::minSideJumps(vector<int>& obstacles) {
    vector<int> last_mem;
    for(int i = 0; i < obstacles.size(); i++) {
        if(i== 0) {
            last_mem = vector<int>{1, 0, 1};
        } else {
            vector<int> cur_mem{0, 0, 0};
            cur_mem[0] = obstacles[i] == 1? -2 : (last_mem[0] < 0? -1 : last_mem[0]);
            cur_mem[1] = obstacles[i] == 2? -2 : (last_mem[1] < 0? -1 : last_mem[1]);
            cur_mem[2] = obstacles[i] == 3? -2 : (last_mem[2] < 0? -1 : last_mem[2]);
            for(int j = 0; j < 3; j++) {
                for(int k = j + 1; k < 3; k++) {
                    if(cur_mem[j] < 0 && cur_mem[k] < 0) continue;
                    if(cur_mem[j] == -2 || cur_mem[k] == -2) continue;
                    if(cur_mem[j] == -1) cur_mem[j] = cur_mem[k] + 1;
                    else if(cur_mem[k] == -1) cur_mem[k] = cur_mem[j] + 1;
                    else {
                        cur_mem[k] = min(cur_mem[j] + 1, cur_mem[k]);
                        cur_mem[j] = min(cur_mem[j], cur_mem[k] + 1);
                    }
                }
            }
            last_mem = vector<int>{cur_mem[0], cur_mem[1], cur_mem[2]};
        }
        
    }
    int res = -1;
    for(int i = 0; i < 3; i++) res = min(res >= 0? res : last_mem[i],  last_mem[i] >= 0? last_mem[i] : res);

    
    return res;
}
