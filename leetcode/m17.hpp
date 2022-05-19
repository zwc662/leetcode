//
//  m17.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/27/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//Given a digit string, return all possible letter combinations that the number could represent.
//Input:Digit string "23"   \
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

#ifndef m17_h
#define m17_h
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits);
    void test(string digits);
};

void Solution::test(string digits) {
    digits = "2";
    vector<string> comb = Solution::letterCombinations(digits);
    for(auto i = comb.begin(); i != comb.end(); i++) {
        for(auto j = (*i).begin(); j != (*i).end(); j++) {
            printf("%c", *j);
        }
        printf("\n");
    }
}

vector<string> Solution::letterCombinations(string digits) {
    vector<string> output;
    vector<string> table;
    size_t size = 0;
    for(auto i = digits.begin(); i != digits.end(); i++) {
        string chs;
        char base;
        int offset;
        if((*i) == '1' || (*i) == '*' || (*i) == '#') continue;
        cout << *i <<endl;
        switch(*i) {
            case '0':
                base = ' ';
                offset = 1;
                break;
            case '2':
                base = 'a';
                offset = 3;
                break;
            case '3':
                base = 'd';
                offset = 3;
                break;
            case '4':
                base = 'g';
                offset = 3;
                break;
            case '5':
                base = 'j';
                offset = 3;
                break;
            case '6':
                base = 'm';
                offset = 3;
                break;
            case '7':
                base = 'p';
                offset = 4;
                break;
            case '8':
                base = 't';
                offset = 3;
                break;
            case '9':
                base = 'w';
                offset = 4;
                break;
        }
        cout << base <<endl;
        for(int i = 0; i < offset; i++) chs = chs + (char)(base + i);
        table.push_back(chs);
        if(size == 0) size = offset;
        else size *= offset;
    }
    //cout << size << endl;
    for(size_t i = 0; i < size; i++) {
        size_t coord = i;
        string letter;
        for(size_t j = 0; j < table.size(); j++) {
            letter = letter + table[j][coord % (table[j].size())];
            coord = coord/(table[j].size());
        }
        output.push_back(letter);
    }
    //cout << output.size() << endl;
    return output;
}
