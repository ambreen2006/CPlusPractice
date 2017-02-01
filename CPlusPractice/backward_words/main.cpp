//
//  main.cpp
//  backward_words
//
//  Created by Ambreen Haleem on 1/26/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void solution1() {
    
    string delims = " \t,.;";
    string line;
    while(getline(cin,line)) {
        string::size_type begIndex, endIndex;
        begIndex = line.find_first_not_of(delims);
        cout << begIndex << endl;
        
        while(begIndex != string::npos) {
            endIndex = line.find_first_of(delims,begIndex);
            if(endIndex == string::npos) {
                endIndex = line.length();
            }
            
            for(int i = static_cast<int>(endIndex-1); i>=static_cast<int>(begIndex); --i) {
                cout << line[i];
            }
            
            cout << ' ';
            
            begIndex = line.find_first_not_of(delims,endIndex);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    solution1();
    
    return 0;
}
