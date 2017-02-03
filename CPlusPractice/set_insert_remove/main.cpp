//
//  main.cpp
//  set_insert_remove
//
//  Created by Ambreen Haleem on 2/1/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    set<double> c;
    pair<set<double>::iterator,bool> status = c.insert(3.3);
    
    if(status.second) {
        cout << "3.3 inserted " << endl;
    }
    else
        cout << "3.3 already exists" << endl;
    
    
    cout << distance(c.begin(), status.first) + 1 << endl;
    //double value = 8.9;
    //auto status = c.insert(value);
    
    multiset<string> names {"ambreen", "bhai", "ambreen"};
    for (auto name = names.cbegin(); name != names.cend(); name++) {
        cout  << *name << " ";
    }

    cout << endl;
    multiset<string>::iterator pos = names.find("ambreen");
    if(pos!=names.end()) {
        
        cout << *pos << endl;
        names.erase(pos);
    }

    for (auto name = names.cbegin(); name != names.cend(); name++) {
        cout  << *name << " ";
    }
    
    cout << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
