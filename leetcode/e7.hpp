//
//  e7.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/16/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
//Given a 32-bit signed integer, reverse digits of an integer.  \
Example 1:

//Input: 123    \
Output:  321    \
Example 2:

//Input: -123   \
Output: -321    \
Example 3:

//Input: 120    \
Output: 21  \

//bound of signed int is 429496729/2

#ifndef e7_h
#define e7_h
#include<vector>
using namespace std;
class Solution {
public:
    int reverse(int x);
};

int Solution::reverse(int x) {
    unsigned int bound = 0;
    bound = (bound - 1)/2;
    unsigned long rev = 0;
    
    int ca = 1;
    if(x < 0) ca = -1;
    x = x * ca;
    if(x < 0) return 0;
    
    vector<int> digits = {x % 10};
    
    
    while(x >= 10) {
        x = x / 10;
        digits.push_back(x % 10);
    }
    
    for(int i = 0; i < digits.size(); i++) {
        if(rev > bound) return 0;
        rev = 10 * rev + digits[i];
    }
    if(rev > bound) return 0;
    
    return ca * rev;
}
#endif /* e7_h */
