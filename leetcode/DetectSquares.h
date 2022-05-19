//
//  DetectSquares.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/13/22.
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

#ifndef DetectSquares_h
#define DetectSquares_h

class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> row_map;
    unordered_map<int, unordered_map<int, int>> col_map;
    DetectSquares() {
        this->row_map;
        this->col_map;
    };
    
    void add(vector<int> point) {
        int row = point[0];
        int col = point[1];
        this->row_map[row][col] = this->row_map[row][col] + 1;
        this->col_map[col][row] = this->col_map[col][row] + 1;
 
    }
    
    int count(vector<int> point) {
        int row = point[0];
        int col = point[1];
        int tot = 0;
        //unordered_map<int, unordered_map<int, bool>> visited;
        for(auto i = this->col_map[col].begin(); i != this->col_map[col].end(); i++) {
            for(auto j = this->row_map[row].begin(); j != this->row_map[row].end(); j++) {
                int row_ = i->first;
                int col_ = j->first;
                if(row_ == row || col == col_) continue;
                if(abs(row_ - row) != abs(col_ - col)) continue;
                //if(!visited[row_][col_]) {
                //    visited[row_][col_] = true;
                tot = tot + i->second * this->row_map[row_][col_] * j->second;
                //} else continue;
            }
        }
        return tot;
    }
};

void test(const vector<string>& input_strs) {
    DetectSquares sol = DetectSquares();
    sol.add(vector<int>{5, 10});
    sol.add(vector<int>{10, 5});
    sol.add(vector<int>{10, 10});
    
 
    sol.add(vector<int>{3, 0});
    sol.add(vector<int>{8, 0});
    sol.add(vector<int>{8, 5});
    
 
    sol.add(vector<int>{9, 0});
    sol.add(vector<int>{9, 8});
    sol.add(vector<int>{1, 8});
    
    sol.add(vector<int>{0, 0});
    sol.add(vector<int>{8, 0});
    sol.add(vector<int>{8, 8});
    
    cout << "hehe" << endl;
    cout << sol.count(vector<int>{0, 8}) << endl;
 
}
 
#endif /* DetectSquares_h */
