//
//  main.cpp
//  priority_queue1
//
//  Created by Ambreen Haleem on 2/8/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CharCardinality {
    
    size_t count;
    char   symbol;
    
    bool operator >(const CharCardinality& obj) const {
        return (count > obj.count);
    }
    
    bool operator <(const CharCardinality& obj) const {
        return (count < obj.count);
    }
};

int main(int argc, const char * argv[]) {

    priority_queue<CharCardinality,vector<CharCardinality>, std::greater<CharCardinality>> minQueue;
    
    CharCardinality a({10,'a'}),b({5,'b'}),c({15,'c'});
    
    minQueue.emplace(a);
    minQueue.emplace(b);
    minQueue.emplace(c);
    
    auto temp = minQueue.top();
    minQueue.pop();
    cout << temp.symbol << " " << temp.count << endl;
    
    temp = minQueue.top();
    minQueue.pop();
    cout << temp.symbol << " " << temp.count << endl;
    
    temp = minQueue.top();
    minQueue.pop();
    cout << temp.symbol << " " << temp.count << endl;
    
    return 0;
}
