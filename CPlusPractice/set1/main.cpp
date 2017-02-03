//
//  main.cpp
//  set1
//
//  Created by Ambreen Haleem on 2/1/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    set<int, greater<int>> coll1;
    coll1.insert({4,3,5,1,6,2});
    coll1.emplace(5);
    
    for(const int& elem : coll1) {
        cout << elem << " ";
    }
    cout << endl;
    
    // insert 4 again
    auto status = coll1.emplace(4);
    if(status.second) {
        cout << "4 inserted as element " << distance(coll1.begin(), status.first) + 1 << endl;
    }
    else {
        cout << "4 already exists " << endl;
    }
    
    set<int> coll2(coll1.begin(), coll1.end());
    copy(coll2.cbegin(),coll2.cend(),ostream_iterator<int>(cout, " "));
    cout << endl;
    
    cout << "After deleting upto 3 "<< endl;
    coll2.erase(coll2.begin(), coll2.find(3));
    copy(coll2.cbegin(),coll2.cend(),ostream_iterator<int>(cout, " "));
    cout << endl;
    
    cout << "Removing all 5 "<< endl;
    
    size_t num;
    num = coll2.erase(5);
    cout << num << " elements removed " << endl;
    
    // print all elelemts
    copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
