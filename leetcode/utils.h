//
//  utils.h
//  leetcode
//
//  Created by Weichao  Zhou on 4/27/22.
//  Copyright © 2022 Weichao  Zhou. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

#ifndef utils_h
#define utils_h


std::vector<std::string> ReadOneDimStrArray(std::string input_str) {
    std::vector<std::string> strs;
    std::string str;
    for(size_t i = 0; i < input_str.length() - 1; i++) {
        if(input_str.at(i) == ']') break;
        else if(input_str.at(i) == '[')  continue;
        else if(input_str.at(i) == ',') continue;
        else if(input_str.at(i) == '"') {
            if(str.length() > 0) {
                //cout<< str << " ";
                strs.push_back(str);
                str = "";
            } else {
                continue;
            }
        } else str.push_back(input_str.at(i));
    }
    return strs;
}

std::vector<std::vector<std::string>> ReadTwoDimStrArray(std::string input_str) {
    std::vector<std::vector<std::string>> str_vecs;
    std::vector<std::string> strs;
    std::string item;
    for(size_t i = 0; i < input_str.length() - 1; i++) {
        if(input_str.at(i) == ']') {
            if(strs.size() > 0) {
                //cout<< endl;
                str_vecs.push_back(strs);
                strs.clear();
            } else continue;
        }
        else if(input_str.at(i) == '[') {item = ""; continue;}
        else if(input_str.at(i) == ',') {item = ""; continue;}
        else if(input_str.at(i) == '"') {
            if(item.length() > 0) {
                strs.push_back(item);
                //cout<< item << " ";
            }
            item = "";
        }
        else item.push_back(input_str.at(i));
    }
    return str_vecs;
}

std::vector<int> ReadOneDimIntArray(std::string input_str) {
    std::vector<int> grid;
    int sign = 1;
    int num = 0;
    for(size_t i = 0; i < input_str.length(); i++) {
         
        if(input_str.at(i) == ']') {
            grid.push_back(sign * num);
            
            return grid;
        }
        else if(input_str.at(i) == '[') grid.clear();
        else if(input_str.at(i) == ',') {
            grid.push_back(sign * num);
            sign = 1;
            num = 0;
            continue;
        }
        else if(input_str.at(i) == '-') sign = -1;
        else if(input_str.at(i) - '0' < 0 || input_str.at(i) - '0' > 9) continue;
        else num = num * 10 + (int) (input_str.at(i) - '0');
    }
    return grid;
}


std::vector<double> ReadOneDimFloatArray(std::string input_str) {
    std::vector<double> grid;
    int sign = 1;
    int int_num = 0;
    double float_num = 0;
    bool fraction = false;
    for(size_t i = 0; i < input_str.length(); i++) {
         
        if(input_str.at(i) == ']') {
            while(float_num > 1) float_num = float_num / 10.0;
            grid.push_back(sign * (float_num + int_num));
            
            return grid;
        }
        else if(input_str.at(i) == '[') grid.clear();
        else if(input_str.at(i) == ',') {
            while(float_num > 1) float_num = float_num / 10.0;
            grid.push_back(sign * (float_num + int_num));
            sign = 1;
            int_num = 0;
            float_num = 0;
            continue;
        }
        else if(input_str.at(i) == '-') sign = -1;
        else if(input_str.at(i) == '.') fraction = true;
        else if(input_str.at(i) - '0' < 0 || input_str.at(i) - '0' > 9) continue;
        else if(!fraction) int_num = int_num * 10 + (int) (input_str.at(i) - '0');
        else if(fraction) float_num = float_num * 10 + (int) (input_str.at(i) - '0');
    }
    return grid;
}


std::vector<std::vector<int>> ReadTwoDimIntArray(std::string input_str) {
    std::vector<std::vector<int>> grid;
    std::string grid_str_i;
    for(size_t i = 1; i < input_str.length() - 1; i++) {
        if(input_str.at(i) == ']') {
            grid_str_i.push_back(']');
            grid.push_back(ReadOneDimIntArray(grid_str_i));
            grid_str_i = "";
        }
        else if(input_str.at(i) == ',' && grid_str_i.size() == 0) continue;
        else grid_str_i.push_back(input_str.at(i));
    }
    return grid;
}


std::vector<std::vector<double>> ReadTwoDimFloatArray(std::string input_str) {
    std::vector<std::vector<double>> grid;
    std::string grid_str_i;
    for(size_t i = 1; i < input_str.length() - 1; i++) {
        if(input_str.at(i) == ']') {
            grid_str_i.push_back(']');
            grid.push_back(ReadOneDimFloatArray(grid_str_i));
            grid_str_i = "";
        }
        else if(input_str.at(i) == ',' && grid_str_i.size() == 0) continue;
        else grid_str_i.push_back(input_str.at(i));
    }
    return grid;
}

 
int ReadOneInt(std::string input_str) {
    int k;
    sscanf(input_str.data(), "%d", &k);
    //cout << k << endl;
    return k;
}

long long ReadOneLongLong(std::string input_str) {
    long long k;
    sscanf(input_str.data(), "%lld", &k);
    //cout << k << endl;
    return k;
}


std::string ReadOneStr(std::string input_str) {
    std::string str;
    for(int i = 0; i < input_str.length(); i++) {
        if(input_str.at(i) == '"') continue;
        else str.push_back(input_str.at(i));
    }
    return str;
}

#endif /* utils_h */
