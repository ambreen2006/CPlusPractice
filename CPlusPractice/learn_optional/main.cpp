//
//  main.cpp
//  learn_optional
//
//  Created by Ambreen Haleem on 4/14/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <experimental/optional>
#include <utility>

using namespace std;

std::experimental::optional<int> create_node(int a, bool flag)
{
    if(flag) return a;
    else return {};
}

int main(int argc, const char * argv[]) {
    
    std::experimental::optional<int> a(std::experimental::nullopt);
    std::experimental::optional<int> b(17);
    std::experimental::optional<int> c = create_node(31, true);
    
    
   // std::vector<experimental::optional<int>> nodes;//{create_node(51, true)};
    //{10,4,15,std::experimental::optional<int>(std::experimental::nullopt),7};
    
    if(a)
        std::cout << "a has a value\n";
    if(b)
        std::cout << "b has a value\n";
    
    return 0;
}
