//
//  main.cpp
//  CPlusPractice
//
//  Created by Ambreen Haleem on 1/25/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    vector<string> filenames {"prog.dat","mydir","hello.","oops.tmp","end.data"};
    string tmpname;
    const string suffix("tmp");
    
    for(const auto& filename : filenames) {
        
        string::size_type idx = filename.find(".");
        if(idx == string::npos) {
            tmpname = filename + "." + suffix;
        }
        else {
            
            string basename = filename.substr(0,idx);
            string extname = filename.substr(idx+1);
            
            if(extname.empty()) {
                tmpname = filename;
                tmpname += suffix;
            }
            else if (extname == suffix) {
                tmpname = filename;
                tmpname.replace(idx+1, extname.size(), "xxx");
            }
            else {
                tmpname = filename;
                tmpname.replace(idx+1, string::npos, suffix);
            }
        }
        
        cout << filename << " => " << tmpname << endl;
    }
    
    return 0;
}
