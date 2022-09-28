//
//  ReorderDataInLogFiles.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/11/22.
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

#ifndef ReorderDataInLogFiles_h
#define ReorderDataInLogFiles_h

class Solution {
public:
   vector<string> reorderLogFiles(vector<string>& logs);
   bool gt(string log1, string log2);
};
void test(const vector<string>& input_strs) {
    vector<string> logs = ReadOneDimStrArray(input_strs[0]);
    Solution sol;
    vector<string> results = sol.reorderLogFiles(logs);
    for(int i = 0; i < results.size(); i++) cout << results[i] << endl;
}

vector<string> Solution::reorderLogFiles(vector<string>& logs) {
    for(int i = 1; i < logs.size(); i++) {
        //cout << logs[i] << endl;
        for(int j = i; j > 0; j--) {
            if(this->gt(logs[j - 1], logs[j])) {
                string tmp = logs[j - 1];
                logs[j - 1] = logs[j];
                logs[j] = tmp;
            } else break;
        }
   
    }
    return logs;
}

bool Solution::gt(string log1, string log2) {
    int i1 = 0, i2 = 0;
    
    while(log1.at(i1) != ' ') i1++;
    while(log2.at(i2) != ' ') i2++;
    
    bool digit = true;
    for(int i = i1; i < log1.length(); i++) {
        if(log1.at(i) >= 'a' && log1.at(i) <= 'z') {digit = false; break;}
    }
    if(digit) {
        for(int i = i2; i < log2.length(); i++) {
            if(log2.at(i) >= 'a' && log2.at(i) <= 'z') {digit = false; break;}
        }
    }
    if(digit) return false;
    
    if(log1.substr(i1) == log2.substr(i2)) {
        
        if(digit) return false;
        i1 = 0; i2 = 0;
        while(log1.at(i1) != ' ' && log2.at(i2) != ' ') {
            if(log1.at(i1) == log2.at(i2)) {
                i1++; i2++; continue;
            }
            else if(log1.at(i1) > log2.at(i2)) return true;
            else return false;
        }
        return true;
    }
    
    while(i1 < log1.length() && i2 < log2.length()) {
        if(log1.at(i1) == log2.at(i2)) {i1++; i2++;}
        else if(log1.at(i1) == ' ' && log2.at(i2) != ' ') return false;
        else if(log1.at(i1) != ' ' && log2.at(i2) == ' ') return true;
        else if(log1.at(i1) < log2.at(i2)) {
            if(log1.at(i1) <= '9' && log2.at(i2) >= 'a') return true;
            else if(log1.at(i1) <= '9' && log2.at(i2) <= '9') return false;
            else return false;
        } else if(log1.at(i1) > log2.at(i2)) {
            if(log1.at(i1) >= 'a' && log2.at(i2) <= '9') return false;
            else if(log1.at(i1) <= '9' && log2.at(i2) <= '9') return false;
            else return true;
        }
    }
    if(i1 == log1.length()) return false;
    else return true;
    }

#endif /* ReorderDataInLogFiles_h */
