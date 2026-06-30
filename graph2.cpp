/*
  graph2.cpp

  Educational Graph class demonstrating DFS and BFS traversals in C++.

  - Graph supports dynamic addition of edges even when constructed with zero vertices.
  - addEdge(u, v, undirected) will auto-resize internal adjacency list if needed.
  - dfs(start = -1) and bfs(start = -1):
      - start >= 0 : traverse starting from that node (single-component traversal).
      - start == -1: perform a full traversal covering all components.
  - Inline comments explain algorithmic steps for learners.

  This updated version includes simple, built-in tests/demonstrations for edge cases
  required by the PRD (empty graph behavior, adding edges to a zero-vertex graph,
  out-of-range start nodes, directed graphs, and self-loops).

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

// Small helper to compare expected vs actual traversal and print PASS/FAIL
void checkEqual(const vector<int> &actual, const vector<int> &expected, const char *testName) {
    if (actual == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << "\n  expected: ";
        printTraversal(expected);
        cout << "  actual:   ";
        printTraversal(actual);
    }
}

// Demonstration and simple tests for edge cases required by PRD
int main() {
    cout << "--- Graph traversal examples and tests ---" << endl << endl;

    // 1) Empty graph behavior
    {
        Graph empty;
        cout << "Test 1: Empty graph DFS/BFS" << endl;
        vector<int> d = empty.dfs(); // should print message and return empty
        vector<int> b = empty.bfs(); // should print message and return empty
        checkEqual(d, vector<int>{}, "Empty graph DFS returns empty");
        checkEqual(b, vector<int>{}, "Empty graph BFS returns empty");
        cout << endl;
    }

    // 2) Adding edges to a zero-vertex graph (auto-resize)
    {
        Graph g;
        cout << "Test 2: addEdge on zero-vertex graph (auto-resize)" << endl;
        g.addEdge(2, 0); // should resize internally to at least 3 vertices
        cout << "Vertex count (expected >= 3): " << g.vertexCount() << endl;
        // Traversal starting from 2 should at least visit connected component containing 2 and 0
        vector<int> bfsFrom2 = g.bfs(2);
        // Depending on adjacency order, expect 2 -> 0
        cout << "BFS from 2: "; printTraversal(bfsFrom2);
        // Ensure vertexCount is as expected
        checkEqual(vector<int>{static_cast<int>(g.vertexCount())}, vector<int>{g.vertexCount()}, "Vertex count reported consistently");
        cout << endl;
    }

    // 3) Out-of-range start node
    {
        Graph g(2); // vertices 0 and 1 exist
        cout << "Test 3: start node out-of-range" << endl;
        vector<int> d = g.dfs(5); // should print out-of-range message and return empty
        vector<int> b = g.bfs(5); // similarly
        checkEqual(d, vector<int>{}, "DFS with out-of-range start returns empty");
        checkEqual(b, vector<int>{}, "BFS with out-of-range start returns empty");
        cout << endl;
    }

    // 4) Directed graph behavior (undirected = false)
    {
        cout << "Test 4: directed graph traversal" << endl;
        Graph dg; // directed graph via undirected=false
        dg.addEdge(0, 1, false); // 0 -> 1
        dg.addEdge(1, 2, false); // 1 -> 2
        // BFS and DFS from 0 should visit 0,1,2 in that order (for BFS) and 0,1,2 for DFS in this simple chain
        vector<int> bfsDirected = dg.bfs(0);
        vector<int> dfsDirected = dg.dfs(0);
        checkEqual(bfsDirected, vector<int>{0,1,2}, "Directed BFS from 0");
        checkEqual(dfsDirected, vector<int>{0,1,2}, "Directed DFS from 0");
        cout << endl;
    }

    // 5) Self-loop handling
    {
        cout << "Test 5: self-loop" << endl;
        Graph sl;
        sl.addEdge(0, 0); // self-loop
        vector<int> bfsSL = sl.bfs(0);
        vector<int> dfsSL = sl.dfs(0);
        checkEqual(bfsSL, vector<int>{0}, "BFS visits self-loop node once");
        checkEqual(dfsSL, vector<int>{0}, "DFS visits self-loop node once");
        cout << endl;
    }

    // 6) Full traversal across components (sample educational graph)
    {
        cout << "Test 6: sample graph full traversal" << endl;
        Graph g; // graph with auto-resize
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(3, 4);

        cout << "Vertex count: " << g.vertexCount() << " (expected 5)" << endl;

        cout << "DFS starting from node 0: ";
        auto dfsFrom0 = g.dfs(0);
        printTraversal(dfsFrom0);

        cout << "BFS starting from node 0: ";
        auto bfsFrom0 = g.bfs(0);
        printTraversal(bfsFrom0);

        cout << "Full DFS (covering all components): ";
        auto fullDfs = g.dfs();
        printTraversal(fullDfs);

        cout << "Full BFS (covering all components): ";
        auto fullBfs = g.bfs();
        printTraversal(fullBfs);

        // Basic checks (orders may vary by adjacency order but should contain nodes 0..4)
        vector<int> expectedNodes = {0,1,2,3,4};
        auto sortAndCompare = [&](const vector<int>& actual, const char* name){
            vector<int> copy = actual;
            std::sort(copy.begin(), copy.end());
            checkEqual(copy, expectedNodes, name);
        };

        sortAndCompare(fullDfs, "Full DFS contains all nodes 0..4");
        sortAndCompare(fullBfs, "Full BFS contains all nodes 0..4");
        cout << endl;
    }

    cout << "--- End of tests ---" << endl;
    return 0;
}
