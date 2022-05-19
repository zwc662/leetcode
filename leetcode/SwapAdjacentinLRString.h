//
//  SwapAdjacentinLRString.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/13/22.
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
#ifndef SwapAdjacentinLRString_h
#define SwapAdjacentinLRString_h
/*
Key observations:
There are three kinds of characters, ‘L’, ‘R’, ‘X’.
Replacing XL with LX = move L to the left by one
Replacing RX with XR = move R to the right by one
If we remove all the X in both strings, the resulting strings should be the same.

Additional observations:
Since a move always involves X, an L or R cannot move through another L or R.
Since an L can only move to the right, for each occurrence of L in the start string, its position should be to the same or to the left of its corresponding L in the end string.

And vice versa for the R characters.

Implementation
We first compare two strings with X removed. This checks relative position between Ls and Rs are correct.

Then we find the indices for each occurence of L and check the condition in the above figure. Then we do the same for R.
 */


class Solution {
public:
    bool canTransform(string start, string end);
};

void test(const vector<string>& input_strs) {
    string start = ReadOneStr(input_strs[0]);
    string end = ReadOneStr(input_strs[1]);
    Solution sol;
    cout << start << " " << end << endl;
    bool result = sol.canTransform(start, end);
    cout << result << endl;
}

bool Solution::canTransform(string start, string end) {
    string start_, end_;
    vector<int> Lstart, Lend, Rstart, Rend;
    for(int i = 0; i < start.size(); i++) {
        if(start.at(i) != 'X') {
            start_.push_back(start.at(i));
            if(start.at(i) == 'L') Lstart.push_back(i);
            else if(start.at(i) == 'R') Rstart.push_back(i);
        }
        if(end.at(i) != 'X') { end_.push_back(end.at(i));
            if(end.at(i) == 'L') Lend.push_back(i);
            else if(end.at(i) == 'R') Rend.push_back(i);
        }
    }
    if(start_ != end_) return false;
    if(Lstart.size() != Lend.size()) return false;
    if(Rstart.size() != Rend.size()) return false;
    for(int i = 0; i < Lstart.size(); i++) {
        if(Lstart[i] < Lend[i]) return false;
    }
    for(int i = 0; i < Rstart.size(); i++) {
        if(Rstart[i] > Rend[i]) return false;
    }
    return true;

}

#endif /* SwapAdjacentinLRString_h */
