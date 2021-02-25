#include "graph/graph.hpp"
#include "reader/reader.hpp"
using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Please input the name file in the second arguments." << endl;
        return 1;
    }
    Reader r(argv[1]);
    Graph g(r.getLines());
    g.topologicalSort();
    return 0;
}