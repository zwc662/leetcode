//
//  DesignSnakeGame.h
//  leetcode
//
//  Created by Weichao  Zhou on 5/30/22.
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

#ifndef DesignSnakeGame_h
#define DesignSnakeGame_h

class SnakeGame {
    public:
        int width, height, score;
        deque<vector<int>> food;
        vector<vector<int>> snake;
        SnakeGame(int width, int height, vector<vector<int>>& food);
        int move(string direction);
        
};

void test(const vector<string>& input_strs) {
    vector<vector<int>> food;
    food.push_back(vector<int>{1, 2});
    food.push_back(vector<int>{0, 1});
    SnakeGame sol(3, 2, food);
    cout << sol.move("R") << endl;
    cout << sol.move("D") << endl;
    cout << sol.move("R") << endl;
    cout << sol.move("U") << endl;
    cout << sol.move("L") << endl;
    cout << sol.move("U") << endl;
}

SnakeGame::SnakeGame(int width, int height, vector<vector<int>>& food) {
    for(int i = 0; i < food.size(); i++) this->food.push_back(food[i]);

    this->width = width;
    this->height = height;
    this->snake = vector<vector<int>>{vector<int>{0, 0}};
    this->score = 0;
}

int SnakeGame::move(string direction) {
    vector<int> pos = this->snake[0];
    if(direction == "U") {
        if(pos[0] == 0) return -1;
        else this->snake[0] = vector<int>{pos[0] - 1, pos[1]};
    } else if(direction == "D") {
        if(pos[0] == height - 1) return -1;
        else this->snake[0] = vector<int>{pos[0] + 1, pos[1]};
    } else if(direction == "L") {
        if(pos[1] == 0) return -1;
        else this->snake[0] = vector<int>{pos[0], pos[1] - 1};
    } else if(direction == "R") {
        if(pos[1] == width - 1) return -1;
        else this->snake[0] = vector<int>{pos[0], pos[1] + 1};
    }
    vector<int> head_pos{this->snake[0][0], this->snake[0][1]};
    for(int i = 1; i < this->snake.size(); i++) {
        vector<int> pos_ = this->snake[i];
        if(pos_[0] == head_pos[0] && pos_[1] == head_pos[1]) return -1;
        this->snake[i] = vector<int>{pos[0], pos[1]};
        pos = vector<int>{pos_[0], pos_[1]};
    }
    
    if(this->food.front() == head_pos) {
        this->food.pop_front();
        this->snake.push_back(pos);
        this->score++;
    }
    return this->score;
}


#endif /* DesignSnakeGame_h */
