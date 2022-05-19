//
//  m3.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/8/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//////////////////////////////
//3. Longest Substring Without Repeating Characters\
Given a string, find the length of the longest substring without repeating characters. \
Examples:\
Given "abcabcbb", the answer is "abc", which the length is 3.\
Given "bbbbb", the answer is "b", with the length of 1.\
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//////////////////////////////

#include<string>
#include<vector>
#include<map>
using namespace std;
#ifndef m3_h
#define m3_h
class Solution {
public:
    int lengthOfLongestSubstring(string s);
    void test();
};

int Solution::lengthOfLongestSubstring(string s) {
    int max = 0;
    int len = 0;
    int anch = -1;
    vector<int> table(256, -1);
    if(s=="") return 0;
    for(int i = 0; i < s.size(); i++) {
        int index = int(s[i]);
        if(table[index] <= anch ) {
            table[index] = i;
            len++;
        } else {
            max = (max < len ? len : max);
            printf("len=%d, max=%d\n", len, max);
            len = i - table[index];
            anch = table[index];
            table[index] = i;
            
            printf("len=%d\n", len);
        }
    }
    max = (max < len ? len : max);
    printf("len=%d, max=%d\n", len, max);
    return max;
}

void Solution::test() {
    string s = "sfafewfwfewcfwcewcwecwecsdcfsfsfswew";
    int len = lengthOfLongestSubstring(s);
    cout << len << endl;
}

#endif /* m3_h */
