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
struct Vertex {

    Vertex(T pLabel) : label(pLabel) {};
    
    void addEdge(T destination,int weight) {
        edges[destination] = weight;
    }
    
    T label;
    unordered_map<T, int> edges;
};

template<typename T>
struct Edge {
	
	Edge() {}
	Edge(T pDestination, int pWeight) : destination(pDestination), weight(pWeight) {}

    
    T    destination;
    int  weight;

    friend bool operator < (const Edge<T>& lhs, const Edge<T>& rhs) {
        return ((lhs.weight < rhs.weight) || (lhs.destination < rhs.destination));
    }

};

template<typename T>
void getMinSpanningTree(unordered_map<T,shared_ptr<Vertex<T>>> nodes, T first, int infinityMarker) {
	
	cout << nodes.size() << endl;
	
    if(nodes.size() == 0) {
        return;
    }
    
    shared_ptr<Vertex<T>> nearestVertex = nodes[first];
    set<Edge<T>> distance;
    
	for(const auto node : nodes) {
		if(node.first == first) continue;
		
        T label    = node.first;
		distance.emplace(Edge<T>(label,infinityMarker));
	}
	
	while (!distance.empty()) {
	
		// Find the nodes for which distance table needs to be updated
		vector<typename set<Edge<T>>::const_iterator> changedNodes;
		for(auto it = distance.begin(); it!=distance.end();++it)
		{
			auto nearestVertexWeight = nearestVertex->edges.find(it->destination);
			
			if(nearestVertexWeight != nearestVertex->edges.end()) {
				if(nearestVertexWeight->second < it->weight) {
					changedNodes.emplace_back(it);
				}
			}
		}
		
		// Update the table
		for(auto changed : changedNodes) {
			Edge<T> edge = *changed;
			edge.weight = nearestVertex->edges[edge.destination];
			distance.erase(changed);
			distance.emplace(edge);
		}
		
		cout << nearestVertex->label << " ";
		// Get the min cost edge
		auto minEdge = distance.begin();
		cout << "<-" << minEdge->weight << "-> " << minEdge->destination << "\n";
		nearestVertex = nodes[minEdge->destination];
		distance.erase(minEdge);
		
		
	}
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
	
	
	unordered_map<string,shared_ptr<Vertex<string>>> vertices;/*(({{v1->label,v1},{v2->label,v2},{v3->label,v3},{v4->label,v4},{v5->label,v5}};*/
	
	vertices[v1->label] = v1;
	vertices[v2->label] = v2;
	vertices[v3->label] = v3;
	vertices[v4->label] = v4;
	vertices[v5->label] = v5;
	
    getMinSpanningTree(vertices,v1->label,numeric_limits<int>::max());

    return 0;
}
