//
//  RemoveAllOnesWithRowAndColumnFlips.h
//  leetcode
//
//  Created by Weichao  Zhou on 4/20/22.
//  Copyright © 2022 Weichao  Zhou. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
  
#ifndef RemoveAllOnesWithRowAndColumnFlips_h
#define RemoveAllOnesWithRowAndColumnFlips_h

using namespace std;

class Solution {
    public:
        bool removeOnes(vector<vector<int>>& grid);
};

void test(const vector<string>& input_strs) {
            vector<vector<int>> grid;
            vector<int> grid_i;
            for(size_t i = 1; i < input_strs[0].length() - 1; i++) {
                if(input_strs[0].at(i) == ']') grid.push_back(grid_i);
                else if(input_strs[0].at(i) == '[') grid_i.clear();
                else if(input_strs[0].at(i) == ',') continue;
                else grid_i.push_back(input_strs[0].at(i) - '0');
            }
            //for(auto i: grid) {
            //    for(int j: i) cout << j << " ";
            //    cout << endl;
            //}
            Solution sol;
            cout << sol.removeOnes(grid) << endl;
        }
        
bool Solution::removeOnes(vector<vector<int>>& grid) {
    vector<int> row = grid[0];
    for(auto row_i = grid.begin() + 1; row_i != grid.end(); row_i++) {
        // if rev is true, then row and row_i is supposed to be opposite
        bool rev = row[0]^(*row_i)[0];
        
        for(int j = 1; j < row.size(); j++) {
            // if row[0] and (*row)[0] are opposite (rev is true), but row[j] and (*row_i)[j] are the same, or
            // if row[0] and (*row)[0] are the same (rev is false), but row[j] and (*row_i)[j] are opposite, then the removeOnes return false;
            // in other words, (row[0]^(*row)[0]) should be the same as (row[j]^(*row_i)[j]), otherwise removeOnes return false;
            if(rev^(row[j]^(*row_i)[j])) return false;
        }
    }
    return true;
}
#endif /* RemoveAllOnesWithRowAndColumnFlips_h */



