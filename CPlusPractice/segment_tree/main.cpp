//
//  main.cpp
//  segment_tree
//  Code from Competitive Programming 3 book (modified to do range sum query instead of range
//  minimum
//  Created by ahaleem on 2/2/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {

private:
	
	int left(int p) { return p << 1; }
	int right(int p) { return ((p << 1) +1);}
	
	void build(int p, int L, int R) {
		if(L == R)
		{
			st[p] = array[L]; return;
		}
		
		int mid = (L+R)/2;
		
		build(left(p), L, mid);
		build(right(p), mid+1,R);
		
		st[p] = st[left(p)] + st[right(p)];
	}
	
	int rsq(int p, int L, int R, int i, int j) {
		
		// Out of the requested range
		if(i > R || j < L) {
			return 0;
		}
		
		// This means that the current interval represented by [L,R] is within/is [i,j]
		if(L >= i && R <= j) {
			return st[p];
		}
		
		int mid = (L+R)/2;
		int p1 = rsq(left(p), L, mid, i, j);
		int p2 = rsq(right(p), mid+1,R, i, j);
	
		return (p1+p2);
	}
	
public:
	SegmentTree(vector<int> &_array) {
		array = _array;
		st.assign(4*array.size(), 0);
		build(1, 0, (int) (array.size()-1));
	}
	
	int rsq(int i, int j) {
		return rsq(1, 0, (int)(array.size()-1), i, j);
	}
	
	void print() {
		copy(st.begin()+1,st.end(),ostream_iterator<int>(std::cout, ","));
		cout << endl;
	}
	
private:
	vector<int> st, array;
};

int main(int argc, const char * argv[]) {
	// insert code here...
	
	vector<int> arr = {-2, 0, 3, -5, 2, -1};
	SegmentTree st(arr);

	cout << "rsq(0,2) = " << st.rsq(0,2) << endl;
	cout << "rsq(2,5) = " << st.rsq(2,5) << endl;
	cout << "rsq(0,5) = " << st.rsq(0,5) << endl;

	return 0;
}
