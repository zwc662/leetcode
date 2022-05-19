//
//  SatisfiabilityOfEqualityEquations.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/19/22.
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

#ifndef SatisfiabilityOfEqualityEquations_h
#define SatisfiabilityOfEqualityEquations_h

class Solution {
public:
    bool equationsPossible(vector<string>& equations);
    bool bfs(bool connected[26][26], int v1, int v2);
};

void test(const vector<string>& input_strs) {
    vector<string> equations = ReadOneDimStrArray(input_strs[0]);
    Solution sol;
    cout << sol.equationsPossible(equations) << endl;
}

bool Solution::equationsPossible(vector<string>& equations) {
    bool connected[26][26];
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            connected[i][j] = false;
        }
    }
    for(int i = 0; i < equations.size(); i++) {
        string equation = equations[i];
        if(equation.at(1) == '=') {
            int v1 = equation.at(0) - 'a';
            int v2 = equation.at(3) - 'a';
            connected[v1][v2] = true;
            connected[v2][v1] = true;
        }
    }
    
    for(int i = 0; i < equations.size(); i++) {
        string equation = equations[i];
        if(equation.at(1) == '=') continue;
        int v1 = equation.at(0) - 'a';
        int v2 = equation.at(3) - 'a';
        
        if(this->bfs(connected, v1, v2)) return false;
    }
    
    return true;
}

bool Solution::bfs(bool connected[26][26], int v1, int v2) {
    deque<int> q;
    bool visited[26];
    q.push_back(v1);
    visited[v1] = true;
    while(!q.empty()) {
        int i = q.front();
        q.pop_front();
        for(int j = 0; j < 26; j++) {
            if(connected[i][j] & !visited[j]) {
                if(j == v2) return true;
                q.push_back(j);
                visited[j] = true;
            }
        }
    }
    return false;
}
#endif /* SatisfiabilityOfEqualityEquations_h */
