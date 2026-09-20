#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Tarjan's algorithm for bridges and articulation points in an undirected graph.
// Input vertices are numbered from 0 to vertices - 1.
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
                    bridges.emplace_back(min(vertex, edge.to),
                                         max(vertex, edge.to));
                }

                if (parentEdge != -1 &&
                    lowLink[edge.to] >= discoveryTime[vertex]) {
                    articulation[vertex] = true;
                }
            } else {
                lowLink[vertex] = min(lowLink[vertex],
                                       discoveryTime[edge.to]);
            }
        }

        // A DFS root is an articulation point only if it has two or more
        // independent DFS children.
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

        // A unique edge ID ensures that parallel edges are handled correctly:
        // only the DFS tree edge is ignored as the parent edge.
        const int edgeId = static_cast<int>(bridges.size()) +
                           static_cast<int>(graph[0].size());
        graph[first].push_back({second, edgeId});
        graph[second].push_back({first, edgeId});
    }

    void findCriticalElements() {
        timer = 0;
        bridges.clear();
        fill(discoveryTime.begin(), discoveryTime.end(), -1);
        fill(lowLink.begin(), lowLink.end(), -1);
        fill(articulation.begin(), articulation.end(), false);

        // Starting from every unvisited vertex supports disconnected graphs.
        for (int vertex = 0; vertex < static_cast<int>(graph.size());
             ++vertex) {
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
        for (int vertex = 0; vertex < static_cast<int>(articulation.size());
             ++vertex) {
            if (articulation[vertex]) {
                result.push_back(vertex);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertices, edges;
    if (!(cin >> vertices >> edges) || vertices < 0 || edges < 0) {
        return 0;
    }

    TarjanGraph graph(vertices);
    for (int i = 0; i < edges; ++i) {
        int first, second;
        cin >> first >> second;
        graph.addEdge(first, second);
    }

    graph.findCriticalElements();

    cout << "Bridges:\n";
    for (const auto& [first, second] : graph.getBridges()) {
        cout << first << " - " << second << '\n';
    }

    cout << "Articulation points:\n";
    for (int vertex : graph.getArticulationPoints()) {
        cout << vertex << '\n';
    }

    return 0;
}
