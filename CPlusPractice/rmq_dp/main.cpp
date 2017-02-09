//
//  main.cpp
//  rmq_dp
//
//  Created by ahaleem on 2/2/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int rmq(int i, int j, vector<int>& array) {
    
    int result = 0;
    vector<vector<int>> M;
    size_t N = array.size();
    
    M.assign(N, vector<int>(log2(N)+1,-1));
    
    
    return result;
}

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
    
    int N = 16;
    vector<int> array {2,4,3,1,6,7};
    rmq(1, 3, array);
    
    cout << endl;
    return 0;
}
