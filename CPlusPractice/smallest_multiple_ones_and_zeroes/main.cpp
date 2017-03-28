//
//  main.cpp
//  smallest_multiple_ones_and_zeroes
//
//  Created by Ambreen Haleem on 3/23/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <limits>

using namespace std;

pair<bool,vector<int>> computeSubsetSums(unordered_map<int, vector<int>>& table,int power, int newMod, int M) {
    
    if(newMod == 0) {
        return {true,{power}};
    }
    
    vector<pair<int,vector<int>>> newSubsets;
    for(auto it = table.begin(); it != table.end(); it++) {
        
        int subsum = it->first + newMod;
        if((subsum % M) == 0)
        {
            vector<int> allPowers = it->second;
            allPowers.emplace_back(power);
            return {true,allPowers};
        }
        
        if(table.find(subsum) == table.end()) {
            vector<int> temp = it->second;
            temp.emplace_back(power);
            newSubsets.emplace_back(subsum,temp);
        }
    }
    
    for(auto& newSet : newSubsets ) {
        table[newSet.first] = newSet.second;
    }
    
    if (table.find(newMod) == table.end()) {
        table[newMod] = { power };
    }
    
    return {false,{}};
}

int reconstructNumber(vector<int>& powers) {
    
    int targetNumber = 0;
    int MAX = numeric_limits<int>::max();
    
    for(auto it = powers.begin(); it != powers.end();it++) {
        
        if (*it > 9) {
            cout << "Overflow \n";
            return MAX;
        }
        
        int value = pow(10, *it);
        if(targetNumber > MAX-value) {
            cout << "Overflow error \n";
            return MAX;
        }
        
        targetNumber += value;
    }

    return targetNumber;
}

int findSmallestMultiple(int M) {

    assert(M > 0);
    
    if(M == 1) {
        return 1;
    }
    
    int tenMultiples = 10;
    int modMultiplier = 10 % M;
    
    unordered_map<int, vector<int>> table;
    
    table[1] = {0};
    auto result = computeSubsetSums(table, 1, modMultiplier, M);
    if(result.first) {
        return reconstructNumber(result.second);
    }
    
    for(int i = 2; i < M+1; i++) {
        
        int newMod = (tenMultiples*modMultiplier) % M;
        auto result = computeSubsetSums(table,i,newMod,M);
        if(result.first) {
            return reconstructNumber(result.second);
            break;
        }
        
        tenMultiples = newMod;
        
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    

    for(int i = 1; i < 10; i++) {
        cout << "Smallest multiplier of i = " << i << " is " << findSmallestMultiple(i) << "\n";
    }
  
    return 0;
}
