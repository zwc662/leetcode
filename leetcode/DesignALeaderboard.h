//
//  DesignALeaderboard.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/26/22.
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

#ifndef DesignALeaderboard_h
#define DesignALeaderboard_h
class Leaderboard {
public:
    vector<pair<int, int>> ranks;
    unordered_map<int, int> id_scores;
    Leaderboard();
    void addScore(int playerId, int score);
    int top(int K);
    void reset(int playerId);
};

void test(const vector<string>& input_strs) {
     
    Leaderboard lb = Leaderboard();
    lb.addScore(1, 73);
    lb.addScore(2, 56);
    lb.addScore(3, 39);
    lb.addScore(4, 51);
    lb.addScore(5, 4);
    cout << lb.top(1) << endl;
    lb.reset(1);
    lb.reset(2);
    lb.addScore(2, 51);
    cout << lb.top(3) << endl;
}

Leaderboard::Leaderboard() {
    this->id_scores;
    this->ranks;
}

void Leaderboard::addScore(int playerId, int score) {
    this->id_scores[playerId] = score;
    for(auto i = this->ranks.begin(); i != this->ranks.end(); i++) {
        pair<int, int> id_score = *i;
        int playerId_ = id_score.first;
        int score_ = id_score.second;
        if(this->id_scores[playerId_] == score_ && score_> score) continue;
        else if(this->id_scores[playerId_] != score_) continue;
        else {
            this->ranks.insert(i, pair<int, int>(playerId, score));
            return;
        }
    }
    this->ranks.push_back(pair<int, int>(playerId, score));
}

int Leaderboard::top(int k) {
    int tot = 0;
    int sum = 0;
    for(int i = 0; i < this->ranks.size(); i++) {
        int playerId_ = ranks[i].first;
        int score_ = ranks[i].second;
        if(this->id_scores[playerId_] == score_) {
            tot++;
            sum += score_;
        }
        if(tot == k) return sum;
    }
    return sum;
}

void Leaderboard::reset(int playerId) {
    this->addScore(playerId, 0);
}


#endif /* DesignALeaderboard_h */
