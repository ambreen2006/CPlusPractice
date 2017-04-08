//
//  main.cpp
//  prim_algorithm
//
//  Created by Ambreen Haleem on 4/4/17.
//  Copyright © 2017 Ambreen Haleem. All rights reserved.
//

#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>

using namespace std;

template<typename T>
class Edge;


template<typename T>
struct Vertex {

    Vertex(T pLabel) : label(pLabel) {};
    
    void addEdge(T destination,int weight) {
        
        Edge<T> edge;
        edge.destination = destination;
        edge.weight = weight;
        
        edgesMap[destination] = weight;
    }
    
    T label;
    unordered_map<T, Edge<T>> edgesMap;
};


template<typename T>
struct Edge {
    
    T    destination;
    int  weight;
    
    friend bool operator > (const Edge<T>& lhs, const Edge<T>& rhs) {
        return lhs.weight > rhs.weight;
    }
    
    friend bool operator < (const Edge<T>& lhs, const Edge<T>& rhs) {
        return lhs.weight < rhs.weight;
    }

};

template<typename T>
void getMinSpanningTree(vector<shared_ptr<Vertex<T>>> nodes, int infinityMarker) {
    
    if(nodes.size() == 0) {
        return;
    }
    
    shared_ptr<Vertex<T>> nearestVertex = nodes[0];
    set<Edge<T>> distance;
    
    for(int i = 1; i < nodes.size(); i++) {
    
        T label = nodes[i]->label;
        distance.insert({nodes[i]->label,infinityMarker});
    }
    
    for(auto it = distance.begin(); it!=distance.end();)
    {
        
    }
    
    /*
    for(auto& node : distance) {
        
        auto nodePtr = node.destination.lock();
        if(!nodePtr) continue;
        
        auto it = nearestVertex->edgesMap.find(nodePtr->label);
        if(it!=end && it->second.weight < node.weight) {
            //node.weight = it->second.weight;
        }
        
    }*/
    /*
    unordered_map<T,T>   nearest;
    unordered_map<T,int> distance;
    
    for(int i = 1; i < nodes.size(); i++) {
        
        T    label = nodes[i]->label;
        auto edge  = nearestVertex->edgesMap.find(label);

        nearest[label]  = nearestVertex->label;
        distance[nodes[i]->label] = (edge!= nearestVertex->edgesMap.end()) ? (edge->second).weight : infinityMarker;
    
    }

    int min = infinityMarker;

    int count =  (int)nodes.size();
    while(count > 1) {
        
        
        
        count--;
    }
    */
}

int main(int argc, const char * argv[]) {
    
    
    shared_ptr<Vertex<string>> v1 = make_shared<Vertex<string>>("V1");
    shared_ptr<Vertex<string>> v2 = make_shared<Vertex<string>>("V2");
    shared_ptr<Vertex<string>> v3 = make_shared<Vertex<string>>("V3");
    shared_ptr<Vertex<string>> v4 = make_shared<Vertex<string>>("V4");
    shared_ptr<Vertex<string>> v5 = make_shared<Vertex<string>>("V5");
    
    v1->addEdge("V2", 1);
    v1->addEdge("V3", 3);
    
    v2->addEdge("V1", 1);
    v2->addEdge("V3", 3);
    v2->addEdge("V4", 6);
    
    v3->addEdge("V1", 3);
    v3->addEdge("V2", 3);
    v3->addEdge("V4", 4);
    v3->addEdge("V5", 2);

    v5->addEdge("V2", 3);
    
    vector<shared_ptr<Vertex<string>>> vertices {v1,v2,v3,v4,v5};
    
    getMinSpanningTree(vertices,numeric_limits<int>::max());

    return 0;
}
