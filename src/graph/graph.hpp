#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
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
    void addEdge(string source, string target);
    void addNode(string key);
    void addDegree(string key);
    void printGraph();
    Graph topologicalSort();
};

#endif // __GRAPH_H__