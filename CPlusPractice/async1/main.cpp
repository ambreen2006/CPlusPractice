//
//  main.cpp
//  async1
//
//  Created by Ambreen Haleem on 3/16/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <random>
#include <thread>
#include <future>

using namespace std;

int doSomething(char c) {
    
    default_random_engine dre(c);
    uniform_int_distribution<int>  id(19,1000);
    
    for(int i = 0; i < 10; i++) {
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }
    return c;
}

int func1() {
    return doSomething('.');
}

int func2() {
    return doSomething('+');
}

int main(int argc, const char * argv[]) {
    cout << "starting func1() in background and func2() in foreground: \n";
    future<int> result1(async(func1));
    int result2 = func2();
    int result = result1.get()+ result2;
    
    cout << "\nresult of funct1() + func2(): " << result << endl;
    
    return 0;
}
