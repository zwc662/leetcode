//
//  ProcessTasksUsingServers.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/6/22.
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
#include <queue>

using namespace std;
#ifndef ProcessTasksUsingServers_h
#define ProcessTasksUsingServers_h

class Solution {
public:
    static bool Compare(pair<int, int> server1, pair<int, int> server2);
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks);
    vector<int> assignTasks_sol(vector<int>& servers, vector<int>& tasks);
};

void test(const vector<string>& input_strs) {
    vector<int> servers = ReadOneDimIntArray(input_strs[0]);
    vector<int> tasks = ReadOneDimIntArray(input_strs[1]);
    Solution sol;
    vector<int> result = sol.assignTasks(servers, tasks);
    for(int i = 0; i < result.size(); i++) cout << result[i] << endl;
}

bool Solution::Compare(pair<int, int> server1, pair<int, int> server2) {
    if(server1.second > server2.second) return true;
    else if(server1.second == server2.second) {
        if(server1.first > server2.first) return true;
    }
    return false;
}

 

vector<int> Solution::assignTasks(vector<int>& servers, vector<int>& tasks) {
    int time = 0;
    vector<int> result;
    int task = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> serverq(Solution::Compare);
    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> timeq(Solution::Compare);
    
    for(int i = 0; i < servers.size(); i++) {
        serverq.push(pair<int, int>{i, servers[i]});
    }
    while(true) {
        if(timeq.size() > 0) time = max(time, task);
        while(!timeq.empty() && timeq.top().second <= time) {
            pair<int, int> server_time = timeq.top();
            timeq.pop();
            serverq.push(pair<int, int>{server_time.first, servers[server_time.first]});
        }
        
        pair<int, int> server = serverq.top();
        serverq.pop();
        timeq.push(pair<int, int>{server.first, time + tasks[task++]});
        result.push_back(server.first);
        
        if(result.size() == tasks.size()) break;
    }
    return result;
}

vector<int> Solution::assignTasks_sol(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        // store {weight, server_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_server_pq;
        // store {end_time, server_index}, use long instead of int because the time maybe overflow
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> busy_server_pq;
        vector<int> ans(m);
        
        for (int i = 0; i < n; ++i) {
            free_server_pq.push({servers[i], i});
        }
        
        long time = 0;
        for (int i = 0; i < m; ++i) {
            time = max(static_cast<long>(i), time);
            if (free_server_pq.empty() && busy_server_pq.top().first > time) {
                time = busy_server_pq.top().first;
            }
            
            while (!busy_server_pq.empty() && busy_server_pq.top().first == time) {
                auto &info = busy_server_pq.top();
                int server_idx = static_cast<int>(info.second);
                free_server_pq.push({servers[server_idx], server_idx});
                busy_server_pq.pop();
            }
            
            auto &info = free_server_pq.top();
            busy_server_pq.push({time + tasks[i], info.second});
            ans[i] = info.second;
            free_server_pq.pop();
        }
        
        return ans;
    }

#endif /* ProcessTasksUsingServers_h */
