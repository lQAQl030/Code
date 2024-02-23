class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({distance, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        int minCost = 0;
        int numEdges = 0;

        for (const auto& edge : edges) {
            int distance = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            int rootU = find(u);
            int rootV = find(v);

            if (rootU != rootV) {
                parent[rootU] = rootV;
                minCost += distance;
                ++numEdges;
                if (numEdges == n - 1) {
                    break;
                }
            }
        }

        return minCost;
    }
};