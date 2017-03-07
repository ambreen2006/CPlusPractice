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
#include <numeric>

using namespace std;

#define MAX_N 1000
#define LOG_TWO_N 10

class RMQ {
private:
	int _A[MAX_N], SpT[MAX_N][LOG_TWO_N];
public:
	RMQ(int n, int A[]) {
		for (int i = 0; i < n; i++) {
			_A[i] = A[i];
			SpT[i][0] = i;
		}
		
		for(int j = 1; (1 << j) <=n ; j++) {
			for(int i = 0; i + ((1<<j)-1) < n;i++) {
				if(_A[SpT[i][j-1]] < _A[SpT[i+(1 << (j-1))][j-1]])
				{
					SpT[i][j] = SpT[i][j-1];
				}
				else {
					SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
				}
			}
		}
		
	} // end of rmq
	
	int query(int i, int j) {
		int k = (int) floor(log((double)j-i+1)/log(2.0));
		if(_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]])
			return SpT[i][k];
		else
			return SpT[j-(1<<k)+1][k];
	}
};

class RangeSumDP {
public:
	RangeSumDP(const vector<int> _arr) {
		arr = _arr;
		spt.assign(arr.size()+1, 0);
		partial_sum(arr.begin(), arr.end(), spt.begin()+1);
		copy(spt.begin(),spt.end(),ostream_iterator<int>(cout, ","));
	}
	
	int rsq(int i, int j) {
		return (spt[j+1] - spt[i]);
	}
	
private:
	vector<int> spt, arr;
};

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";

	vector<int> arr = {18, 17, 13, 19, 15};
	copy(arr.begin(),arr.end(),ostream_iterator<int>(cout,","));
	cout << endl;
	RangeSumDP dp(arr);
	
	cout << endl;
	cout << "RMQ(0,2) = " << dp.rsq(0,0) << endl;
    return 0;
}
