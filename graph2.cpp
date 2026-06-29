/*
 * File: graph2.cpp
 * Description: Educational implementation of Depth-First Search (DFS) and 
 *              Breadth-First Search (BFS) graph traversal algorithms.
 * Author: DSA Learning Repository
 * C++ Standard: C++17
 * 
 * This file provides:
 * - A modular Graph class for building directed and undirected graphs
 * - Recursive and iterative implementations of DFS
 * - Queue-based implementation of BFS
 * - Comprehensive examples demonstrating various graph scenarios
 * 
 * Use Cases:
 * - Understanding fundamental graph traversal techniques
 * - Foundation for advanced graph algorithms (shortest path, cycle detection, etc.)
 * - Educational resource for learning data structures
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
 * ============================================================================
 * GRAPH CLASS - Core Data Structure
 * ============================================================================
 * 
 * Purpose: Encapsulates graph representation using adjacency list
 * Features:
 *  - Support for both directed and undirected graphs
 *  - Methods to add vertices and edges
 *  - DFS and BFS traversal implementations
 *  - Helper methods for graph analysis
 */
class Graph {
private:
    int numVertices;                          // Number of vertices in the graph
    vector<vector<int>> adjacencyList;        // Adjacency list representation
    bool isDirected;                          // Flag to indicate graph type

public:
    /*
     * Constructor: Initialize Graph with specified number of vertices
     * Parameters:
     *  - vertices: Number of vertices in the graph
     *  - directed: Boolean flag (default=false for undirected graphs)
     */
    Graph(int vertices, bool directed = false) 
        : numVertices(vertices), isDirected(directed), 
          adjacencyList(vertices) {}

    /*
     * Method: addEdge
     * Description: Add an edge between two vertices
     * Parameters:
     *  - u: Source vertex
     *  - v: Destination vertex
     * Time Complexity: O(1)
     * Note: For undirected graphs, edge is added in both directions
     */
    void addEdge(int u, int v) {
        if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
            cerr << "Invalid edge: (" << u << ", " << v << ")" << endl;
            return;
        }
        
        adjacencyList[u].push_back(v);
        
        // For undirected graphs, add edge in reverse direction
        if (!isDirected) {
            adjacencyList[v].push_back(u);
        }
    }

    /*
     * Method: dfsRecursive (Helper)
     * Description: Recursive helper function for DFS traversal
     * Parameters:
     *  - vertex: Current vertex being visited
     *  - visited: Set of already visited vertices
     *  - result: Vector to store traversal order
     * Time Complexity: O(V + E) where V = vertices, E = edges
     * Space Complexity: O(V) for recursion stack
     */
    void dfsRecursive(int vertex, unordered_set<int>& visited, vector<int>& result) {
        // Mark current vertex as visited
        visited.insert(vertex);
        result.push_back(vertex);
        
        // Recursively visit all adjacent unvisited vertices
        for (int neighbor : adjacencyList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsRecursive(neighbor, visited, result);
            }
        }
    }

    /*
     * Method: dfsIterative (Helper)
     * Description: Iterative helper function for DFS traversal using stack
     * Parameters:
     *  - startVertex: Starting vertex for traversal
     *  - visited: Set of already visited vertices
     *  - result: Vector to store traversal order
     * Time Complexity: O(V + E)
     * Space Complexity: O(V) for stack
     * 
     * Algorithm:
     *  1. Push start vertex onto stack
     *  2. While stack is not empty:
     *     - Pop vertex from stack
     *     - If not visited, mark as visited and add to result
     *     - Push all unvisited neighbors onto stack
     */
    void dfsIterative(int startVertex, unordered_set<int>& visited, 
                      vector<int>& result) {
        stack<int> st;
        st.push(startVertex);
        
        while (!st.empty()) {
            int vertex = st.top();
            st.pop();
            
            // Process vertex only if not visited
            if (visited.find(vertex) == visited.end()) {
                visited.insert(vertex);
                result.push_back(vertex);
                
                // Push all unvisited neighbors to stack
                // Note: We iterate in reverse to maintain left-to-right order
                for (int i = adjacencyList[vertex].size() - 1; i >= 0; --i) {
                    int neighbor = adjacencyList[vertex][i];
                    if (visited.find(neighbor) == visited.end()) {
                        st.push(neighbor);
                    }
                }
            }
        }
    }

    /*
     * Method: DFS_Recursive
     * Description: Public method for recursive DFS traversal from all unvisited vertices
     * Returns: Vector containing vertices in DFS traversal order
     * Use Case: Complete graph traversal including disconnected components
     */
    vector<int> DFS_Recursive() {
        unordered_set<int> visited;
        vector<int> result;
        
        // Traverse all vertices to handle disconnected graphs
        for (int i = 0; i < numVertices; ++i) {
            if (visited.find(i) == visited.end()) {
                dfsRecursive(i, visited, result);
            }
        }
        
        return result;
    }

    /*
     * Method: DFS_Iterative
     * Description: Public method for iterative DFS traversal from all unvisited vertices
     * Returns: Vector containing vertices in DFS traversal order
     * Use Case: Alternative to recursive DFS, avoids stack overflow for deep graphs
     */
    vector<int> DFS_Iterative() {
        unordered_set<int> visited;
        vector<int> result;
        
        // Traverse all vertices to handle disconnected graphs
        for (int i = 0; i < numVertices; ++i) {
            if (visited.find(i) == visited.end()) {
                dfsIterative(i, visited, result);
            }
        }
        
        return result;
    }

    /*
     * Method: BFS
     * Description: Breadth-First Search traversal using queue
     * Returns: Vector containing vertices in BFS traversal order
     * Time Complexity: O(V + E)
     * Space Complexity: O(V) for queue
     * 
     * Algorithm:
     *  1. Initialize queue with start vertex
     *  2. Mark start vertex as visited
     *  3. While queue is not empty:
     *     - Dequeue a vertex
     *     - Add to result
     *     - Enqueue all unvisited neighbors
     *     - Mark neighbors as visited
     * 
     * Use Case: Finding shortest path, level-order traversal, 
     *           discovering connected components
     */
    vector<int> BFS() {
        unordered_set<int> visited;
        vector<int> result;
        queue<int> q;
        
        // Process all vertices to handle disconnected graphs
        for (int startVertex = 0; startVertex < numVertices; ++startVertex) {
            if (visited.find(startVertex) == visited.end()) {
                q.push(startVertex);
                visited.insert(startVertex);
                
                while (!q.empty()) {
                    int vertex = q.front();
                    q.pop();
                    result.push_back(vertex);
                    
                    // Enqueue all unvisited neighbors
                    for (int neighbor : adjacencyList[vertex]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        
        return result;
    }

    /*
     * Method: BFS_ShortestPath
     * Description: Find shortest path between two vertices using BFS
     * Parameters:
     *  - start: Starting vertex
     *  - end: Ending vertex
     * Returns: Vector representing the shortest path (empty if no path exists)
     * 
     * Algorithm:
     *  1. Use BFS starting from 'start' vertex
     *  2. Maintain parent tracking to reconstruct path
     *  3. Return path by backtracking from 'end' to 'start' using parents
     */
    vector<int> BFS_ShortestPath(int start, int end) {
        if (start < 0 || start >= numVertices || end < 0 || end >= numVertices) {
            cerr << "Invalid vertices for path finding" << endl;
            return {};
        }
        
        unordered_set<int> visited;
        vector<int> parent(numVertices, -1);
        queue<int> q;
        
        q.push(start);
        visited.insert(start);
        
        // BFS to find shortest path
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            
            if (vertex == end) break;
            
            for (int neighbor : adjacencyList[vertex]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    parent[neighbor] = vertex;
                    q.push(neighbor);
                }
            }
        }
        
        // Reconstruct path
        if (visited.find(end) == visited.end()) {
            // No path exists
            return {};
        }
        
        vector<int> path;
        int current = end;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        return path;
    }

    /*
     * Method: printGraph
     * Description: Display the adjacency list representation of the graph
     * Useful for debugging and understanding graph structure
     */
    void printGraph() const {
        cout << "\n" << string(60, '=') << "\n";
        cout << "Graph Adjacency List:\n";
        cout << string(60, '=') << "\n";
        
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << " -> ";
            for (int neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
        cout << string(60, '=') << "\n";
    }

    /*
     * Method: printTraversal
     * Description: Display traversal results in formatted manner
     * Parameters:
     *  - traversalName: Name of the traversal algorithm
     *  - result: Vector containing traversal order
     */
    void printTraversal(const string& traversalName, const vector<int>& result) const {
        cout << "\n" << traversalName << " Traversal Order: ";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }
};

// ============================================================================
// DEMONSTRATION FUNCTIONS - Various Graph Scenarios
// ============================================================================

/*
 * Example 1: Simple Connected Undirected Graph
 * 
 *     0 --- 1
 *     |     |
 *     2 --- 3
 * 
 * This demonstrates DFS and BFS on a basic connected graph.
 */
void example_SimpleConnectedGraph() {
    cout << "\n" << string(70, '#') << "\n";
    cout << "EXAMPLE 1: Simple Connected Undirected Graph\n";
    cout << string(70, '#') << "\n";
    
    Graph g(4, false);  // 4 vertices, undirected
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    
    g.printGraph();
    
    cout << "\n--- DFS Traversals ---\n";
    vector<int> dfsRec = g.DFS_Recursive();
    g.printTraversal("DFS (Recursive)", dfsRec);
    
    vector<int> dfsIter = g.DFS_Iterative();
    g.printTraversal("DFS (Iterative)", dfsIter);
    
    cout << "\n--- BFS Traversal ---\n";
    vector<int> bfs = g.BFS();
    g.printTraversal("BFS", bfs);
}

/*
 * Example 2: Directed Graph (Acyclic)
 * 
 *     0 --> 1 --> 3
 *     |           ^
 *     +---> 2 ----+
 * 
 * Demonstrates DFS and BFS on directed acyclic graph (DAG).
 */
void example_DirectedAcyclicGraph() {
    cout << "\n" << string(70, '#') << "\n";
    cout << "EXAMPLE 2: Directed Acyclic Graph (DAG)\n";
    cout << string(70, '#') << "\n";
    
    Graph g(4, true);  // 4 vertices, directed
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    
    g.printGraph();
    
    cout << "\n--- DFS Traversals ---\n";
    vector<int> dfsRec = g.DFS_Recursive();
    g.printTraversal("DFS (Recursive)", dfsRec);
    
    vector<int> dfsIter = g.DFS_Iterative();
    g.printTraversal("DFS (Iterative)", dfsIter);
    
    cout << "\n--- BFS Traversal ---\n";
    vector<int> bfs = g.BFS();
    g.printTraversal("BFS", bfs);
}

/*
 * Example 3: Graph with Cycle
 * 
 *     0 --- 1
 *     |     |
 *     3 --- 2
 *     (undirected cycle)
 * 
 * Demonstrates how visited set prevents infinite loops during traversal.
 */
void example_GraphWithCycle() {
    cout << "\n" << string(70, '#') << "\n";
    cout << "EXAMPLE 3: Undirected Graph with Cycle\n";
    cout << string(70, '#') << "\n";
    
    Graph g(4, false);  // Undirected graph
    
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);  // Creates cycle: 0-1-2-3-0
    
    g.printGraph();
    
    cout << "\n--- DFS Traversals (Cycle handling) ---\n";
    vector<int> dfsRec = g.DFS_Recursive();
    g.printTraversal("DFS (Recursive)", dfsRec);
    
    vector<int> dfsIter = g.DFS_Iterative();
    g.printTraversal("DFS (Iterative)", dfsIter);
    
    cout << "\n--- BFS Traversal (Cycle handling) ---\n";
    vector<int> bfs = g.BFS();
    g.printTraversal("BFS", bfs);
}

/*
 * Example 4: Disconnected Graph
 * 
 *     Component 1:     Component 2:
 *     0 --- 1          3 --- 4
 *           |               |
 *     2 ----+               5
 * 
 * Demonstrates traversal across multiple disconnected components.
 */
void example_DisconnectedGraph() {
    cout << "\n" << string(70, '#') << "\n";
    cout << "EXAMPLE 4: Disconnected Graph\n";
    cout << string(70, '#') << "\n";
    
    Graph g(6, false);  // 6 vertices, undirected
    
    // Component 1
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    
    // Component 2
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    
    g.printGraph();
    
    cout << "\n--- DFS Traversals (Multiple components) ---\n";
    vector<int> dfsRec = g.DFS_Recursive();
    g.printTraversal("DFS (Recursive)", dfsRec);
    
    vector<int> dfsIter = g.DFS_Iterative();
    g.printTraversal("DFS (Iterative)", dfsIter);
    
    cout << "\n--- BFS Traversal (Multiple components) ---\n";
    vector<int> bfs = g.BFS();
    g.printTraversal("BFS", bfs);
}

/*
 * Example 5: Single Vertex Graph (Edge Case)
 * 
 *     0
 * 
 * Demonstrates handling of minimal graph.
 */
void example_SingleVertexGraph() {
    cout << "\n" << string(70, '#') << "\n";
    cout << "EXAMPLE 5: Single Vertex Graph (Edge Case)\n";
    cout << string(70, '#') << "\n";
    
    Graph g(1, false);
    
    g.printGraph();
    
    cout << "\n--- DFS Traversals ---\n";
    vector<int> dfsRec = g.DFS_Recursive();
    g.printTraversal("DFS (Recursive)", dfsRec);
    
    vector<int> dfsIter = g.DFS_Iterative();
    g.printTraversal("DFS (Iterative)", dfsIter);
    
    cout << "\n--- BFS Traversal ---\n";
    vector<int> bfs = g.BFS();
    g.printTraversal("BFS", bfs);
}

/*
 * Example 6: Complex Directed Graph
 * 
 *     0 --> 1 --> 2
 *     |     |     |
 *     v     v     v
 *     3 --> 4 --> 5
 * 
 * Demonstrates traversal on more complex directed structure.
 */
void example_ComplexDirectedGraph() {
    cout << "\n" << string(70, '#') << "\n";
    cout << "EXAMPLE 6: Complex Directed Graph\n";
    cout << string(70, '#') << "\n";
    
    Graph g(6, true);  // 6 vertices, directed
    
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    
    g.printGraph();
    
    cout << "\n--- DFS Traversals ---\n";
    vector<int> dfsRec = g.DFS_Recursive();
    g.printTraversal("DFS (Recursive)", dfsRec);
    
    vector<int> dfsIter = g.DFS_Iterative();
    g.printTraversal("DFS (Iterative)", dfsIter);
    
    cout << "\n--- BFS Traversal ---\n";
    vector<int> bfs = g.BFS();
    g.printTraversal("BFS", bfs);
}

/*
 * Example 7: Shortest Path Finding using BFS
 * 
 * Demonstrates practical application of BFS for finding shortest paths.
 */
void example_ShortestPathBFS() {
    cout << "\n" << string(70, '#') << "\n";
    cout << "EXAMPLE 7: Shortest Path Finding with BFS\n";
    cout << string(70, '#') << "\n";
    
    Graph g(7, false);  // 7 vertices, undirected
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    
    g.printGraph();
    
    cout << "\nFinding shortest paths:\n";
    cout << string(60, '-') << "\n";
    
    vector<pair<int, int>> pathQueries = {{0, 6}, {1, 5}, {2, 4}, {0, 0}};
    
    for (const auto& [start, end] : pathQueries) {
        vector<int> path = g.BFS_ShortestPath(start, end);
        
        cout << "Path from " << start << " to " << end << ": ";
        if (path.empty()) {
            cout << "No path exists";
        } else {
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << " (Length: " << path.size() - 1 << " edges)";
        }
        cout << "\n";
    }
}

/*
 * Example 8: Empty Graph (Edge Case)
 * 
 * Demonstrates graceful handling of empty graph.
 */
void example_EmptyGraph() {
    cout << "\n" << string(70, '#') << "\n";
    cout << "EXAMPLE 8: Empty Graph (Edge Case)\n";
    cout << string(70, '#') << "\n";
    
    Graph g(0, false);
    
    g.printGraph();
    
    cout << "\n--- DFS Traversals on empty graph ---\n";
    vector<int> dfsRec = g.DFS_Recursive();
    g.printTraversal("DFS (Recursive)", dfsRec);
    
    vector<int> dfsIter = g.DFS_Iterative();
    g.printTraversal("DFS (Iterative)", dfsIter);
    
    cout << "\n--- BFS Traversal on empty graph ---\n";
    vector<int> bfs = g.BFS();
    g.printTraversal("BFS", bfs);
}

// ============================================================================
// COMPARISON ANALYSIS FUNCTION
// ============================================================================

/*
 * Function: compareTraversalAlgorithms
 * Description: Provides detailed comparison of DFS vs BFS characteristics
 * 
 * This function displays:
 *  - Time and space complexity
 *  - Use cases and applications
 *  - Advantages and disadvantages of each algorithm
 */
void compareTraversalAlgorithms() {
    cout << "\n" << string(80, '=') << "\n";
    cout << "COMPARISON: DFS vs BFS\n";
    cout << string(80, '=') << "\n";
    
    cout << "\n┌─ DEPTH-FIRST SEARCH (DFS) ─────────────────────────────────────┐\n";
    cout << "│                                                                  │\n";
    cout << "│ Time Complexity:        O(V + E)                                 │\n";
    cout << "│ Space Complexity:       O(V) [recursion/stack]                   │\n";
    cout << "│                                                                  │\n";
    cout << "│ Characteristics:                                                 │\n";
    cout << "│  • Explores as far as possible along each branch                 │\n";
    cout << "│  • Uses stack (implicit in recursion, explicit in iteration)     │\n";
    cout << "│  • Memory efficient for breadth (shallow trees)                  │\n";
    cout << "│                                                                  │\n";
    cout << "│ Applications:                                                    │\n";
    cout << "│  • Topological sorting                                           │\n";
    cout << "│  • Cycle detection                                               │\n";
    cout << "│  • Path finding in mazes                                         │\n";
    cout << "│  • Strongly connected components                                 │\n";
    cout << "│  • Back edge detection                                           │\n";
    cout << "└─────────────────────────────────────────────────────────────────┘\n";
    
    cout << "\n┌─ BREADTH-FIRST SEARCH (BFS) ──────────────────────────────────┐\n";
    cout << "│                                                                  │\n";
    cout << "│ Time Complexity:        O(V + E)                                 │\n";
    cout << "│ Space Complexity:       O(V) [queue]                             │\n";
    cout << "│                                                                  │\n";
    cout << "│ Characteristics:                                                 │\n";
    cout << "│  • Explores neighbors level by level                             │\n";
    cout << "│  • Uses queue (FIFO data structure)                              │\n";
    cout << "│  • Finds shortest path in unweighted graphs                      │\n";
    cout << "│                                                                  │\n";
    cout << "│ Applications:                                                    │\n";
    cout << "│  • Shortest path finding                                         │\n";
    cout << "│  • Level-order traversal                                         │\n";
    cout << "│  • Social network (friend suggestions)                           │\n";
    cout << "│  • Bipartite graph checking                                      │\n";
    cout << "│  • Web crawler (breadth exploration)                             │\n";
    cout << "└─────────────────────────────────────────────────────────────────┘\n";
    
    cout << "\n┌─ KEY DIFFERENCES ─────────────────────────────────────────────┐\n";
    cout << "│                                                                  │\n";
    cout << "│ Aspect              │ DFS              │ BFS                      │\n";
    cout << "│ ────────────────────┼──────────────────┼──────────────────────    │\n";
    cout << "│ Data Structure      │ Stack            │ Queue                    │\n";
    cout << "│ Order               │ Depth-first      │ Level-by-level           │\n";
    cout << "│ Shortest Path       │ Not optimal      │ Optimal (unweighted)     │\n";
    cout << "│ Memory (wide trees) │ More efficient   │ Less efficient           │\n";
    cout << "│ Memory (deep trees) │ Less efficient   │ More efficient           │\n";
    cout << "│ Recursion Risk      │ Stack overflow   │ No issue                 │\n";
    cout << "│                                                                  │\n";
    cout << "└─────────────────────────────────────────────────────────────────┘\n";
}

// ============================================================================
// MAIN FUNCTION - Execute All Examples
// ============================================================================

/*
 * Main Function: Driver for all examples and demonstrations
 * 
 * Execution Flow:
 *  1. Display header and introduction
 *  2. Run all graph examples (simple, directed, cyclic, disconnected, etc.)
 *  3. Demonstrate practical applications (shortest path)
 *  4. Display comparative analysis
 *  5. Display footer with summary
 */
int main() {
    cout << "\n" << string(80, '#') << "\n";
    cout << "# GRAPH TRAVERSAL ALGORITHMS: DFS & BFS EDUCATIONAL IMPLEMENTATION\n";
    cout << "# C++ Standard: C++17 | Paradigm: Object-Oriented\n";
    cout << "#\n";
    cout << "# This program demonstrates comprehensive implementations of:\n";
    cout << "#  • Depth-First Search (DFS) - Recursive and Iterative approaches\n";
    cout << "#  • Breadth-First Search (BFS) - Queue-based approach\n";
    cout << "#  • Graph class with modular design for extensibility\n";
    cout << "#  • Real-world application examples and edge cases\n";
    cout << string(80, '#') << "\n";
    
    try {
        // Execute all examples
        example_SimpleConnectedGraph();
        example_DirectedAcyclicGraph();
        example_GraphWithCycle();
        example_DisconnectedGraph();
        example_SingleVertexGraph();
        example_ComplexDirectedGraph();
        example_ShortestPathBFS();
        example_EmptyGraph();
        
        // Display comparison analysis
        compareTraversalAlgorithms();
        
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return 1;
    }
    
    // Footer
    cout << "\n" << string(80, '#') << "\n";
    cout << "# SUMMARY\n";
    cout << "#\n";
    cout << "# Key Takeaways:\n";
    cout << "#  ✓ DFS is efficient for exploring all paths and cycle detection\n";
    cout << "#  ✓ BFS finds shortest paths and explores level-by-level\n";
    cout << "#  ✓ Both traverse connected and disconnected graphs correctly\n";
    cout << "#  ✓ Graph class is extensible for future algorithms (Dijkstra, etc.)\n";
    cout << "#  ✓ Edge cases (empty, single vertex, cycles) are handled gracefully\n";
    cout << "#\n";
    cout << "# Next Steps:\n";
    cout << "#  • Extend Graph class with weighted edge support\n";
    cout << "#  • Implement shortest path algorithms (Dijkstra, Bellman-Ford)\n";
    cout << "#  • Add cycle detection and topological sorting\n";
    cout << "#  • Explore advanced algorithms (Strongly Connected Components)\n";
    cout << string(80, '#') << "\n\n";
    
    return 0;
}

/* 
 * ============================================================================
 * NOTES FOR LEARNERS
 * ============================================================================
 * 
 * 1. RECURSIVE vs ITERATIVE DFS:
 *    - Recursive: Cleaner code, but risks stack overflow on very deep graphs
 *    - Iterative: More control, avoids recursion depth issues, preferred for 
 *      production code
 *
 * 2. BFS GUARANTEES:
 *    - Finds shortest path in unweighted graphs
 *    - Level-order gives natural grouping by distance
 *    - Essential for many graph applications
 *
 * 3. VISITED SET IMPORTANCE:
 *    - Prevents infinite loops in cyclic graphs
 *    - Ensures each vertex is processed only once
 *    - Critical for correctness in DFS and BFS
 *
 * 4. TIME COMPLEXITY:
 *    - Both DFS and BFS are O(V + E) because they visit each vertex once
 *      and each edge twice (once from each endpoint in undirected graphs)
 *
 * 5. EXTENSIBILITY:
 *    - The Graph class can be extended with:
 *      • Weighted edges (add weight parameter to addEdge)
 *      • Edge removal (for dynamic graphs)
 *      • Graph properties (density, diameter, etc.)
 *      • Weighted path algorithms (Dijkstra, Floyd-Warshall)
 *
 * 6. PRACTICAL APPLICATIONS:
 *    - Social Networks: BFS for friend suggestions, DFS for connected groups
 *    - Web Crawling: BFS for breadth exploration
 *    - Maze Solving: DFS for exploration, BFS for shortest path
 *    - Dependency Resolution: Topological sort using DFS
 *    - Recommendation Systems: BFS for multi-hop connections
 */
