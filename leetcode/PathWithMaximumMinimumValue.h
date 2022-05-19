//
//  PathWithMaximumMinimumValue.h
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

#ifndef PathWithMaximumMinimumValue_h
#define PathWithMaximumMinimumValue_h

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid);
};

void test(const vector<string>& input_strs) {
    vector<vector<int>> grid = ReadTwoDimIntArray(input_strs[0]);
    Solution sol;
    int result = sol.maximumMinimumPath(grid);
    cout << result << endl;
}

int Solution::maximumMinimumPath(vector<vector<int>>& grid) {
    int mem[grid.size()][grid[0].size()];
    for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++)
            mem[i][j] = -1;
    mem[grid.size() - 1][grid[0].size() - 1] = grid[grid.size() - 1][grid[0].size() - 1];
    queue<int> queue;
    queue.push((grid.size() - 1) * grid[0].size() + grid[0].size() - 1);
    while(!queue.empty()) {
        int pos = queue.front();
        queue.pop();
        int x = pos / grid[0].size();
        int y = pos % grid[0].size();
        if(x > 0) {
            int x_ = x - 1;
            if(mem[x_][y] == -1) {
                mem[x_][y] = min(grid[x_][y], mem[x][y]);
                queue.push(x_ * grid[0].size() + y);
            } else if(mem[x_][y] < mem[x][y]) {
                mem[x_][y] = min(grid[x_][y], mem[x][y]);
                queue.push(x_ * grid[0].size() + y);
            }
            
        }
        
        if(x < grid.size() - 1) {
            int x_ = x + 1;
            if(mem[x_][y] == -1) {
                mem[x_][y] = min(grid[x_][y], mem[x][y]);
                queue.push(x_ * grid[0].size() + y);
            } else if(mem[x_][y] < mem[x][y]) {
                mem[x_][y] = min(grid[x_][y], mem[x][y]);
                queue.push(x_ * grid[0].size() + y);
            }
            
        }
        if(y > 0) {
            int y_ = y - 1;
            if(mem[x][y_] == -1) {
                mem[x][y_] = min(grid[x][y_], mem[x][y]);
                queue.push(x * grid[0].size() + y_);
            } else if(mem[x][y_] < mem[x][y]) {
                mem[x][y_] = min(grid[x][y_], mem[x][y]);
                queue.push(x * grid[0].size() + y_);
            }
            
        }
        if(y < grid[0].size() - 1) {
            int y_ = y + 1;
            if(mem[x][y_] == -1) {
                mem[x][y_] = min(grid[x][y_], mem[x][y]);
                queue.push(x * grid[0].size() + y_);
            } else if(mem[x][y_] < mem[x][y]) {
                mem[x][y_] = min(grid[x][y_], mem[x][y]);
                queue.push(x * grid[0].size() + y_);
            }
            
        }
    }
    return mem[0][0];
}


#endif /* PathWithMaximumMinimumValue_h */
