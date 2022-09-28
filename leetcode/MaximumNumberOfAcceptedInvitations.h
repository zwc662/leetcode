//
//  MaximumNumberOfAcceptedInvitations.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/28/22.
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

#ifndef MaximumNumberOfAcceptedInvitations_h
#define MaximumNumberOfAcceptedInvitations_h

class Solution {
public:
    int maximumInvitations(vector<vector<int>>& grid);
    int recur(vector<vector<int>>& grid, vector<int> rows, vector<int> cols, int cur_row, int cur_col);
};

void test(const vector<string>& input_strs) {
    vector<vector<int>> grid = ReadTwoDimIntArray(input_strs[0]);
    Solution sol;
    cout << sol.maximumInvitations(grid) << endl;
}

int Solution::maximumInvitations(vector<vector<int>>& grid) {
    vector<int> rows, cols;
    bool flg_rows[grid.size()];
    for(int i = 0; i < grid.size(); i++) flg_rows[i] = false;
    bool flg_cols[grid[0].size()];
    for(int j = 0; j < grid[0].size(); j++) flg_cols[j] = false;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 1) {
                if(!flg_rows[i]) {
                    flg_rows[i] = true;
                    rows.push_back(i);
                }
                if(!flg_cols[j]) {
                    flg_cols[j] = true;
                    cols.push_back(j);
                }
            }
        }
    }
    return this->recur(grid, rows, cols, 0, 0);
}

int Solution::recur(vector<vector<int>>& grid, vector<int> rows, vector<int> cols, int cur_row, int cur_col) {
    int tot = 0;
    if(rows.size() == 0 || cols.size() == 0) return 0;
    for(int i = 0; i < rows.size(); i++) {
        int row = rows[i];
        if(row < cur_row) continue;
        for(int j = 0; j < cols.size(); j++) {
            int col = cols[j];
            if(row == cur_row && col < cur_col) continue;
            if(grid[row][col] == 1) {
                rows.erase(rows.begin() + i);
                cols.erase(cols.begin() + j);
                tot = max(tot, 1 + this->recur(grid, rows, cols, row, col));
                rows.insert(rows.begin() + i, row);
                cols.insert(cols.begin() + j, col);
            }
        }
    }
    return tot;
}
#endif /* MaximumNumberOfAcceptedInvitations_h */
