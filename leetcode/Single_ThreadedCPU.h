//
//  Single_ThreadedCPU.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/7/22.
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

#ifndef Single_ThreadedCPU_h
#define Single_ThreadedCPU_h

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks);
    static bool compare(vector<int> task1, vector<int> task2);
};

void test(const vector<string>& input_strs) {
    vector<vector<int>> tasks = ReadTwoDimIntArray(input_strs[0]);
    Solution sol;
    vector<int> result = sol.getOrder(tasks);
    for(int i = 0; i < result.size(); i++) cout << result[i] << endl;
}

bool Solution::compare(vector<int> task1, vector<int> task2) {
    if(task1[0] > task2[0]) return true;
    else if(task1[0] == task2[0]) {
        if(task1[1] > task2[1]) return true;
        else if(task1[1] == task2[1]) {
            if(task1[2] > task2[2]) return true;
        }
    }
    return false;
}


vector<int> Solution::getOrder(vector<vector<int>>& tasks) {
    //priority_queue<vector<int>, vector<vector<int>>, std::function<bool(vector<int>, vector<int>)>> enqueueq(Solution::compare);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> enqueueq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> taskq;
    vector<int> result;
    for(int i = 0; i < tasks.size(); i++) {
        enqueueq.push(vector<int>{tasks[i][0], tasks[i][1], i});
    }
    
    int cur_time = 0;
    int free_time = 0;
    for(int i = 0; i < tasks.size(); i++) {
        vector<int> cur_task = enqueueq.top();
        int cur_time = cur_task[0];
        int cur_id = cur_task[2];
        int cur_duration = cur_task[1];
        enqueueq.pop();
        
        if(taskq.empty() && free_time <= cur_time) free_time = cur_time;
        
        taskq.push(pair<int, int>{cur_duration, cur_id});
            
        while(free_time <= cur_time) {
            pair<int, int> task = taskq.top();
            taskq.pop();
            result.push_back(task.second);
            free_time = free_time + task.first;
        }
    }
    while(!taskq.empty()) {
        result.push_back(taskq.top().second);
        taskq.pop();
    }
    return result;
}

#endif /* Single_ThreadedCPU_h */
