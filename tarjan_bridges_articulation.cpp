#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

// Tarjan's algorithm for bridges and articulation points in an undirected graph.
class TarjanGraph {
private:
    struct Edge {
        int to;
        int id;
    };

    vector<vector<Edge>> graph;
    vector<int> discoveryTime;
    vector<int> lowLink;
    vector<bool> articulation;
    vector<pair<int, int>> bridges;
    int timer = 0;
    int nextEdgeId = 0;

    void dfs(int vertex, int parentEdge) {
        discoveryTime[vertex] = lowLink[vertex] = timer++;
        int children = 0;

        for (const Edge& edge : graph[vertex]) {
            if (edge.id == parentEdge) {
                continue;
            }

            if (discoveryTime[edge.to] == -1) {
                ++children;
                dfs(edge.to, edge.id);

                lowLink[vertex] = min(lowLink[vertex], lowLink[edge.to]);

                if (lowLink[edge.to] > discoveryTime[vertex]) {
                    bridges.emplace_back(min(vertex, edge.to), max(vertex, edge.to));
                }

                if (parentEdge != -1 && lowLink[edge.to] >= discoveryTime[vertex]) {
                    articulation[vertex] = true;
                }
            } else {
                lowLink[vertex] = min(lowLink[vertex], discoveryTime[edge.to]);
            }
        }

        if (parentEdge == -1 && children > 1) {
            articulation[vertex] = true;
        }
    }

public:
    explicit TarjanGraph(int vertices)
        : graph(max(vertices, 0)),
          discoveryTime(max(vertices, 0), -1),
          lowLink(max(vertices, 0), -1),
          articulation(max(vertices, 0), false) {}

    void addEdge(int first, int second) {
        if (first < 0 || second < 0 ||
            first >= static_cast<int>(graph.size()) ||
            second >= static_cast<int>(graph.size())) {
            return;
        }

        graph[first].push_back({second, nextEdgeId});
        graph[second].push_back({first, nextEdgeId});
        ++nextEdgeId;
    }

    void findCriticalElements() {
        timer = 0;
        bridges.clear();
        fill(discoveryTime.begin(), discoveryTime.end(), -1);
        fill(lowLink.begin(), lowLink.end(), -1);
        fill(articulation.begin(), articulation.end(), false);

        for (int vertex = 0; vertex < static_cast<int>(graph.size()); ++vertex) {
            if (discoveryTime[vertex] == -1) {
                dfs(vertex, -1);
            }
        }

        sort(bridges.begin(), bridges.end());
    }

    vector<pair<int, int>> getBridges() const {
        return bridges;
    }

    vector<int> getArticulationPoints() const {
        vector<int> result;
        for (int vertex = 0; vertex < static_cast<int>(articulation.size()); ++vertex) {
            if (articulation[vertex]) {
                result.push_back(vertex);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }

    size_t getAdjacencyEntryCount() const {
        size_t total = 0;
        for (const auto& neighbors : graph) {
            total += neighbors.size();
        }
        return total;
    }
};

static vector<pair<int, int>> normalizeBridges(const vector<pair<int, int>>& bridges) {
    vector<pair<int, int>> copy = bridges;
    sort(copy.begin(), copy.end());
    return copy;
}

static vector<int> normalizeArticulationPoints(const vector<int>& points) {
    vector<int> copy = points;
    sort(copy.begin(), copy.end());
    return copy;
}

static bool sameBridgeSet(const vector<pair<int, int>>& actual,
                          const vector<pair<int, int>>& expected) {
    return normalizeBridges(actual) == normalizeBridges(expected);
}

static bool samePointSet(const vector<int>& actual,
                         const vector<int>& expected) {
    return normalizeArticulationPoints(actual) == normalizeArticulationPoints(expected);
}

static void runTest(const string& name,
                    const vector<pair<int, int>>& edges,
                    const vector<pair<int, int>>& expectedBridges,
                    const vector<int>& expectedArticulationPoints) {
    int maxVertex = 0;
    for (const auto& [u, v] : edges) {
        maxVertex = max(maxVertex, max(u, v));
    }

    TarjanGraph graph(maxVertex + 1);
    for (const auto& [u, v] : edges) {
        graph.addEdge(u, v);
    }

    graph.findCriticalElements();

    const auto bridges = graph.getBridges();
    const auto articulationPoints = graph.getArticulationPoints();

    if (!sameBridgeSet(bridges, expectedBridges)) {
        cerr << "FAIL: " << name << " bridges\n";
        cerr << "Expected: ";
        for (const auto& [u, v] : expectedBridges) cerr << "(" << u << "," << v << ") ";
        cerr << "\nActual:   ";
        for (const auto& [u, v] : bridges) cerr << "(" << u << "," << v << ") ";
        cerr << "\n";
        assert(false);
    }

    if (!samePointSet(articulationPoints, expectedArticulationPoints)) {
        cerr << "FAIL: " << name << " articulation points\n";
        cerr << "Expected: ";
        for (int x : expectedArticulationPoints) cerr << x << " ";
        cerr << "\nActual:   ";
        for (int x : articulationPoints) cerr << x << " ";
        cerr << "\n";
        assert(false);
    }

    cout << "PASS: " << name << "\n";
}

static void runPerformanceTest() {
    const int vertices = 20000;
    TarjanGraph graph(vertices);

    for (int i = 0; i < vertices - 1; ++i) {
        graph.addEdge(i, i + 1);
    }
    for (int i = 0; i < vertices; ++i) {
        graph.addEdge(i, (i + 1) % vertices);
    }

    const auto start = chrono::steady_clock::now();
    graph.findCriticalElements();
    const auto end = chrono::steady_clock::now();
    const auto elapsedMs = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    if (elapsedMs > 3000) {
        cerr << "FAIL: performance test exceeded 3000 ms for " << vertices << " vertices (actual: "
             << elapsedMs << " ms)\n";
        assert(false);
    }

    cout << "PASS: performance test (" << vertices << " vertices, " << elapsedMs << " ms)\n";
}

static void runMemoryComplexityTest() {
    const int vertices = 5000;
    TarjanGraph graph(vertices);

    for (int i = 0; i < vertices - 1; ++i) {
        graph.addEdge(i, i + 1);
    }
    for (int i = 0; i < vertices - 2; ++i) {
        graph.addEdge(i, i + 2);
    }

    graph.findCriticalElements();

    const size_t adjacencyEntries = graph.getAdjacencyEntryCount();
    const size_t stateEntries = graph.getArticulationPoints().size() +
                               static_cast<size_t>(vertices) +
                               static_cast<size_t>(vertices);

    assert(graph.getBridges().size() <= adjacencyEntries);
    assert(adjacencyEntries >= 2 * static_cast<size_t>(vertices));
    assert(stateEntries <= 3 * static_cast<size_t>(vertices) + adjacencyEntries);

    cout << "PASS: memory complexity test (V=" << vertices << ", adjacency entries="
         << adjacencyEntries << ")\n";
}

int main() {
    runTest("single isolated vertex",
            {},
            {},
            {});

    runTest("path graph",
            {{0, 1}, {1, 2}},
            {{0, 1}, {1, 2}},
            {1});

    runTest("cycle graph",
            {{0, 1}, {1, 2}, {2, 0}},
            {},
            {});

    runTest("star graph",
            {{0, 1}, {0, 2}, {0, 3}},
            {},
            {0});

    runTest("disconnected graph",
            {{0, 1}, {1, 2}, {3, 4}},
            {{0, 1}, {1, 2}, {3, 4}},
            {1});

    runTest("cycle with leaf",
            {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}},
            {{3, 4}},
            {1, 3});

    runTest("two cycles joined by a bridge",
            {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}, {2, 3}},
            {{2, 3}},
            {2, 3});

    runTest("tree with two articulation points",
            {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}},
            {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}},
            {1, 3});

    runTest("complete graph",
            {{0, 1}, {0, 2}, {1, 2}, {0, 3}, {1, 3}, {2, 3}},
            {},
            {});

    runPerformanceTest();
    runMemoryComplexityTest();

    cout << "All Tarjan validation tests passed." << endl;
    return 0;
}
