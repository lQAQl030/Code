#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct vertex{
    ll w = 0;
    bool color = true;
    list<int> pi;
    list<int> edges;
    // Dont need other arguments
};

class Graph{
    public:
    map<int, vertex> vertices;
    
    void add_vertex(int u, int w){
        vertices[u].w = w;
    }

    void add_edge(int u, int v){
        vertices[u].edges.push_back(v);
        vertices[v].pi.push_back(u);
    }

    void DFS_visit(int u, vector<int> &arr){
        vertices[u].color = false;
        for(auto it = vertices[u].edges.begin() ; it != vertices[u].edges.end() ; it++){
            if(vertices[*it].color){
                DFS_visit(*it, arr);
            }
        }
        arr.push_back(u);
    }

    void DFS(vector<int> &arr){
        for(auto it = vertices.begin() ; it != vertices.end() ; it++){
            if(it->second.color) DFS_visit(it->first, arr);
        }
    }
};

void topo(Graph &graph, vector<int> &arr){
    graph.DFS(arr);
    return;
}

int main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);

    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    Graph graph;
    int n, m, w, u, v;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> w;
        graph.add_vertex(i, w);
    }
    for(int i = 0 ; i < m ; i++){
        cin >> u >> v;
        graph.add_edge(u, v);
    }

    vector<int> arr;
    topo(graph, arr); // reverse topological order

    //DP
    ll max_w = graph.vertices[arr.back()].w;
    for(int i = arr.size() - 2 ; i >= 0 ; i--){
        ll *v_weight = &graph.vertices[arr[i]].w;
        ll u_weight_max = INT_MIN;
        for(auto it = graph.vertices[arr[i]].pi.begin() ; it != graph.vertices[arr[i]].pi.end() ; it++){
            ll *u_weight = &graph.vertices[*it].w;
            u_weight_max = max(*u_weight, u_weight_max);
        }
        *v_weight = (u_weight_max > 0) ? *v_weight + u_weight_max : *v_weight;
        max_w = max(max_w, *v_weight);
    }
    cout << max_w;

    return 0;
}