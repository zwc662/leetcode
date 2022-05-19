//
//  m15.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/24/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.

//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.   \
Note: The solution set must not contain duplicate triplets.

//For example, given array S = [-1, 0, 1, 2, -1, -4],

//A solution set is:
//[
// [-1, 0, 1],
// [-1, -1, 2]
//]

#ifndef m15_h
#define m15_h
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;


class Solution {
public:
    int* sort(vector<int>& nums);
    int* divide(vector<int>& nums, size_t head, size_t tail);
    int* conquer(int* array1, size_t len1, int* array2, size_t len2);
    vector<vector<int>> threeSum(vector<int>& nums);
    vector<vector<int>> threeSum_(vector<int>& nums);
    vector<vector<int>> threeSum__(vector<int>& nums);
    void test(vector<int>& nums);
};

void Solution::test(vector<int>& nums) {
    vector<vector<int>> threesomes = this->threeSum(nums);
    vector<vector<int>> threesomes__ = this->threeSum__(nums);
    if(threesomes__.size() != threesomes.size()) {
        cout << "shit" << endl;
        //return;
    }
    for(auto i = threesomes.begin(); i != threesomes.end(); i++) {
        //printf("{%d, %d, %d},", (*i)[0], (*i)[1],(*i)[2]);
        for(auto j = i->begin(); j != i->end(); j++) {
            printf("%d ", (*j));
        }
        printf("\n");
    }
}
vector<vector<int>> Solution::threeSum_(vector<int>& nums) {
    if(nums.size() < 3) return {};
    vector<vector<int>> threesomes;
    int* array = this->sort(nums);
    size_t m = nums.size();
    for(size_t i = 0; i < nums.size() - 2; i++) {
        if(array[i] + array[i + 1] + array[i + 2] > 0) return threesomes;
        if(array[i] + array[nums.size() - 1] + array[nums.size() - 2] < 0) continue;
        if(i > 0 && array[i] == array[i - 1]) continue;
        size_t l = nums.size();
        size_t j = i + 1;
        for(; j < m; j++) {
            if(array[i] + array[j] + array[j + 1] > 0) break;
            if(array[i] + array[j] + array[nums.size() - 1] < 0) continue;
            if(j > i + 1 && array[j] == array[j - 1]) continue;
            size_t k = j + 1;
            for(; k < l; k++) {
                if(k > j + 1 && array[k] == array[k - 1]) continue;
                if(array[i] + array[j] + array[k] > 0) break;
                if(array[i] + array[j] + array[k] == 0) threesomes.push_back({array[i], array[j], array[k]});
            };
            l = k;
        }
        m = j;
    }
    return threesomes;
}

vector<vector<int>> Solution::threeSum__(vector<int>& nums) {
    if(nums.size() < 3) return {};
    vector<vector<int>> threesomes;
    int* array = this->sort(nums);
    //for(int i = 0; i < nums.size(); i++) cout << array[i] << endl;
    for(size_t i = 0; i < nums.size() - 2; i++) {
        if(array[i] + array[i + 1] + array[i + 2] > 0) return threesomes;
        if(array[i] + array[nums.size() - 2] + array[nums.size() - 1] < 0) continue;
        if(i > 0 && array[i] == array[i - 1]) continue;
        for(size_t j = i + 1; j < nums.size() - 1; j++) {
            if(array[i] + array[j] + array[j + 1] > 0) break;
            if(array[i] + array[j] + array[nums.size() - 1] < 0) continue;
            if(j > i + 1 && array[j] == array[j - 1]) continue;
            for(size_t k = j + 1; k < nums.size(); k++) {
                if(array[i] + array[j] + array[k] > 0) break;
                if(k > j + 1 && array[k] == array[k - 1]) continue;
                if(array[i] + array[j] + array[k] == 0) {
                    threesomes.push_back({array[i], array[j], array[k]});
                }
            };
        }
    }
    return threesomes;
}

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    if(nums.size() < 3) return {};
    vector<vector<int>> threesomes;
    int* array = this->sort(nums);
    int min = array[0];
    //printf("min is %d\n", min);
    int max = array[nums.size() - 1];
    //printf("max is %d\n", max);
    size_t size = max - min + 1;
    
    vector<int> hash(size, 0);
    //printf("hash table size is %d\n", hash.size());
    size_t j = 0;
    size_t i = 0;
    while(i < size) {
        while((int)i + min == array[j] && j < nums.size()) {
            hash[i]++;
            j++;
        }
        i++;
    }
    
    //printf("try the first one %d\n", hash[0]);
    //printf("try the last one %d\n", hash[size - 1]);
    for(size_t i = 0; i < hash.size(); i++) {
        if(hash[i] == 0) continue;
        if((int)i + min > 0) {
            return threesomes;
        }
        for(size_t j = i; j < hash.size(); j++) {
            if(hash[j] <= (i == j? 1 : 0)) continue;
            if((int)i + min + (int)j + min + min > 0) break;
            if((int)i + min + (int)j + min + max < 0) continue;
            size_t k = 0 - (int)i - min - (int)j - min - min;
            if(k < j) break;
            if(k == j && k == i && hash[i] < 3) continue;
            if(k == j && k != i && hash[j] < 2) continue;
            if(k != j && k != i && hash[k] < 1) continue;
            threesomes.push_back({(int)i + min, (int)(j) + min, (int)k + min});
        }
    }
    return threesomes;
}

int* Solution::sort(vector<int>& nums) {
    size_t pivot = nums.size()/2;
    int* array1 =  this->divide(nums, 0, pivot);
    int* array2 =  this->divide(nums, pivot, nums.size());
    int* array = this->conquer(array1, pivot, array2, nums.size() - pivot);
    return array;
}

int* Solution::divide(vector<int>& nums, size_t head, size_t tail) {
    int* array = new int[tail - head];
    
    if(tail == head) return nullptr;
    else if(tail - head == 1) {
        *array = nums[head];
        return array;
    } else if(tail - head == 2) {
        if(nums[head] <= nums[tail - 1]) {
            array[0] = nums[head];
            array[1] = nums[tail - 1];
            return array;
        }
        else {
            array[0] = nums[tail - 1];
            array[1] = nums[head];
            return array;
        }
    }
    else {
        size_t pivot = (head + tail)/2;
        int* array1 =  this->divide(nums, head, pivot);
        int* array2 =  this->divide(nums, pivot, tail);
        int* array = this->conquer(array1, pivot - head, array2, tail - pivot);
        return array;
    }
}

int* Solution::conquer(int* array1, size_t len1, int* array2, size_t len2) {
    //vector<int> array;
    int* array = new int[len1 + len2];
    size_t i = 0, j = 0;
    while(i < len1 || j < len2) {
        if(i == len1) {array[i + j] = (array2[j]); j++;}
        else if(j == len2) {array[i + j] = (array1[i]); i++;}
        else if(array1[i] <= array2[j]) {
            array[i + j] = (array1[i]);
            i++;
        } else if(array2[j] < array1[i]) {
            array[i + j] = (array2[j]);
            j++;
        }
    }
    return array;
}
#endif /* m15_h */
