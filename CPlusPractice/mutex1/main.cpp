//
//  main.cpp
//  mutex1
//
//  Created by Ambreen Haleem on 3/21/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <mutex>
#include <future>

std::mutex m;

void print(const std::string& s) {
    std::lock_guard<std::mutex> g(m);
    for(const char& ch: s) {
        std::cout.put(ch);
    }
    std::cout << "\n";
}

int main(int argc, const char * argv[]) {
    
    auto f1 = std::async(std::launch::async, print,"Ambreen is awesome!");
    auto f2 = std::async(std::launch::async, print, "I rock!");
    
    print("Hello World!");
    
    return 0;
}
