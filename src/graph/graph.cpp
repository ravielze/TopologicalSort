#include "graph.hpp"

Graph::Graph()
{
}

Graph::Graph(const vector<string> &lines)
{
}

Graph::Graph(const Graph &other)
{
    this->adjList = map<string, vector<string>>(other.adjList);
    this->degrees = map<string, int>(other.degrees);
}

void Graph::addEdge(string source, string target)
{
    this->addNode(source);
    this->addNode(target);
    this->adjList[source].push_back(target);
    this->addDegree(target);
}

void Graph::addNode(string key)
{
    if (this->adjList.find(key) == this->adjList.end())
    {
        this->adjList.insert({key, vector<string>()});
        this->degrees.insert({key, 0});
    }
}

void Graph::addDegree(string key)
{
    if (this->adjList.find(key) == this->adjList.end())
    {
        this->adjList.insert({key, vector<string>()});
        this->degrees.insert({key, 0});
    }
    else
    {
        this->degrees[key]++;
    }
}

void Graph::printGraph()
{
    map<string, vector<string>>::iterator itr;
    for (itr = this->adjList.begin(); itr != this->adjList.end(); ++itr)
    {
        cout << itr->first << '\t: ';
        for (string t : itr->second)
        {
            cout << t << ' ';
        }

        cout << endl;
    }
}

Graph Graph::topologicalSort()
{
    Graph copy((*this));
    copy.topologicalSortHelper(1);
    return copy;
}

void Graph::topologicalSortHelper(int depth)
{
}
