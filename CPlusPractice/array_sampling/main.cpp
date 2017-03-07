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


int findIndex(int startIndex,int element,vector<int>& arraySet) {
	int i = startIndex;
	for(; i < arraySet.size(); i++) {
		if(element < arraySet[i]) {
			return i;
		};
	}
	return -1;
}

vector<size_t> numWays(vector<vector<int>>& arrays, size_t& N, size_t& K, size_t currentSet) {
	
	vector<size_t> intermediateWays(N,0);

	if(currentSet == K) {
		iota(intermediateWays.rbegin(),intermediateWays.rend(),1);
		return intermediateWays;
	}

	auto ways = numWays(arrays, N, K, (currentSet+1));
	int index = 0;
	
	for(int i = 0; i < N; i++) {
		index = findIndex(index, arrays[currentSet-1][i], arrays[currentSet]);
		if(index >= 0)
			intermediateWays[i] = ways[index];
	}
	
	return intermediateWays;
}

size_t numWaysArraySampling(vector<vector<int>>& arrays)
{
	if(arrays.size() == 0) return 0;
	
	size_t K = arrays.size();
	size_t N = arrays[0].size();
	
	vector<vector<int>> sortedArrays(arrays);
	for(auto& anArray : sortedArrays) {
		sort(anArray.begin(), anArray.end());
	}
	
	auto ways = numWays(sortedArrays, N, K, 1);
	return accumulate( ways.begin(), ways.end(), 0);
}

int main(int argc, const char * argv[]) {

	vector<vector<int>> arrays {{10,2,1},{1,1,6}, {7,8,9}};
	cout << numWaysArraySampling(arrays) << "\n";
    return 0;
}
