//
//  e20.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/27/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.


//  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#ifndef e20_h
#define e20_h

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    bool isValid(string s);
    void test();
};

void Solution::test() {
    string s = "[";
    cout << Solution::isValid(s) << endl;
}
bool Solution::isValid(string s) {
    vector<char> chs = {*(s.begin())};
    for(auto i = s.begin() + 1; i != s.end(); i++) {
        if(*i == '(' || *i == '{' || *i == '[') chs.push_back(*i);
        else {
            int j = 0;
            while(chs[chs.size() - j - 1] == '\0') {
                j++;
            }
            if(*i == ')' && chs[chs.size() - j - 1] != '(') return false;
            else if(*i == '}' && chs[chs.size() - j - 1] != '{') return false;
            else if(*i == ']' && chs[chs.size() - j - 1] != '[') return false;
            else chs[chs.size() - j - 1] = '\0';
        };
    }
    if(chs[0] == '\0') return true;
    return false;
}
#endif /* e20_h */
