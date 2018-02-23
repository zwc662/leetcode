//
//  e1_twosum.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/7/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
#include<vector>
#include<map>
using namespace std;
#ifndef e1_twosum_h
#define e1_twosum_h

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target);
    void test();
};

vector<int> Solution::twoSum1(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i ++) {
        for(int j = i + 1; j < nums.size(); j ++) {
            if(nums[i] + nums[j] == target) {
                vector<int> a = {i, j};
                return a;
            }
        }
    }
    return vector<int>{NULL, NULL};
}
/*
 To improve our run time complexity, we need a more efficient way to check if the complement exists in the array. If the complement exists, we need to look up its index. What is the best way to maintain a mapping of each element in the array to its index? A hash table.
 
vector<int> Solution::twoSum2(vector<int>& nums, int target) {
    map<int, int> map_ = new map<>();
    for (int i = 0; i < nums.size(); i++) {
        map_.put(nums[i], i);
    }
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map_.containsKey(complement) && map_.get(complement) != i) {
            return vector<int>{ i, map_.get(complement)};
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
*/

/*
 It turns out we can do it in one-pass. While we iterate and inserting elements into the table, we also look back to check if current element's complement already exists in the table. If it exists, we have found a solution and return immediately.
 
 
 
 public int[] twoSum(int[] nums, int target) {
 Map<Integer, Integer> map = new HashMap<>();
 for (int i = 0; i < nums.length; i++) {
 int complement = target - nums[i];
 if (map.containsKey(complement)) {
 return new int[] { map.get(complement), i };
 }
 map.put(nums[i], i);
 }
 throw new IllegalArgumentException("No two sum solution");
 }
*/
#endif /* e1_twosum_h */
