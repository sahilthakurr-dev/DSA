#include <algorithm>
#include <cassert>
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

        const int edgeId = static_cast<int>(graph[first].size()) +
                           static_cast<int>(graph[second].size());

        graph[first].push_back({second, edgeId});
        graph[second].push_back({first, edgeId});
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

    const vector<pair<int, int>>& getBridges() const {
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
};

template <typename T>
bool sameVector(const vector<T>& a, const vector<T>& b) {
    return a == b;
}

void runTest(const string& name,
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

    if (!sameVector(bridges, expectedBridges)) {
        cerr << "FAIL: " << name << " bridges\n";
        cerr << "Expected: ";
        for (const auto& e : expectedBridges) {
            cerr << "(" << e.first << "," << e.second << ") ";
        }
        cerr << "\nActual:   ";
        for (const auto& e : bridges) {
            cerr << "(" << e.first << "," << e.second << ") ";
        }
        cerr << "\n";
        assert(false);
    }

    if (!sameVector(articulationPoints, expectedArticulationPoints)) {
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

int main() {
    // 1) Simple path: 0-1-2
    // Bridges: (0,1), (1,2)
    // Articulation: 1
    runTest("path graph",
            {{0, 1}, {1, 2}},
            {{0, 1}, {1, 2}},
            {1});

    // 2) Cycle: 0-1-2-0
    // Bridges: none
    // Articulation: none
    runTest("cycle graph",
            {{0, 1}, {1, 2}, {2, 0}},
            {},
            {});

    // 3) Star: 0 connected to 1,2,3
    // Bridges: none
    // Articulation: 0
    runTest("star graph",
            {{0, 1}, {0, 2}, {0, 3}},
            {},
            {0});

    // 4) Disconnected graph:
    // 0-1-2 and 3-4
    // Bridges: (0,1), (1,2), (3,4)
    // Articulation: 1
    runTest("disconnected graph",
            {{0, 1}, {1, 2}, {3, 4}},
            {{0, 1}, {1, 2}, {3, 4}},
            {1});

    // 5) Graph with a cycle and a leaf:
    // 0-1, 1-2, 2-0, 1-3, 3-4
    // Bridges: (3,4)
    // Articulation: 1, 3
    runTest("cycle with leaf",
            {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}},
            {{3, 4}},
            {1, 3});

    cout << "All Tarjan validation tests passed." << endl;
    return 0;
}
