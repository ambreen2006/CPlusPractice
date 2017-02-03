//
//  main.cpp
//  setrange1
//
//  Created by Ambreen Haleem on 2/1/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    multiset<int> c;
    c.insert(1);
    c.insert(2);
    c.insert(4);
    c.insert(5);
    c.insert(5);
    c.insert(7);
    
    cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
    cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
    cout << "equal_range(3): " << *c.equal_range(3).first << " " << *c.equal_range(3).second << endl;
    
    cout << endl;
    
    cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
    cout << "equal_range(5): " << *c.equal_range(5).first << " " << *c.equal_range(5).second << endl;

    cout << endl;
    
    // testing move
    set<int> collect1 {1,2,3};
    
    cout << "Size of collect1 " << collect1.size() << endl;
    
    set<int> collect2(move(collect1));
    
    cout << "Size of collect1 " << collect1.size() << endl;
    cout << "Size of collect2 " << collect2.size() << endl;
    
    cout << "Finding 1: " << *collect2.find(1) << endl;
    cout << "Finding 2: " << *collect2.find(2) << endl;
    
    for(const auto& elem : collect2) {
        cout << elem << " ";
    }
    cout << endl;
    
    auto iter =  collect2.cbegin();
    cout << *iter;
    
    cout << endl;
    
    return 0;
}
