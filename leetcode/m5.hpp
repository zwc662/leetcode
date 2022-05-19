//
//  m5.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/14/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.

//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

//Example:  \
Input: "babad"  \
Output: "bab"   \
Note: "aba" is also a valid answer.

//Example:  \
Input: "cbbd"   \
Output: "bb"

//Use stack, first in last out.
#ifndef m5_h
#define m5_h
#include<stdio.h>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s);
};

string Solution::longestPalindrome(string s) {
    if(s.size() == 1) return s;
    string palindrome;
    int cnt = 0;
    for(auto i = s.begin(); i != s.end(); cnt++) {
        size_t len = 0;
        i += cnt%2;
        string cand = (cnt%2 ? string(1, char(*(i))) : "");
        while(char(*(i - len - cnt%2)) == char(*(len + i + 1))) {
            cand = string(1, char(*(i - len - cnt%2))) + cand + string(1, char(*(len + i +1)));
            if(i - len - cnt%2 != s.begin() && len + i + 1 != s.end()) {
                len++;
            } else break;
        }
        if(cand.size() > palindrome.size()) palindrome = cand;
    }
    return palindrome;
}
#endif /* m5_h */
