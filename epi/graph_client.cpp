#include "graph.h"

int main()
{
    Graph g({1, 2, 3, 4, 5, 6, 7, 8, 9});
    g.addedge(1, 2);
    g.addedge(1, 3);
    g.addedge(2, 4);
    g.addedge(4, 7);
    g.addedge(3, 5);
    g.addedge(3, 6);
    g.addedge(5, 7);
    g.addedge(6, 8);
    g.addedge(6, 9);

    cout << "Print graph" << endl;
    g.print();

    cout << endl << "DFS traversal" << endl;
    DFS(g, 1);

    cout << endl << "BFS traversal" << endl;
    BFS(g, 1);

    return 0;
}
