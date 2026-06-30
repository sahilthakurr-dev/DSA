/*
  graph2.cpp

  Educational Graph class demonstrating DFS and BFS traversals in C++.

  - Graph supports dynamic addition of edges even when constructed with zero vertices.
  - addEdge(u, v, undirected) will auto-resize internal adjacency list if needed.
  - dfs(start = -1) and bfs(start = -1):
      - start >= 0 : traverse starting from that node (single-component traversal).
      - start == -1: perform a full traversal covering all components.
  - Inline comments explain algorithmic steps for learners.

  Compile:
    g++ -std=c++17 graph2.cpp -o graph2

  Run:
    ./graph2
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::max;

/*
  Simple, modular Graph class with adjacency list representation.
  Vertices are represented by non-negative integer indices (0, 1, 2, ...).
*/
class Graph {
private:
    vector<vector<int>> adj; // adjacency list

    // Ensure internal adjacency list can hold vertex 'v'.
    void ensureVertex(int v) {
        if (v >= static_cast<int>(adj.size())) {
            adj.resize(v + 1);
        }
    }

    // Recursive helper for DFS
    void dfsUtil(int node, vector<bool> &visited, vector<int> &order) {
        visited[node] = true;
        order.push_back(node);

        // Visit all neighbors
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfsUtil(nei, visited, order);
            }
        }
    }

public:
    // Construct with optional number of vertices (default 0)
    Graph(int vertices = 0) : adj(vertices) {}

    // Add an edge between u and v. If undirected is true, add both directions.
    // If u or v is out of range, the adjacency list will be resized to accommodate them.
    void addEdge(int u, int v, bool undirected = true) {
        if (u < 0 || v < 0) {
            // Negative vertex indices are not supported; ignore the request.
            return;
        }
        ensureVertex(max(u, v));
        adj[u].push_back(v);
        if (undirected) {
            adj[v].push_back(u);
        }
    }

    // Depth-First Search.
    // If start == -1, perform a full traversal (all components).
    // Returns the nodes in the order they were visited.
    vector<int> dfs(int start = -1) {
        vector<int> order;

        if (adj.empty()) {
            cout << "DFS: Graph is empty. No vertices to traverse." << endl;
            return order;
        }

        int n = static_cast<int>(adj.size());
        vector<bool> visited(n, false);

        if (start >= 0) {
            if (start >= n) {
                cout << "DFS: start node " << start << " is out of range (0.." << n-1 << ")." << endl;
                return order;
            }
            // Start a DFS from the given start node (single-component traversal)
            dfsUtil(start, visited, order);
            return order;
        }

        // Full traversal: handle disconnected graphs by running DFS from every unvisited vertex
        for (int v = 0; v < n; ++v) {
            if (!visited[v]) {
                dfsUtil(v, visited, order);
            }
        }
        return order;
    }

    // Breadth-First Search.
    // If start == -1, perform a full traversal (all components), BFS order per component.
    // Returns the nodes in the order they were visited.
    vector<int> bfs(int start = -1) {
        vector<int> order;

        if (adj.empty()) {
            cout << "BFS: Graph is empty. No vertices to traverse." << endl;
            return order;
        }

        int n = static_cast<int>(adj.size());
        vector<bool> visited(n, false);

        auto bfsFrom = [&](int s) {
            if (s < 0 || s >= n) return;
            queue<int> q;
            q.push(s);
            visited[s] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);

                for (int nei : adj[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
        };

        if (start >= 0) {
            if (start >= n) {
                cout << "BFS: start node " << start << " is out of range (0.." << n-1 << ")." << endl;
                return order;
            }
            bfsFrom(start);
            return order;
        }

        // Full traversal across components
        for (int v = 0; v < n; ++v) {
            if (!visited[v]) bfsFrom(v);
        }
        return order;
    }

    // Optional: return current number of vertices (based on highest index + 1)
    int vertexCount() const {
        return static_cast<int>(adj.size());
    }
};

// Utility to print traversal result
void printTraversal(const vector<int> &order) {
    if (order.empty()) {
        cout << "(no nodes visited)" << endl;
        return;
    }
    for (size_t i = 0; i < order.size(); ++i) {
        if (i) cout << " -> ";
        cout << order[i];
    }
    cout << endl;
}

// Example usage demonstrating DFS and BFS (educational)
int main() {
    // Start with an empty graph to demonstrate safe edge additions to zero-vertex graphs
    Graph g; // graph with 0 vertices initially

    // Add edges. The graph auto-resizes to include vertices 0..4.
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    // Add a separate component to demonstrate full traversal across components
    g.addEdge(3, 4);

    cout << "Vertex count after adding edges: " << g.vertexCount() << endl;
    cout << endl;

    // DFS starting from vertex 0 (will visit the connected component containing 0)
    cout << "DFS starting from node 0: ";
    vector<int> dfsFrom0 = g.dfs(0);
    printTraversal(dfsFrom0);

    // BFS starting from vertex 0
    cout << "BFS starting from node 0: ";
    vector<int> bfsFrom0 = g.bfs(0);
    printTraversal(bfsFrom0);

    cout << endl;

    // Full DFS across all components
    cout << "Full DFS (covering all components): ";
    vector<int> fullDfs = g.dfs(); // no start => full traversal
    printTraversal(fullDfs);

    // Full BFS across all components
    cout << "Full BFS (covering all components): ";
    vector<int> fullBfs = g.bfs(); // no start => full traversal
    printTraversal(fullBfs);

    return 0;
}
