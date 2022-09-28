//
//  main.cpp
//  leetcode
//
//  Created by Weichao  Zhou on 2/7/18.
//  Copyright © 2018 Weichao  Zhou. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include "SortList.h"

using namespace std;

int main( int argc, char ** argv ) {
    std::ifstream myfile; myfile.open("input.txt");
    std::string mystring;
    vector<std::string> input_strs;
    while(getline(myfile, mystring)) input_strs.push_back(mystring);
    
    test(input_strs);
}

