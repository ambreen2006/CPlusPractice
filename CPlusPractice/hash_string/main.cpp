//
//  main.cpp
//  hash_string
//
//  Created by Ambreen Haleem on 3/28/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <functional>
#include <chrono>
#include <limits>

using namespace std;

unsigned int customHash(string str,unsigned int tableSize) {
    unsigned int h = 0;
    for(const auto& ch: str) {
        h = h*37+ch;
    }
    
    h = h%tableSize;
    return h;
}

int main(int argc, const char * argv[]) {
    string str = "The way I measure performance for optimization is extremely casual. It isn’t informed by great knowledge of statistics. My tests run for seconds, not hours. I don’t feel the need to apologize for this casual approach. These methods translate into human-visible performance improvements in overall program run time, so I must be on the right track.If I run the same timing experiment on two different days, I get results that may differ by somewhere between 0.1% and 1%. This is no doubt due to differences in initial conditions in my PC. I have no way to control these conditions, so I dont worry. If I see larger variations, I can make the timing runs longer. As this makes my test/debug cycles longer, I dont do it unless I see a need to.Even when I see variation of a few percent between runs, relative variation of timing measurements within a single run seems to be way below 1%. That is, I can see even relatively subtle changes by timing two variations of a function in the same test run. I try to make timing runs on a quiet computer that isn’t streaming video, running a Java update, or uncompressing a big archive. I try not to move the mouse or switch windows during a timing run. When PCs contained only one processor core, this was really important. With modern multicore processors, I don’t notice much variation even if I forget to turn off Pandora. If a timing test calls a function 10,000 times, that code and related data are going to remain in cache. If I were doing a test of worst-case absolute time for a hard real-time system, that would matter. But I am doing a relative time measurement on a system whose kernel is already nondeterministic. Furthermore, I’m testing only functions that my profiler has already identified as hot. They will thus be in cache already during production runs, so the iterated test actually represents realistic conditions.    If a modified function appears to be 1% faster, it’s generally not worth modifying. Amdahl’s Law will shrink its small contribution to overall run time to insiginficance. An improvement of 10% has marginal value. A change of 100% is far more interesting. Accepting only large changes in performance frees the developer from worrying about methodology.      Create a Stopwatch Class To time part of a program, instrument the code with a stopwatch class. The class works exactly like a mechanical stopwatch. Instantiate the stopwatch or call its start() member function, and the stopwatch begins to tick. Call the stopwatch’s stop() member function or destroy the stopwatch class instance, and the stopwatch stops ticking and displays the elapsed time. It’s not hard to build a stopwatch class, and there are plenty available on the Internet. Example 3-3 shows one I have used.";
    
   
    auto start_time = chrono::system_clock::now();
    cout << customHash(str, numeric_limits<unsigned int>::max()-1) << endl;
    cout << "Duration: " << (chrono::system_clock::now() - start_time).count() << "\n";
    
    start_time = chrono::system_clock::now();
    cout << hash<string>{}(str) << "\n";
    cout << "Duration: " << (chrono::system_clock::now() - start_time).count() << "\n";

    return 0;
}
