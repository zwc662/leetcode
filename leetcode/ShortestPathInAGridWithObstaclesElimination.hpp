//
//  ShortestPathInAGridWithObstaclesElimination.h
//  leetcode
//
//  Created by Weichao  Zhou on 4/19/22.
//  Copyright © 2022 Weichao  Zhou. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
  
using namespace std;
using std::cout; using std::endl;
using std::cin; using std::string;

#ifndef ShortestPathInAGridWithObstaclesElimination_h
#define ShortestPathInAGridWithObstaclesElimination_h

class Solution {
public:
    void test(const vector<string>& input_strs) {
        vector<vector<int>> grid;
        vector<int> grid_i;
        for(size_t i = 1; i < input_strs[0].length() - 1; i++) {
            if(input_strs[0].at(i) == ']') grid.push_back(grid_i);
            else if(input_strs[0].at(i) == '[') grid_i.clear();
            else if(input_strs[0].at(i) == ',') continue;
            else grid_i.push_back(input_strs[0].at(i) - '0');
        }
        
        //for(auto i: grid) {
        //    for(int j: i) cout << j << " ";
        //    cout << endl;
        //}
        string k_str = input_strs[1];
        int k;
        sscanf(k_str.data(), "%d", &k);
        //cout << k << endl;
        cout << shortestPath(grid, k) << endl;
    }
protected:
    struct Pos{
        int x;
        int y;
        int dist;
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
       // At a particular cell we will store the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
		
		// queue stores (x,y,current path length,number of obstacles we can still remove)
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1];
            q.pop();
			
			// Exit if current position is outside of the grid
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                continue;
            }
			
			// Destination found
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return t[2];

            if(grid[x][y]==1){
                if(t[3]>0) // If we encounter an obstacle and we can remove it
                    t[3]--;
                else
                    continue;
            }
			
			// The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
			// Then we don't need to continue on our current path
            if(vis[x][y]!=-1 && vis[x][y]>=t[3])
                continue;
            vis[x][y]=t[3];
            
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
            
        }
        return -1;
    }
};






#endif /* ShortestPathInAGridWithObstaclesElimination_h */
