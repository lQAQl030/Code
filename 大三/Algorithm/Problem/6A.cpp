#include<bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX
#define int long long int

struct Edge {
    int u, v, weight, color;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == -1)
        return vertex;
    return parent[vertex] = findParent(parent[vertex], parent);
}

void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
    int parentA = findParent(a, parent);
    int parentB = findParent(b, parent);

    if (parentA != parentB) {
        if (rank[parentA] < rank[parentB])
            swap(parentA, parentB);
        parent[parentB] = parentA;
        if (rank[parentA] == rank[parentB])
            rank[parentA]++;
    }
}

vector<int> ans;

void minCostToMaintainConnectivity(int n, int k, vector<int>& colorCosts, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n + 1, -1);
    vector<int> rank(n + 1, 0);

    int minCost = 0;
    vector<bool> colorUsed(k + 1, false);

    for (Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;
        int color = edge.color;

        if (findParent(u, parent) != findParent(v, parent)) {
            minCost += weight;
            if (!colorUsed[color]) {
                minCost += colorCosts[color];
                colorUsed[color] = true;
            }
            unionSets(u, v, parent, rank);
        }
    }

    for (int i = 1 ; i <= n-1 ; i++) {
        if (findParent(i, parent) != findParent(i+1, parent)) {
            return;
        }
    }

    if(minCost != 0) ans.push_back(minCost);
}

void generateSubsets(vector<vector<Edge>>& nums, vector<vector<Edge>>& subset, int index, int &n, int &k, vector<int>& colorCosts) {
    // Base case: if index reaches the size of nums, print the subset
    if (index == nums.size()) {
        vector<Edge> selected;
        for (auto &sub : subset) {
            copy(sub.begin(), sub.end(), back_inserter(selected));
        }
        minCostToMaintainConnectivity(n, k, colorCosts, selected);
        return;
    }

    // Exclude current element
    generateSubsets(nums, subset, index + 1, n, k, colorCosts);

    // Include current element
    subset.push_back(nums[index]);
    generateSubsets(nums, subset, index + 1, n, k, colorCosts);

    // Backtrack
    subset.pop_back();
}

void generateAllSubsets(vector<vector<Edge>>& nums, int &n, int &k, vector<int>& colorCosts) {
    vector<vector<Edge>> subset;
    generateSubsets(nums, subset, 0, n, k, colorCosts);
}

signed main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> colorCosts(k + 1);
    for (int i = 1; i <= k; ++i)
        cin >> colorCosts[i];

    vector<vector<Edge>> edges(k+1);
    for (int i = 0; i < m; ++i){
        int u,v,weight,color;
        cin >> u >> v >> weight >> color;
        edges[color].push_back({u,v,weight,color});
    }

    generateAllSubsets(edges, n, k, colorCosts);

    sort(ans.begin(), ans.end());
    // for(int &i : ans) cout << i << " ";
    cout << ans[0] << endl;

    return 0;
}