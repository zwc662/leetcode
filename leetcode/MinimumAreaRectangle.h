//
//  MinimumAreaRectangle.h
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
#include <set>
#include "utils.h"

using namespace std;

#ifndef MinimumAreaRectangle_h
#define MinimumAreaRectangle_h

class Solution {
public:
    unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;
    unordered_map<int, vector<pair<int, int>>> rowPairs;
    unordered_map<int, vector<pair<int, int>>> colPairs;
    int minAreaRect_sol2(vector<vector<int>>& points);
    int minAreaRect_sol1(vector<vector<int>>& points);
};

void test(const vector<string>& input_strs) {
    vector<vector<int>> dict = ReadTwoDimIntArray(input_strs[0]);
    Solution sol;
    int result = sol.minAreaRect_sol2(dict);
    cout << result << endl;
}

int Solution::minAreaRect_sol1(vector<vector<int>>& points) {
    for(int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];
        this->rows[x].push_back(y);
        this->rows[y].push_back(x);
    }
    int result = INT_MAX;
    for(int i = 0; i < rows.size(); i++) {
        for(int j = 0; j < rows[i].size(); j++) {
            for(int k = j + 1; k < rows[i].size(); k++) {
                int col1 = rows[i][j];
                int col2 = rows[i][k];
                if(col1 == col2) continue;
                int diff = abs(col2 - col1);
                for(int m = i + 1; m < i +   floor(result / diff); m++) {
                    if(find(this->rows[m].begin(), this->rows[m].end(), col1) != this->rows[m].end() && find(this->rows[m].begin(), this->rows[m].end(), col2)  != this->rows[m].end()) {
                        result = (m - i) * diff; break;
                    }
                }
            }
        }
    }
    return result;
}

int Solution::minAreaRect_sol2(vector<vector<int>>& points) {
  int res = INT_MAX;
  unordered_map<int, set<int>> x;
  for (auto p : points) x[p[0]].insert(p[1]);
  for (auto i = x.begin(); i != x.end(); ++i)
    for (auto j = next(i); j != x.end(); ++j) {
      if (i->second.size() < 2 || j->second.size() < 2) continue;
      vector<int> y;
      set_intersection(begin(i->second), end(i->second),
        begin(j->second), end(j->second), back_inserter(y));
      for (int k = 1; k < y.size(); ++k)
        res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
    }
  return res == INT_MAX ? 0 : res;
}

#endif /* MinimumAreaRectangle_h */
