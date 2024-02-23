#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX
#define ll long long int

struct Edge {
    int source, destination, weight;
};

void addEdge(vector<Edge>& graph, int src, int dest, int weight) {
    graph.push_back({src, dest, weight});
}

bool bellmanFord(vector<Edge>& graph, int n, vector<ll>& dist) {
    dist[0] = 0;
    bool relaxed;

    for (int i = 0; i < n - 1; ++i) {
        relaxed = false;
        for (auto& edge : graph) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                relaxed = true;
            }
        }
        if (!relaxed) break; // If no relaxation in this iteration, stop
    }

    for (auto& edge : graph) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if (dist[u] != INF && dist[u] + weight < dist[v])
            return false;
    }

    return true;
}

void dijkstra(vector<vector<pair<int, int>>>& adjList, int src, vector<ll>& dist) {
    int n = dist.size();
    dist.assign(n, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int edgeWeight = neighbor.second;
            if (dist[u] + edgeWeight < dist[v]) {
                dist[v] = dist[u] + edgeWeight;
                pq.push({dist[v], v});
            }
        }
    }
}

void johnsonsAlgorithm(vector<Edge>& graph, int n) {
    if (graph.empty()) {
        cout << 0 << endl;
        return;
    }
    vector<ll> h(n + 1, INF);
    vector<ll> modifiedWeights(n + 1);

    vector<vector<pair<int, int>>> adjList(n + 1);

    for (ll i = 1; i < n + 1; ++i) {
        addEdge(graph, 0, i, 0);
    }

    if (!bellmanFord(graph, n + 1, h)) {
        cout << "Negative-weight cycle found\n";
        return;
    }

    graph.resize(graph.size() - n);

    for (auto& edge : graph) {
        edge.weight += h[edge.source] - h[edge.destination];
    }

    for (auto& edge : graph) {
        adjList[edge.source].push_back({edge.destination, edge.weight});
    }

    ll sum = 0;
    for (int u = 1; u <= n; ++u) {
        dijkstra(adjList, u, modifiedWeights);
        for (int v = 1; v <= n; ++v) {
            if (modifiedWeights[v] != INF) {
                sum += modifiedWeights[v] + h[v] - h[u];
            }
        }
    }
    cout << sum << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, m, u, v, w;
    vector<Edge> graph;
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    johnsonsAlgorithm(graph, n);

    return 0;
}
