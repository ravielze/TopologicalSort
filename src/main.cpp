#include "graph/graph.hpp"
#include "reader/reader.hpp"
using namespace std;

int main()
{
    Graph x;
    x.addEdge("ke1", "si1");
    x.addEdge("ke2", "si2");
    x.addEdge("ke3", "si3");
    x.addEdge("ke3", "si1");
    x.printGraph();
    cout << endl;
    Graph y(x);
    y.addEdge("si1", "si4");
    y.addEdge("si2", "si4");
    y.addEdge("si3", "si4");
    x.printGraph();
    cout << endl;
    y.printGraph();
    cout << endl;
    x.printGraph();
    return 0;
}