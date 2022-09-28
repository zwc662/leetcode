//
//  LexicographicallySmallestEquivalentString.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/19/22.
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
#ifndef LexicographicallySmallestEquivalentString_h
#define LexicographicallySmallestEquivalentString_h

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr);
};

struct linked_ch {
    int len = 0;
    char ch;
    linked_ch* head;
};

#endif /* LexicographicallySmallestEquivalentString_h */
void test(const vector<string>& input_strs) {
    string s1 = ReadOneStr(input_strs[0]), s2 = ReadOneStr(input_strs[1]), baseStr = ReadOneStr(input_strs[2]);
    Solution sol = Solution();
    cout << sol.smallestEquivalentString(s1, s2, baseStr) << endl;
}

string smallestEquivalentString_unfinished(string s1, string s2, string baseStr) {
    unordered_map<char, linked_ch> tab;
    unordered_map<char, linked_ch> equiv;
    for(int i = 0; i < s1.length(); i++) {
        char c1 = s1.at(i), c2 = s2.at(i);
        char min_c = 'z';
        if(tab.find(c1) != tab.end()) min_c = tab[c1].head[0].ch;
        if(tab.find(c2) != tab.end()) min_c = min(tab[c2].head[0].ch, min_c);
        min_c = min(min_c, min(c1, c2));
        
        if(tab.find(c1) == tab.end() && tab.find(c2) == tab.end()) {
            if(c1 == c2) {
                equiv[min_c] = linked_ch{1, min_c, new linked_ch[26]};
                equiv[min_c].head[0] = equiv[min_c];
                tab[c1] = (min_c == c1? equiv[min_c] : equiv[min_c].head[1]);
            } else {
                equiv[min_c] = linked_ch{2, min_c, new linked_ch[26]};
                equiv[min_c].head[0] = equiv[min_c];
                equiv[min_c].head[1] = linked_ch{1, min_c == c1? c2 : c1, new linked_ch[26]};
                equiv[min_c].head[1].head[0] = equiv[min_c];
            
                tab[c1] = (min_c == c1? equiv[min_c] : equiv[min_c].head[1]);
                tab[c2] = (min_c == c1? equiv[min_c].head[1] : equiv[min_c]);
            }
        }
        else if(tab.find(c1) == tab.end()) {
            if(min_c == c1) {
                equiv[min_c] = linked_ch{1 + equiv[tab[c2].head->ch].len, min_c, new linked_ch[26]};
                equiv[min_c].head[0] = equiv[min_c];
                for(int i = equiv[tab[c2].head->ch].len - 1; i >= 0; i--) {
                    tab[equiv[tab[c2].head->ch].head[i].ch] = linked_ch{1, equiv[tab[c2].head->ch].head[i].ch, new linked_ch[26]};
                    tab[equiv[tab[c2].head->ch].head[i].ch].head = equiv[min_c].head;
                    equiv[min_c].head[i + 1] = tab[equiv[tab[c2].head->ch].head[i].ch];
                }
                tab[c1] = equiv[min_c];
                tab[c2].head[0] = equiv[min_c];
            } else {
                tab[c1] = linked_ch{1, c2, new linked_ch[26]};
                tab[c1].head[0] = equiv[min_c];
                equiv[min_c].head[equiv[min_c].len] = tab[c1];
            }
        }
        else if(tab.find(c2) == tab.end()) {
            if(min_c == c2) {
                equiv[min_c] = linked_ch{1 + equiv[tab[c1].head->ch].len, min_c, new linked_ch[26]};
                equiv[min_c].head[0] = equiv[min_c];
                for(int i = equiv[tab[c1].head->ch].len - 1; i >= 0; i++) {
                    tab[equiv[tab[c1].head->ch].head[i].ch] = linked_ch{1, equiv[tab[c1].head->ch].head[i].ch, new linked_ch[26]};
                    tab[equiv[tab[c1].head->ch].head[i].ch].head = equiv[min_c].head;
                    equiv[min_c].head[i + 1] = tab[equiv[tab[c1].head->ch].head[i].ch];
                }
                tab[c2] = equiv[min_c];
                tab[c1].head[0] = equiv[min_c];
            } else {
                tab[c2] = linked_ch{1, c2, new linked_ch[26]};
                tab[c2].head[0] = equiv[min_c];
                equiv[min_c].head[equiv[min_c].len] = tab[c2];
            }
        } else if(c1 == c2) continue;
        else {
            if(min_c == tab[c1].head->ch) {
                for(int i = equiv[tab[c2].head->ch].len -1; i >= 0; i--) {
                    tab[equiv[tab[c2].head->ch].head[i].ch] = linked_ch{1, equiv[tab[c2].head->ch].head[i].ch, new linked_ch[26]};
                    tab[equiv[tab[c2].head->ch].head[i].ch].head = equiv[min_c].head;
                    equiv[min_c].head[i + 1] = tab[equiv[tab[c2].head->ch].head[i].ch];
                }
                tab[c2].head = new linked_ch[26];
                tab[c2].head[0] = equiv[min_c];
            } else {
                for(int i = equiv[tab[c1].head->ch].len - 1; i >= 0; i--) {
                    tab[equiv[tab[c1].head->ch].head[i].ch] = linked_ch{1, equiv[tab[c1].head->ch].head[i].ch, new linked_ch[26]};
                    tab[equiv[tab[c1].head->ch].head[i].ch].head = equiv[min_c].head;
                    equiv[min_c].head[i + 1] = tab[equiv[tab[c1].head->ch].head[i].ch];
                }
                tab[c1].head  = new linked_ch[26];
                tab[c1].head[0] = equiv[min_c];
            }
        }
    }
    
    string res = "";
    for(int i = 0; i < baseStr.length(); i++) {
        char ci = baseStr.at(i);
        if(tab.find(ci) == tab.end()) res.push_back(ci);
        else res.push_back(tab[ci].head->ch);
    }
    return res;
}


string Solution::smallestEquivalentString(string s1, string s2, string baseStr) {
    unordered_map<char, char> tab;
    unordered_map<char, vector<char>> equiv;
 
    for(int i = 0; i < s1.length(); i++) {
        char c1 = s1.at(i), c2 = s2.at(i);
        char min_c = 'z';
        if(tab.find(c1) != tab.end()) min_c = tab[c1];
        if(tab.find(c2) != tab.end()) min_c = min(tab[c2], min_c);
        min_c = min(min_c, min(c1, c2));
 
        if(tab.find(c1) == tab.end() && tab.find(c2) == tab.end()) {
            tab[c1] = min_c;
            tab[c2] = min_c;
             
            if(c1 == c2) equiv[min_c] = vector<char>{c1};
            else equiv[min_c] = vector<char>{c1, c2};
         
        }
        else if(tab.find(c1) == tab.end()) {
            tab[c1] = min_c;
            equiv[min_c].push_back(c1);
        }
        else if(tab.find(c2) == tab.end()) {
            tab[c2] = min_c;
            equiv[min_c].push_back(c2);
        }
        
        if(tab[c1] != min_c) {
            for(auto c: equiv[tab[c1]]) {
                equiv[min_c].push_back(c);
                tab[c] = min_c;
            }
            //tab[c1] = min_c;
        }
        if(tab[c2] != min_c) {
            for(auto c: equiv[tab[c2]]) {
                equiv[min_c].push_back(c);
                tab[c] = min_c;
            }
            //tab[c2] = min_c;
        }
        
    }
    string res = "";
    for(int i = 0; i < baseStr.length(); i++) {
        char ci = baseStr.at(i);
        if(tab.find(ci) == tab.end()) res.push_back(ci);
        else res.push_back(tab[ci]);
    }
    return res;
}
