//
//  main.cpp
//  naive_string_matching
//
//  Created by Ambreen Haleem on 3/28/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <utility>
#include <limits>

using namespace std;

/*
 * Returns after first occurance found.
 */
pair<bool,int> isSubstring(string& T, string& P) {
    
    for(size_t i = 0; i < (T.length()-P.length()+1); i++)
    {
        bool found = true;
        for(size_t j = 0; j < P.length(); j++) {
        
            if(T[i+j] != P[j]) {
                found = false;
                break;
            }
        }
        
        if(found) {
            return {true,i};
        }
        
    }
    
    return {false,std::numeric_limits<size_t>::max()};
}

int main(int argc, const char * argv[]) {
    
    string T = "abccdab";
    string P = "cd";
    auto result = isSubstring(T, P);
    
    cout << result.first << " " << result.second << "\n";
    
    return 0;
}
