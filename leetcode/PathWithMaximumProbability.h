//
//  PathWithMaximumProbability.h
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

#ifndef PathWithMaximumProbability_h
#define PathWithMaximumProbability_h

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end);
};

void test(const vector<string>& input_strs) {
    int n = ReadOneInt(input_strs[0]);
    vector<vector<int>> edges = ReadTwoDimIntArray(input_strs[1]);
    vector<double> succProb = ReadOneDimFloatArray(input_strs[2]);
    int start = ReadOneInt(input_strs[3]);
    int end = ReadOneInt(input_strs[4]);
    
    Solution sol;
    cout << sol.maxProbability(n, edges, succProb, start, end) << endl;
}

double Solution::maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
     
    unordered_map<int, unordered_map<int, double>> edge_probs;
    double reach_probs[n];
    
    for(int i = 0; i < n; i++) reach_probs[i] = 0;
    reach_probs[start] = 1.0;
    
    for(int i = 0; i < edges.size(); i++) {
        edge_probs[edges[i][0]][edges[i][1]] = succProb[i];
        edge_probs[edges[i][1]][edges[i][0]] = succProb[i];
    }
    
    set<int> q;
    q.insert(start);
    bool diff = true;
    while(diff) {
        diff = false;
        for(auto sitr = q.begin(); sitr != q.end(); sitr++) {
            int s = *sitr;
            bool local_diff = false;
            for(auto titr = edge_probs[s].begin(); titr != edge_probs[s].end(); titr++) {
                int t = titr->first;
                if(edge_probs[s][t] != 0 && reach_probs[t] < reach_probs[s] * titr->second) {
                    reach_probs[t] = reach_probs[s] * titr->second;
                    diff = true;
                    local_diff = true;
                    q.insert(t);
                }
            }
            if(local_diff) q.erase(sitr);
        }
    }
    return reach_probs[end];
}

#endif /* PathWithMaximumProbability_h */
