//
//  main.cpp
//  permutation_1
//
//  Created by ahaleem on 3/2/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> permSet {1,2,3,4};

void heapPermutation(size_t n) {
	if(n == 0) {
		cout << "{ ";
		copy(permSet.begin(),permSet.end(),ostream_iterator<int>(cout,","));
		cout << " }\n";
	}
	for(int i = 0; i<n; i++) {
		heapPermutation(n-1);
		if(n % 2 == 0) {
			auto temp = permSet[i];
			permSet[i] = permSet[(n-1)];
			permSet[(n-1)] = temp;
		}
		else {
			auto temp = permSet[0];
			permSet[0] = permSet[(n-1)];
			permSet[(n-1)] = temp;
		}
	}
}

int main(int argc, const char * argv[]) {
	// insert code here...
	heapPermutation(permSet.size());
    return 0;
}
