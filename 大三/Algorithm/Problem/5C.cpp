#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    vector<list<int>> edges;
    vector<list<int>> redges;
    vector<bool> visited;
    vector<int> finish;
    vector<int> root;
    int isolated = 0;

    void add_edge(int u, int v){
        edges[u].push_back(v);
        redges[v].push_back(u);
    }
    
    void init(){
        finish.clear();
        visited.resize(edges.size());

        fill(visited.begin(), visited.end(), false);
        for(int i = 1 ; i < edges.size() ; i++) DFS(i);

        fill(visited.begin(), visited.end(), false);
        for(int i = finish.size() - 1 ; i >= 0 ; i--){
            root.clear();
            rDFS(finish[i], finish[i]);
            if(root.size() == 1) isolated++;
        }
    }

    void DFS(int u){
        if(visited[u]) return;
        visited[u] = true;
        for(int &v : edges[u]) DFS(v);
        finish.push_back(u);
    }

    void rDFS(int u, int absorb){
        if(visited[u]) return;
        visited[u] = true;
        for(int &v : redges[u]) rDFS(v, u);
        root.push_back(absorb);
    }
};

int main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);

    int n, m, u, v;
    cin >> n >> m;
    if(m == 0){
        cout << n << endl;
        return 0;
    }

    Graph graph;
    graph.edges.resize(n+1);
    graph.redges.resize(n+1);
    for(int i = 0 ; i < m ; i++){
        cin >> u >> v;
        graph.add_edge(u,v);
    }
    graph.init();

    // for(int &i : graph.finish) cout << i << " "; cout << endl;

    cout << graph.isolated << endl;

    return 0;
}