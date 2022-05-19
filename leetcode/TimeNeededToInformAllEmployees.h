//
//  TimeNeededToInformAllEmployees.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/5/22.
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

#ifndef TimeNeededToInformAllEmployees_h
#define TimeNeededToInformAllEmployees_h

class Solution {
    public:
    int numOfMinutes_sol(int n, int headID, vector<int>& manager, vector<int>& informTime);
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime);
    int dfs(int i, vector<int>& manager, vector<int>& informTime);
};

void test(const vector<string>& input_strs) {
    int n = ReadOneInt(input_strs[0]);
    int headID = ReadOneInt(input_strs[1]);
    vector<int> manager = ReadOneDimIntArray(input_strs[2]);
    vector<int> informTime = ReadOneDimIntArray(input_strs[3]);
    Solution sol;
    int result = sol.numOfMinutes(n, headID, manager, informTime);
    cout << result << endl;
}

int Solution::numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
       {
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, dfs(i, manager, informTime));
        return res;
}

int Solution::dfs(int i, vector<int>& manager, vector<int>& informTime) {
        if (manager[i] != -1) {
            informTime[i] += dfs(manager[i], manager, informTime);
            manager[i] = -1;
        }
        return informTime[i];
    }

int Solution::numOfMinutes_sol(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<int> totalTime;
    vector<int> reach;
    vector<int> curs;
    for(int i = 0; i < n; i++) {
        reach.push_back(i);
        curs.push_back(i);
        totalTime.push_back(0);
    }
 
    int result;
    while(curs.size() > 0) {
        auto it = curs.begin();
        while(it < curs.end()) {
            int i = *it;
            if(reach[i] == -1) {
                result = max(result, totalTime[i]);
                it = curs.erase(it);
                continue;
            } else {
                totalTime[i] = totalTime[i] + informTime[reach[i]];
                reach[i] = manager[reach[i]];
                if(reach[reach[i]] == -1) {
                    reach[i] = -1;
                    totalTime[i] = totalTime[i] + totalTime[reach[i]];
                }
            }
            it++;
        }
    }
    return result;
}


#endif /* TimeNeededToInformAllEmployees_h */
