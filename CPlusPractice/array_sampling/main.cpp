//
//  main.cpp
//  array_sampling
//
//  Created by ahaleem on 3/7/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int FindIndex(int startIndex,int element,vector<int>& arraySet) {
	int i = startIndex;
	for(; i < arraySet.size(); i++) {
		if(element < arraySet[i]) {
			return i;
		};
	}
	return -1;
}

vector<size_t> NumWays(vector<vector<int>>& arrays, size_t& N, size_t& K, size_t setId) {

	vector<size_t> waysTable(N,0);
	if(setId == (K-1)) {
		iota(waysTable.rbegin(),waysTable.rend(),1);
		return waysTable;
	}
	
	auto ways = NumWays(arrays, N, K, (setId+1));
	int index = 0;
	
	for(int i = 0; i < N; i++) {
		index = FindIndex(index, arrays[setId][i], arrays[setId+1]);
		if(index >= 0) {
			waysTable[i] = ways[index];
		}
	}
	
	return waysTable;
}

size_t NumWaysArraySampling(vector<vector<int>>& arrays)
{
	if(arrays.size() == 0) return 0;
	
	size_t K = arrays.size();
	size_t N = arrays[0].size();
	
	vector<vector<int>> sortedArrays(arrays);
	for(auto& anArray : sortedArrays) {
		sort(anArray.begin(), anArray.end());
	}
	
	auto ways = NumWays(sortedArrays, N, K, 0);
	return accumulate(ways.begin(), ways.end(), 0);
}

int main(int argc, const char * argv[]) {

	vector<vector<int>> arrays {{10,2,1},{1,1,6}, {7,8,9}};
	cout << NumWaysArraySampling(arrays) << "\n";
	
	arrays  = {{2,3,0},{4,2,1}};
	cout << NumWaysArraySampling(arrays) << "\n";
	
    return 0;
}
