//
//  LongestWordInDictionaryThroughDeleting.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/16/22.
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

#ifndef LongestWordInDictionaryThroughDeleting_h
#define LongestWordInDictionaryThroughDeleting_h

class Solution {
public:
    static bool Compare(string w1, string w2);
    string findLongestWord(string s, vector<string>& dictionary);
};

void test(const vector<string>& input_strs) {
    string s = ReadOneStr(input_strs[0]);
    vector<string> dictionary = ReadOneDimStrArray(input_strs[1]);
    Solution sol;
    string result = sol.findLongestWord(s, dictionary);
    cout << result << endl;
}

bool Solution::Compare(string w1, string w2)
{
    int i = 0, j = 0;
    while(i < w1.size() && j < w2.size()) {
        if(w1.at(i) < w2.at(j)) return false;
        else if(w1.at(i) > w2.at(j)) return true;
        i++;
        j++;
    }
    if(i < w1.size()) return true;
    if(j < w2.size()) return false;
    return true;
}
 


string Solution::findLongestWord(string s, vector<string>& dictionary) {
    int max_len = 0;
    string result = "";
    std::priority_queue<string, std::vector<string>, std::function<bool(string, string)>> pq(Solution::Compare);
    for(string word: dictionary) pq.push(word);
    while(!pq.empty()) {
        string word = pq.top();
        pq.pop();
        int j = 0;
        for(int i = 0; i < word.size(); i++) {
            while(j < s.size()) {
                if(s.at(j) == word.at(i)) {
                    if(i == word.size() - 1)  {
                        if(max_len < word.size()) result = word;
                        max_len = max_len > word.size()? max_len : word.size();
                    }
                    j++;
                    break;
                }
                j++;
            }
            if(j == s.size()) break;
        }
    }
    return result;
}
#endif /* LongestWordInDictionaryThroughDeleting_h */
