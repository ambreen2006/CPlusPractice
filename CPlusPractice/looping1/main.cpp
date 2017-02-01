//
//  main.cpp
//  looping1
//
//  Created by Ambreen Haleem on 1/26/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//[ 1,5,0,2,7,0 ]


void bubbleDownZeroes(vector<int>& A) {
   
    
    
        size_t i = 0, j = 0;
        while (j < A.size())
        {
            if(A[i] == 0)
            {
                while (A[++j] != 0) {
                    A[i++] = A[j];
                }
            }
            else
            {
                i++;
                j++;
            }
        }
    
       // i--;
        // copy 0's on the right side of i
        while(i < A.size())
        {
            A[i++] = 0;
        }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> vect {1,5,0,2,7,0};
    
    bubbleDownZeroes(vect);
    
    for(const auto& elem : vect) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
