//
//  Minesweeper.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/16/22.
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
/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given an m x n char matrix board representing the game board where:

'M' represents an unrevealed mine,
'E' represents an unrevealed empty square,
'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
'X' represents a revealed mine.
You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

Return the board after revealing this position according to the following rules:

If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
 */

#ifndef Minesweeper_h
#define Minesweeper_h

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click);
    void recur(vector<vector<char>>& board, pair<int, int> click);
};

void test(const vector<string>& input_strs) {
    vector<vector<char>> board = ReadTwoDimCharArray(input_strs[0]);
    for(auto chs: board) {
        for(auto ch: chs) cout << ch << ", ";
        cout << endl;
    }
    vector<int> click = ReadOneDimIntArray(input_strs[1]);
    for(auto num: click) cout << num << endl;
    
    Solution sol;
    vector<vector<char>> result = sol.updateBoard(board, click);
    for(auto chs: result) {
        for(auto ch: chs) cout << ch << ", ";
        cout << endl;
    }
}

#endif /* Minesweeper_h */


vector<vector<char>> Solution::updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int row = click[0];
    int col = click[1];
    if(board[row][col] == 'M') board[row][col] = 'X';
    else recur(board, pair<int, int>(row, col));
    return board;
}


void Solution::recur(vector<vector<char>>& board, pair<int, int> click) {
        int row = click.first;
        int col = click.second;
        queue<pair<int, int>> q;
        if(board[row][col] != 'E') return;
        q.push(pair<int, int>(row - 1, col - 1));
        q.push(pair<int, int>(row - 1, col));
        q.push(pair<int, int>(row - 1, col + 1));
        q.push(pair<int, int>(row, col - 1));
        q.push(pair<int, int>(row, col + 1));
        q.push(pair<int, int>(row + 1, col - 1));
        q.push(pair<int, int>(row + 1, col));
        q.push(pair<int, int>(row + 1, col + 1));
        vector<pair<int, int>> mines;
        queue<pair<int, int>> q_;
        while(!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            if(pos.first < 0 || pos.second < 0 || pos.first > board.size() - 1 || pos.second > board[0].size() - 1) continue;
            else {
                if(board[pos.first][pos.second] == 'M') mines.push_back(pos);
                if(mines.size() == 0) q_.push(pos);
            }
        }
        if(mines.size() > 0) board[row][col] = '0' + mines.size();
        else {
            board[row][col] = 'B';
            while(!q_.empty()) {
                pair<int, int> pos = q_.front();
                q_.pop();
                this->recur(board, pos);
            }
        }
}
