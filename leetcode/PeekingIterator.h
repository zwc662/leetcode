//
//  PeekingIterator.h
//  leetcode
//
//  Created by Weichao  Zhou on 9/18/22.
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

#ifndef PeekingIterator_h
#define PeekingIterator_h

class Iterator {
		struct Data;
 		Data* data;
  public:
		Iterator(const vector<int>& nums);
 		Iterator(const Iterator& iter);

 		// Returns the next element in the iteration.
		int next();

		// Returns true if the iteration has more elements.
		bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    int* cur = nullptr;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        
        if(cur == nullptr) cur = new int(Iterator::next());
        return *cur;
    }
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(cur == nullptr) return Iterator::next();
        else {
            int res = *cur;
            cur = nullptr;
            return res;
        }
	}
	
	bool hasNext() const {
	    if(cur == nullptr && !Iterator::hasNext()) return false;
        else return true;
	}
};

void test(const vector<string>& input_strs) {
    vector<string> cmds = ReadOneDimStrArray(input_strs[0]);
    vector<vector<int>> args = ReadTwoDimIntArray(input_strs[1]);
    PeekingIterator* pi = new PeekingIterator(args[0]);
    for(int i = 0; i < cmds.size(); i++) {
        if(cmds[i] == "PeekingIterator") continue;
        else if(cmds[i] == "peek") cout << "peek " << pi->peek() << endl;
        else if(cmds[i] == "next") cout << "next " << pi->next() << endl;
        else if(cmds[i] == "hasNext") cout << "hasNext " << pi->hasNext() << endl;
    }
    
}

 
#endif /* PeekingIterator_h */

