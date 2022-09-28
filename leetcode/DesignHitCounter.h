//
//  DesignHitCounter.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/18/22.
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

#ifndef DesignHitCounter_h
#define DesignHitCounter_h
class HitCounter {
public:
    queue<vector<int>> q;
    vector<int> last_hit;
    int tot;
    HitCounter();
    void hit(int timestamp);
    int getHits(int timestamp);
};
/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
void test(const vector<string>& input_strs) {
    vector<string> cmds = ReadOneDimStrArray(input_strs[0]);
    vector<vector<int>> args = ReadTwoDimIntArray(input_strs[1]);
    HitCounter* hc = new HitCounter();
    for(int i = 0; i < cmds.size(); i++) {
        int arg = args[i][0];
        if(cmds[i] == "HitCounter") continue;
        else if(cmds[i] == "hit") hc->hit(arg);
        else if(cmds[i] == "getHits") cout << "getHistgs "<< arg << " " << hc->getHits(arg) << endl;
    }
    
}

#endif /* DesignHitCounter_h */


HitCounter::HitCounter() {
    this->tot = 0;
}
    
void HitCounter::hit(int timestamp) {
    if(this->last_hit.size() == 0) {
        last_hit = vector<int>{timestamp, 1};
    } else if(this->last_hit[0] + 300 <= timestamp) {
        this->last_hit = vector<int>{timestamp, 1};
        this->q = queue<vector<int>>();
        this->tot = 0;
    } else if(this->last_hit[0] == timestamp) this->last_hit[1]++;
    else {
        this->tot = this->tot + last_hit[1];
        this->q.push(last_hit);
        
        while(!this->q.empty()) {
            vector<int> old_hit = this->q.front();
            if(old_hit[0] + 300 <= timestamp) {
                this->q.pop();
                this->tot = this->tot - old_hit[1];
            } else {
                break;
            }
        }
        last_hit = vector<int>{timestamp, 1};
    }
    cout << "hit " << timestamp << " " << this->tot << " " << this->last_hit[1] << endl;
}
    
int HitCounter::getHits(int timestamp) {
    if(this->last_hit.size() == 0) return 0;
    if(this->last_hit[0] + 300 <= timestamp) {
        this->last_hit = vector<int>{};
        this->q = queue<vector<int>>();
        this->tot = 0;
        return 0;
    }
    if(this->last_hit[0] == timestamp) return this->tot + this->last_hit[1];
    else {
        while(!this->q.empty()) {
            vector<int> old_hit = this->q.front();
            if(old_hit[0] + 300 <= timestamp) {
                this->q.pop();
                this->tot = this->tot - old_hit[1];
            } else {
                break;
            }
        }
     }
     return this->tot + last_hit[1];
}
