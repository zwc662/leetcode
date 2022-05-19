//
//  RaceCar.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/11/22.
//  Copyright © 2022 Weichao  Zhou. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

using namespace std;

#ifndef RaceCar_h
#define RaceCar_h

class Solution {
    public:
        int racecar(long long target);
};

void test(const vector<string>& input_strs) {
    int target = ReadOneInt(input_strs[0]);
    Solution sol;
    long long result = sol.racecar(target);
    cout << result << endl;
}

int Solution::racecar(long long target) {
    queue<pair<long long,long long>> q;
    unordered_map<long long, unordered_map<long long, int>> mem;
    
    q.push(pair<long long, long long>{0, 1});
    mem[0][1] = 0;
    while(!q.empty()) {
        pair<long long, long long> cur = q.front();
        q.pop();
        long long pos = cur.first;
        long long vel = cur.second;
        int num = mem[pos][vel];
        // instr == 'A'
        long long pos_A = pos + vel;
        if(pos_A == target) return num + 1;
        long long vel_A = vel * 2;
        pair<long long, long long> nxt_A = {pos_A, vel_A};
        if(mem.find(pos_A) == mem.end()) {
            mem[pos_A][vel_A] = num + 1;
            q.push(nxt_A);
        } else if(mem[pos_A].find(vel_A) == mem[pos_A].end()) {
            mem[pos_A][vel_A] = num + 1;
            q.push(nxt_A);
        }
        
        //instr == 'R'
        long long pos_R = pos;
        long long vel_R = (vel > 0? -1 : 1);
        pair<long long, long long> nxt_R = {pos_R, vel_R};
        if(mem[pos_R].find(vel_R) == mem[pos_R].end()) {
            mem[pos_R][vel_R] = num + 1;
            q.push(nxt_R);
        }
    }
       
    return 0;

}



#endif /* RaceCar_h */
