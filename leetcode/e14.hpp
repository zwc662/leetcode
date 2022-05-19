//
//  e14.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/23/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//  Write a function to find the longest common prefix string amongst an array of strings.

#ifndef e14_h
#define e14_h
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        cout << strs[0] << endl;
        if(strs[0].size() == 0) return "";
        string prefix;
        char token;
        int flag = 0;
        while(flag < strs[0].size()){
            token = strs[0][flag];
            for(auto i = strs.begin() + 1; i != strs.end(); i++) {
                if((*i).size() == 0) return "";
                if((*i)[flag] != token) return prefix;
            }
            flag++;
            prefix = prefix + token;
        }
        return prefix;
    }
};

#endif /* e14_h */
