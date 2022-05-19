//
//  h4.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/12/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
/*There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 Example 1:
nums1 = [1, 3]
nums2 = [2]
 
The median is 2.0
 
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
 */


#ifndef h4_h
#define h4_h

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

double Solution::findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {
    size_t len1 = array1.size();
    size_t len2 = array2.size();
    vector<int> nums1(array1);
    vector<int> nums2(array2);
    
    if(len1 > len2) {
        nums1 = array2;
        nums2 = array1;
        len1 = nums1.size();
        len2 = nums2.size();
    }
    
    if(len1 == 0) {
        if(len2%2 == 0) {
            printf("hehe");
            return (nums2[len2/2] + nums2[len2/2 - 1]) / 2.0;
        }
        else return nums2[len2/2];
    }
    
    int max = len1;
    int min = 0;
    int total = (len1 + len2 + 1)/2;
    int id1 = 0; int id2 = 0;
    
    while(min <= max) {
        id1 = (max + min)/2;
        id2 = total - id1;
        if(id1 < len1 && nums1[id1] < nums2[id2 - 1]) {
            min = id1 + 1;
        } else if(id1 > 0 && nums1[id1 - 1] > nums2[id2]) {
            max = id1 - 1;
        } else {
            int left = 0;
            if(id1 == 0) left = nums2[id2 - 1];
            else if(id2 == 0) left = nums1[id1 - 1];
            else left = (nums1[id1 - 1] > nums2[id2 - 1] ? nums1[id1 - 1] : nums2[id2 - 1]);
            if((len1 + len2)%2 == 1) return left;
            
            int right = 0;
            if(id1 == len1) right = nums2[id2];
            else if(id2 == len2) right = nums1[id1];
            else right = (nums1[id1] < nums2[id2] ? nums1[id1] : nums2[id2]);
            
            return (left + right) / 2.0;
        }
    }
}
#endif /* h4_h */
