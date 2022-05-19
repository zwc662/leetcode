//
//  e26.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/28/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
//Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length. Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

//Example:  \
    Given nums = [1,1,2],   \
    Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. \
    It doesn't matter what you leave beyond the new length.
//Shithole problem doesn't knwo if to output 'int' or 'vector<int>'

#ifndef e26_h
#define e26_h
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        for(size_t i = 1; i < nums.size();) {
            if(nums[i] != nums[i-1]) i++;
            else nums.erase(nums.begin() + i, nums.begin() + i + 1);
        }
        return nums.size();
    }
};

#endif /* e26_h */
