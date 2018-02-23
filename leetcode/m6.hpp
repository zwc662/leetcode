//
//  m6.hpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/15/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)  \
    P   A   H   N   \
    A P L S I I G   \
    Y   I   R   \
And then read line by line: "PAHNAPLSIIGYIR"    \
Write the code that will take a string and make this conversion given a number of rows: \
    string convert(string text, int nRows); \
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


#ifndef m6_h
#define m6_h
class Solution {
public:
    string convert(string s, int numRows) {
        size_t len = s.size();
        if(len <= numRows) return s;
        string zigzag;
        if(numRows <= 2) {
            for(size_t i = 0; i < numRows; i++) {
                for(size_t j = i; j < s.size(); j = j + numRows) {
                    zigzag = zigzag + string(1, s[j]);
                }
            }
            return zigzag;
        }
        
        int numCols = 2 * len / (numRows + numRows - 2) + (len % (numRows + numRows - 2)) / numRows + ((len % (numRows + numRows - 2)) % numRows > 0? 1 : 0);
        printf("%d", numCols);
        int coord = 0;
        
        for(size_t i = 0; i < numRows; i++) {
            for(size_t j = 0; j < numCols; j++) {
                if(j % 2 == 0) {
                    coord = i + (j / 2) * (numRows + numRows - 2);
                    printf("zig%d", coord);
                } else {
                    if(i == numRows - 1 || i == 0) continue;
                    coord = numRows - 2 - i + (j / 2) * (numRows + numRows - 2) + numRows;
                    printf("zag%d", coord);
                }
                if(coord >= s.size()) continue;
                zigzag = zigzag + string(1, s[coord]);
            }
        }
        return zigzag;
    }
};
#endif /* m6_h */
