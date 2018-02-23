//
//  h10.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/18/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
//10. Regular Expression Matching   \
Implement regular expression matching with support for '.' and '*'. \
'.' Matches any single character.   \
'*' Matches zero or more of the preceding element.  \
The matching should cover the entire input string (not partial).    \
The function prototype should be:   \
bool isMatch(const char *s, const char *p)  \
Some examples:  \
isMatch("aa","a") → false   \
isMatch("aa","aa") → true   \
isMatch("aaa","aa") → false \
isMatch("aa", "a*") → true  \
isMatch("aa", ".*") → true  \
isMatch("ab", ".*") → true  \
isMatch("aab", "c*a*b") → true

//Use deterministic finite automata which accept the regular expression

#ifndef h10_h
#define h10_h
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class trans {
public:
    char symbol = '\0';
    int from = 0;
    int to = 0;
    trans(char symbol, int from, int to): symbol(symbol), from(from), to(to) {}
    trans(int from, int to): from(from), to(to) {}
};

class state {
public:
    int id = 0;
    trans* out = NULL;
    trans* self = NULL;
    //state(int index): index(index), out(NULL), self(NULL) {}
};

class automata {
public:
    state* states = new state;
    state* init = new state;
    state* end = new state;
    
    automata(string s);
    bool accept(state* init, string s);
};

automata::automata(string s) {
    this->states = new state[s.size() + 1];//[s.size() + 1];
    for(size_t index = 0; index < s.size(); index++) this->states[index].id = int(index);
    this->init = states;
    this->init->id = 0;
    
    auto i = s.begin();
    while(char(*i) == '*') {
        this->init->self = new trans(0, 0);
        i++;
    }
    
    if(i == s.end()) {
        this->init->id = -1;
        return;
    }
    
    char symbol = char(*i);
    int index = 1;
    init->out = new trans(symbol, 0, int(index));
    i++;
    
    while(i != s.end()) {
        if(char(*i) == '*') {
            (this->states + index - 1)->out->symbol = '\0';
            (this->states + index)->self = new trans(symbol, index, index);
            i++;
        } else {
            symbol = char(*i);
            (this->states + index + 1)->id = index + 1;
            (this->states + index)->out = new trans(symbol, index, index + 1);
            index++;
            i++;
        }
    }
    
    this->end = this->states + index;
    this->end->id = -1;
    
    for(int i = 0; i<s.size(); i++) {
        if((this->init + i)->self != NULL)  cout<< (this->init + i)->id << "=>"<< (this->init + i)->self->symbol << "=>" << (this->init + (this->init + i)->self->to)->id << endl;
        if((this->init + i)->out != NULL)   cout<< (this->init + i)->id << "=>"<< (this->init + i)->out->symbol << "=>" << (this->init + (this->init + i)->out->to)->id << endl;
        
        if((this->init + i)->id == -1) break;
    }
}

bool automata::accept(state* init, string s) {
    if(init->out != NULL) {
        if(init->out->symbol == '\0') {
            if(this->accept(this->init + (init->out->to), s)) return true;
        }
    }
    if(init->out != NULL && s.begin() != s.end()) {
        printf("%d ", init->id);
        cout << s << endl;
        if(init->out->symbol == s[0] || init->out->symbol == '.') {
            printf("try out\n");
            if(s.size() == 1) {
                if(this->accept(this->init + (init->out->to), "")) return true;
            } else {
                if(this->accept(this->init + (init->out->to), s.substr(1, s.size() - 1))) return true;
            }
        }
    }
    if(init->self != NULL && s.begin() != s.end()) {
        printf("%d ", init->id);
        cout << s << endl;
        if(init->self->symbol == s[0] || init->self->symbol == '.') {
            printf("try self\n");
            if(s.size() == 1) {
                if(this->accept(init, "")) return true;
                if(init->id == -1) return true;
            } else {
                if(this->accept(init, s.substr(1, s.size() - 1))) return true;
            }
        }
    }
    if(s.size() == 0 && init->id == -1)   return true;
    else if(s.size() == 0 && init->out != NULL) {
        if(init->out->symbol == '?') {
            if(this->accept(this->init + (init->out->to), s)) return true;
        }
    } else if(s.size() == 0 && init->self != NULL) {
        if(init->self->symbol == '.') {
            if(init->id == -1) return true;
        }
    }
    
    printf("%d ", init->id);
    cout << "fail " << s << endl;
    return false;
}

class Solution {
public:
    bool isMatch(string s, string p);
    void test();
};

void Solution::test() {
    string s;
    string p = ".*";
    printf("%d\n", this->isMatch("abbabaaaaaaacaa", "a*.*b.a.*c*b*a*c*"));
}

bool Solution::isMatch(string s, string p) {
    for(auto i = s.begin(); i != s.end(); i++) {
        if(char(*i) == '.' || char(*i) == '*')  {
            automata S = automata(s);
            if(S.accept(S.init, p)) return true;
            else return false;
        }
    }
    for(auto i = p.begin(); i != p.end(); i++) {
        if(char(*i) == '.' || char(*i) == '*')  {
            automata P = automata(p);
            if(P.accept(P.init, s)) return true;
            else return false;
        }
    }
    if(s.begin() != s.end()) {
        automata S = automata(s);
        if(S.accept(S.init, p)) return true;
    } else if(p.begin() != p.end()) {
        automata P = automata(p);
        if(P.accept(P.init, s)) return true;
    } else return true;
    
    return false;
}



#endif /* h10_h */
