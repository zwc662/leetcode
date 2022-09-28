//
//  AsteroidCollision.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/31/22.
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

#ifndef AsteroidCollision_h
#define AsteroidCollision_h

class Solution {
public:
   
    static bool Compare(vector<int> a, vector<int> b){return (a[2] >  b[2]);}
    vector<int> asteroidCollision(vector<int> asteroids);
};

void test(const vector<string>& input_strs) {
    vector<int> asteroids = ReadOneDimIntArray(input_strs[0]);
    Solution sol;
    vector<int> result = sol.asteroidCollision(asteroids);
    for(int i = 0; i < result.size(); i++) cout << result[i] << endl;
}

 

vector<int> Solution::asteroidCollision(vector<int> asteroids) {
        vector<int> res;
        for(int i = 0; i < asteroids.size() - 1; i++) {
            if(asteroids[i] > 0 && asteroids[i + 1] < 0) {
                if(abs(asteroids[i] > abs(asteroids[i + 1]))) {
                    res.push_back(asteroids[i]);
                } else if(abs(asteroids[i] < abs(asteroids[i + 1]))) res.push_back(asteroids[i + 1]);
            } else if(asteroids[i] > 0 && asteroids[i + 1] > 0) {
                res.push_back(asteroids[i]);
            } else if(asteroids[i] < 0) {
                if(i == 0)  res.push_back(asteroids[i]);
                else if(asteroids[i - 1] < 0)res.push_back(asteroids[i]);
            }
        }
        if(asteroids[asteroids.size() - 2] > 0 && asteroids[asteroids.size() - 1] > 0) res.push_back(asteroids[asteroids.size() - 1]);
        else if(asteroids[asteroids.size() - 2] < 0) res.push_back(asteroids[asteroids.size() - 1]);


        while(res.size() > 1 && res.size() < asteroids.size()) {
            asteroids.clear();
            for(int i = 0; i < res.size(); i++) asteroids.push_back(res[i]);
            res.clear();
            for(int i = 0; i < asteroids.size() - 1; i++) {
                if(asteroids[i] > 0 && asteroids[i + 1] < 0) {
                    if(abs(asteroids[i] > abs(asteroids[i + 1]))) {
                        res.push_back(asteroids[i]);
                    } else if(abs(asteroids[i] < abs(asteroids[i + 1]))) res.push_back(asteroids[i + 1]);
                } else if(asteroids[i] > 0 && asteroids[i + 1] > 0) {
                    res.push_back(asteroids[i]);
                } else if(asteroids[i] < 0) {
                    if(i == 0)  res.push_back(asteroids[i]);
                    else if(asteroids[i - 1] < 0)res.push_back(asteroids[i]);
                }
            }
            if(asteroids[asteroids.size() - 2] > 0 && asteroids[asteroids.size() - 1] > 0) res.push_back(asteroids[asteroids.size() - 1]);
            else if(asteroids[asteroids.size() - 2] < 0) res.push_back(asteroids[asteroids.size() - 1]);
            
        }
         
        return res;
}

#endif /* AsteroidCollision_h */
