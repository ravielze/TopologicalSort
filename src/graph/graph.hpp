#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <sstream>
#include "../common/RomanNumber.hpp"
using namespace std;

class Graph
{
private:
    map<string, vector<string>> adjList;
    map<string, int> degrees;
    void topologicalSortHelper(int depth);

public:
    Graph();
    Graph(const vector<string> &lines);
    Graph(const Graph &other);
    void addEdge(string target, string source);
    void addNode(string key);
    void addDegree(string key);
    void printGraph();
    void topologicalSort();
};

#endif // __GRAPH_H__