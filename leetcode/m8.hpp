//
//  m8.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/16/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
/*Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

 

Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/


#ifndef m8_h
#define m8_h
#include<vector>
using namespace std;
class Solution {
public:
    int myAtoi(string str);
}

int Solution::myAtoi(string str) {
    if(str.size() == 0) return 0;
    unsigned int u_bound = -1;
    unsigned int bound = u_bound / 2;
    unsigned int tot = 0;
    int carry = 1;
    for(auto i = str.begin(); i != str.end(); i++) {
        if(i == str.begin() && *i == '-') carry = -1;
        if(char(*i) == '0' || (int(*i) >= int('1') && (int(*i)) <= (int('1') + 8))) {
            if(carry == -1 && tot > (bound - int(*i))/10) return 0;
            if(carry == 1 && tot > (u_bound - int(*i))/10) return 0;
            tot = tot * 10 + int(*i);
        }
    }
    return carry * tot;
}

#endif /* m8_h */
