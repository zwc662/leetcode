//
//  Find All PossibleRecipesFromGivenSupplies.h
//  leetcode
//
//  Created by Weichao  Zhou on 4/21/22.
//  Copyright © 2022 Weichao  Zhou. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

#ifndef FindAllPossibleRecipesFromGivenSupplies_h
#define FindAllPossibleRecipesFromGivenSupplies_h

using namespace std;

class Solution {
public:
    map<string, bool> done;
    map<string, bool> visited;
    map<string, int> ids;
    bool bfs(string recipe, vector<vector<string>>& ingredients);
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies);
    vector<string> toposort(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup);
};

void test(const vector<string>& input_strs) {
            //for(auto i : input_strs) cout<< i << endl;
            vector<string> recipes;
            string recipe;
            for(size_t i = 0; i < input_strs[0].length() - 1; i++) {
                if(input_strs[0].at(i) == ']') break;
                else if(input_strs[0].at(i) == '[')  continue;
                else if(input_strs[0].at(i) == ',') continue;
                else if(input_strs[0].at(i) == '"') {
                    if(recipe.length() > 0) {
                        //cout<< recipe << " ";
                        recipes.push_back(recipe);
                        recipe = "";
                    } else {
                        continue;
                    }
                } else recipe.push_back(input_strs[0].at(i));
            }
            //cout<< endl;
            vector<vector<string>> ingredients;
            vector<string> ingredient;
            string item;
            for(size_t i = 0; i < input_strs[1].length() - 1; i++) {
                if(input_strs[1].at(i) == ']') {
                    if(ingredient.size() > 0) {
                        //cout<< endl;
                        ingredients.push_back(ingredient);
                        ingredient.clear();
                    } else continue;
                }
                else if(input_strs[1].at(i) == '[') {item = ""; continue;}
                else if(input_strs[1].at(i) == ',') {item = ""; continue;}
                else if(input_strs[1].at(i) == '"') {
                    if(item.length() > 0) {
                        ingredient.push_back(item);
                        //cout<< item << " ";
                    }
                    item = "";
                }
                else item.push_back(input_strs[1].at(i));
            }
            
            vector<string> supplies;
            string supply;
            for(size_t i = 0; i < input_strs[2].length() - 1; i++) {
                if(input_strs[2].at(i) == ']') break;
                else if(input_strs[2].at(i) == '[')  continue;
                else if(input_strs[2].at(i) == ',') continue;
                else if(input_strs[2].at(i) == '"') {
                    if(supply.length() > 0) {
                        //cout<< supply << " " << endl;
                        supplies.push_back(supply);
                        supply = "";
                    } else {
                        continue;
                    }
                } else supply.push_back(input_strs[2].at(i));
            }
            
            Solution sol;
            vector<string> result = sol.toposort(recipes, ingredients, supplies);
            for(auto i: result) cout << i << endl;
        }
        
vector<string> Solution::findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    for(auto i = supplies.begin(); i < supplies.end(); i++) {
        this->visited.insert({*i, true});
        this->done.insert({*i, true});
    }
    vector<string> sol;
    for(int i = 0; i < recipes.size(); i++) this->ids.insert({recipes[i], i});
    for(auto i = recipes.begin(); i < recipes.end(); i++) {
        if(this->done.find(*i) != this->done.end() || this->visited.find(*i) != this->visited.end()) continue;
        if(this->bfs(*i, ingredients)) this->done[*i] = true;
    }
    for(auto i = recipes.begin(); i < recipes.end(); i++) {
        if(this->done[*i]) sol.push_back(*i);
    }
    return sol;
}

bool Solution::bfs(string recipe, vector<vector<string>>& ingredients) {
    //if(this->visited[recipe] && !this->done[recipe]) return false;
    
    queue<string> q;
    q.push(recipe);
    
    vector<string> ingredient = ingredients[this->ids[recipe]];
    for(auto i = ingredient.begin(); i < ingredient.end(); i++) {
        string recipe_i = *i;
        if(this->visited.find(*i) != this->visited.end()) {
            if(this->done.find(*i) != this->done.end()) {
                if(this->done[*i]) continue;
            }
            return false;
        }
        this->visited[*i] = true;
        if(this->bfs(*i, ingredients)) continue;
        else return false;
    }
    this->done[recipe] = true;
    return true;
}


vector<string> Solution::toposort(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string,vector<string>> graph;
        int n = (int) rec.size();
        unordered_set<string> s;
        for(auto x : sup) s.insert(x);            //store all the supplies in unordered set
		
        unordered_map<string,int> indegree;   //to store the indegree of all recipes
        for(auto x : rec)indegree[x] = 0;                      //initially take the indegree of all recipes to be 0
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (int)ing[i].size(); j++){
                if(s.find(ing[i][j]) == s.end()){
                    graph[ing[i][j]].push_back(rec[i]);    //if the ingredient required to make a recipe is not in supplies then
                    indegree[rec[i]]++;                     //we need to make a directed edge from that ingredient to recipe
                }
            }
        }
        
        //KAHN'S ALGORITHM
        queue<string> q;
        for(auto x : indegree){
            if(x.second == 0){
                q.push(x.first);
            }
        }
       vector<string> ans;
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto nbr : graph[tmp]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return ans;
    }

#endif /* Find_All_PossibleRecipesFromGivenSupplies_h */
