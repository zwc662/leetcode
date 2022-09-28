//
//  PacificAtlanticWaterFlow.h
//  leetcode
//
//  Created by Weichao  Zhou on 6/6/22.
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

#ifndef PacificAtlanticWaterFlow_h
#define PacificAtlanticWaterFlow_h

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);
    void bfs(bool** visited, vector<vector<int>>& heights, deque<vector<int>> q);
};

void test(const vector<string>& input_strs) {
    vector<vector<int>> heights = ReadTwoDimIntArray(input_strs[0]);
    Solution sol;
    vector<vector<int>> res = sol.pacificAtlantic(heights);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
        cout << endl;
    }
}

void Solution::bfs(bool** visited, vector<vector<int>>& heights, deque<vector<int>> q) {
    while(!q.empty()) {
        vector<int> pos = q.front();
        q.pop_front();
        int x = pos[0];
        int y = pos[1];
        visited[x][y] = true;
        if(x - 1 >= 0 && !visited[x - 1][y] && heights[x - 1][y] >= heights[x][y]) q.push_back(vector<int>{x - 1, y});
        if(x + 1 < heights.size() && !visited[x + 1][y] && heights[x + 1][y] >= heights[x][y]) q.push_back(vector<int>{x + 1, y});
        if(y - 1 >= 0 && !visited[x][y - 1] && heights[x][y - 1] >= heights[x][y]) q.push_back(vector<int>{x, y - 1});
        if(y + 1 < heights[x].size() && !visited[x][y + 1] && heights[x][y + 1] >= heights[x][y]) q.push_back(vector<int>{x, y + 1});
    }
}

vector<vector<int>> Solution::pacificAtlantic(vector<vector<int>>& heights) {
    deque<vector<int>> pac, atl;
    bool **pac_visited;
    bool **atl_visited;
    pac_visited = new bool*[heights.size()];
    atl_visited = new bool*[heights.size()];
    for(int i = 0; i < heights.size(); i++) {
        pac_visited[i] = new bool[heights[i].size()];
        atl_visited[i] = new bool[heights[i].size()];
        for(int j = 0; j < heights[i].size(); j++) {
            pac_visited[i][j] = false;
            atl_visited[i][j] = false;
        }
    }
    
    for(int i = 0; i < heights[0].size(); i++) {
        pac.push_back(vector<int>{i, 0});
        atl.push_back(vector<int>{i, (int) heights[0].size() - 1});

    }
    for(int i = 0; i < heights.size(); i++) {
        pac.push_back(vector<int>{0, i});
        atl.push_back(vector<int>{(int) heights.size() - 1, i});
    }
    
    this->bfs(pac_visited, heights, pac);
    this->bfs(atl_visited, heights, atl);
    
    vector<vector<int>> res;
    for(int i = 0; i < heights.size(); i++) {
        for(int j = 0; j < heights[0].size(); j++) {
            if(pac_visited[i][j] && atl_visited[i][j]) res.push_back(vector<int>{i, j});
        }
    }
    return res;
}

#endif /* PacificAtlanticWaterFlow_h */
