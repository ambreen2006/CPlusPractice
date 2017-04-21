//
//  main.cpp
//  binary_search_1
//
//  Created by ahaleem on 4/17/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>

std::pair<bool,size_t> BinarySearch(const std::vector<int>& vect, int key) {
	
	if(vect.size() == 0) return {false,0};
	auto lower = vect.begin();
	auto upper = vect.end()-1;
	
	while (lower < upper) {
		
		auto mid = lower + (upper-lower) /2;
		if(key == *mid)
		{
			return {true,std::distance(vect.begin(),mid)};
		}
		if(key < *mid)
			upper = mid-1;
		else
			lower = mid+1;
	}
	if( *lower == key) {
		return {true,std::distance(vect.begin(),lower)};
	}
	return {false,std::distance(vect.begin(),lower)};
}

int main(int argc, const char * argv[]) {
	
	std::vector<int> arr {5,7,11};
	auto result = BinarySearch(arr,5);
	if(result.first)
		std::cout << result.second << std::endl;
	else
		std::cout << "Not found " << std::endl;
	return 0;
}
