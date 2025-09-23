#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{
public:
    map<int, list<int>> adj;

    void insertNodes(int u, int v, bool isUndirected)
    {
        adj[u].push_back(v);
        if (isUndirected)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (const auto &i : adj)
        {
            cout << i.first << " -> ";
            for (const auto &j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    int nodes;
    cout << "Enter the total number of nodes: ";
    cin >> nodes;

    int edges;
    cout << "Enter the total number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v; 
        g.insertNodes(u, v, false);
    }

    g.printGraph();

    return 0;
}
