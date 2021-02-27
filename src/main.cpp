#include "graph/graph.hpp"
#include "reader/reader.hpp"
#include <chrono>
using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Please input the name file in the second arguments." << endl;
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    Reader r(argv[1]);
    Graph g(r.getLines());
    if (argc >= 3)
    {
        int a = atoi(argv[2]);
        g.setTab(a);
    }
    g.topologicalSort();
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> time_span = t2 - t1;
    cout << "Waktu yang dibutuhkan: " << time_span.count() / 1000 << " detik." << endl;
    return 0;
}