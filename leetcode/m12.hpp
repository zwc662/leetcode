//
//  m12.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/22/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
//Given an integer, convert it to a roman numeral.  \\
Input is guaranteed to be within the range from 1 to 3999.



#ifndef m12_h
#define m12_h
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string r;
        while(num != 0) {
            int i = 0;
            for(; i < num/1000; i++) r = r + "M";
            num -= i * 10000;
            int i = 0;
            for(; i < num/500; i++) r = r + "D";
            
    }
};

#endif /* m12_h */
