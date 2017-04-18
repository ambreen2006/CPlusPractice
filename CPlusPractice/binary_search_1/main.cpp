//
//  main.cpp
//  binary_search_1
//
//  Created by ahaleem on 4/17/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <vector>

size_t find(const std::vector<int>& array, int key) {
	
	auto lower = array.begin();
	auto upper = array.end()-1;
	while (lower < upper) {
		auto mid = lower + (upper-lower) /2;
		if(key == *mid) return std::distance(lower,mid);
		if(key < *mid)
			upper = mid-1;
		else
			lower = mid+1;
	}
	
	return std::distance(array.begin(),lower);
}

int main(int argc, const char * argv[]) {
	
	std::vector<int> arr {2,5,11,14};
	auto result = find(arr,5);
	std::cout << result << std::endl;
	return 0;
	
}
