//
//  m11.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/21/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

//Note: You may not slant the container and n is at least 2.

//for (l, r > l + 1), if h(l) < h(r), then it's sure that f(l+1, r) > f(l, l+1), \\
because no matter how r-(l+ 1) is (r-(l+1) >= 1 any way), min(r, l+1) > min(l, l+1),\\
so f(l, l+1) < f(l+1, r)\\
same if h(l) > h(r), just change the direction

#ifndef m11_h
#define m11_h
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for(size_t i = 0; i < height.size() - 1; i++) {
            for(size_t j = height.size() - 1; j != i; j++) {
                int v = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
                max = max < v ? v : max;
            }
        }
        return max;
    }
};

#endif /* m11_h */
