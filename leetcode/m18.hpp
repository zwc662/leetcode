//
//  m18.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/27/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.    \
A solution set is:  \
[   \
 [-1,  0, 0, 1],    \
 [-2, -1, 1, 2],    \
 [-2,  0, 0, 2] \
 ]

#ifndef m18_h
#define m18_h
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;


class Solution {
public:
    int* sort(vector<int>& nums);
    int* divide(vector<int>& nums, size_t head, size_t tail);
    int* conquer(int* array1, size_t len1, int* array2, size_t len2);
    vector<vector<int>> fourSum(vector<int>& nums, int target);
    vector<vector<int>> fourSum_(vector<int>& nums, int target);
    void test(vector<int>& nums, int target);
};

void Solution::test(vector<int>& nums, int target) {
    //nums = {1,-2,-5,-4,-3,3,3,5};
    //target = -11;
    vector<vector<int>> foursomes = this->fourSum(nums, target);

    for(auto i = foursomes.begin(); i != foursomes.end(); i++) {
        //printf("{%d, %d, %d},", (*i)[0], (*i)[1],(*i)[2]);
        for(auto j = i->begin(); j != i->end(); j++) {
            printf("%d ", (*j));
        }
        printf("\n");
    }
}

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target) {
    if(nums.size() < 4) return {};
    vector<vector<int>> foursomes;
    int* array = this->sort(nums);
    //for(int i = 0; i < nums.size(); i++) cout << array[i] << endl;
    for(size_t i = 0; i < nums.size() - 3; i++) {
        if(array[i] + array[i + 1] + array[i + 2] + array[i + 3] > target) return foursomes;
        if(array[i] + array[nums.size() - 3] + array[nums.size() - 2] + array[nums.size() - 1] < target) continue;
        if(i > 0 && array[i] == array[i - 1]) continue;
        for(size_t j = i + 1; j < nums.size() - 2; j++) {
            if(array[i] + array[j] + array[j + 1] + array[j + 2] > target) break;
            if(array[i] + array[j] + array[nums.size() - 2] + array[nums.size() - 1] < target) continue;
            if(j > i + 1 && array[j] == array[j - 1]) continue;
            for(size_t k = j + 1; k < nums.size() - 1; k++) {
                if(array[i] + array[j] + array[k] + array[k + 1] > target) break;
                if(array[i] + array[j] + array[k] + array[nums.size() - 1] < target) continue;
                if(k > j + 1 && array[k] == array[k - 1]) continue;
                for(size_t l = k + 1; l < nums.size(); l++) {
                    if(array[i] + array[j] + array[k] + array[l]> target) break;
                    if(l > k + 1 && array[l] == array[l - 1]) continue;
                    if(array[i] + array[j] + array[k] + array[l]== target) {
                        foursomes.push_back({array[i], array[j], array[k], array[l]});
                    }
                }
            }
        }
    }
    return foursomes;
}


vector<vector<int>> Solution::fourSum_(vector<int>& nums, int target) {
    if(nums.size() < 3) return {};
    vector<vector<int>> foursomes;
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
    
    //for(size_t i = 0; i != hash.size(); i++) {
    //    cout << (int)i + min << " " << hash[i] << endl;
    //}
    //printf("try the first one %d\n", hash[0]);
    //printf("try the last one %d\n", hash[size - 1]);
    for(size_t i = 0; i < hash.size(); i++) {
        if(hash[i] == 0) continue;
        if((int)i + min + (int)i + min + (int)i + min + (int)i + min> target) {
            return foursomes;
        }
        for(size_t j = i; j < hash.size(); j++) {
            if(i == j) {
                if(hash[j] <= 1) continue;
            } else if(hash[j] <= 0) continue;
            if((int)i + min + (int)j + min + (int)j + min + (int)j + min > target) break;
            if((int)i + min + (int)j + min + max + max < target) continue;
            for(size_t k = j; k < hash.size(); k++) {
                if(k == j) {
                    if(j == i) {
                        if(hash[k] <= 2) continue;
                    } else {
                        if(hash[k] <= 1) continue;
                    }
                } else if(hash[k] <= 0) continue;
                if((int)i + min + (int)j + min + int(k) + min + min > target) break;
                if((int)i + min + (int)j + min + int(k) + min + max < target) continue;
                int l = target - (int)i - min - (int)j - min - (int)k - min - min;
                if(l < (int)k) break;
                if(l == k && l == j && l == i && hash[i] < 4) continue;
                if(l == k && l == j && l != i && hash[j] < 3) continue;
                if(l == k && l != j && l != i && hash[k] < 2) continue;
                if(l != k && l != j && l != i && hash[l] < 1) continue;
                //printf("hehe %d, %d, %d, %d\n", i, j, k, l);
                foursomes.push_back({(int)i + min, (int)j + min, (int)k + min, (int)l + min});
            }
        }
    }
    return foursomes;
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

#endif /* m18_h */
