#include <bits/stdc++.h>
using namespace std;

struct vertex{
    // Set
    int p;
    int rank;
    int black_num = 1;
    bool black = true;

    // Vertex
    bool v_color = true; // false = visited
    int d = INT_MAX;
    list<int> edges;
};

class Graph{
    public:
    vector<vertex> vertices;

    void link(int x, int y){
        int sum = vertices[x].black_num + vertices[y].black_num;

        if(vertices[x].rank > vertices[y].rank){
            vertices[y].p = x;
            vertices[x].black_num = sum;
        }else{
            vertices[x].p = y;
            vertices[y].black_num = sum;
            if(vertices[x].rank == vertices[y].rank){
                vertices[y].rank++;
            }
        }
    }

    int find_set(int x, int black_num = 0){
        if(x != vertices[x].p){
            vertices[x].p = find_set(vertices[x].p);
        }
        return vertices[x].p;
    }

    int find_black(int x){
        return vertices[find_set(x)].black_num;
    }

    void s_union(int x, int y){
        int left = find_set(x);
        int right = find_set(y);
        if(left != right) link(left, right);
    }

    void add_vertex(int u){
        vertices[u].p = u;
        vertices[u].rank = 0;
    }

    void add_edge(int u, int v){
        // Set
        s_union(u, v);
        // Vertex
        vertices[u].edges.push_back(v);
        vertices[v].edges.push_back(u);
    }

    int BFS(int s){
        vector<bool> visited(vertices.size(), true);
        visited[s] = false;
        vertices[s].d = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(vertices[u].black) return vertices[u].d;
            for(int &v : vertices[u].edges){
                if(visited[v]){
                    visited[v] = false;
                    vertices[v].d = vertices[u].d + 1;
                    q.push(v);
                }
            }
        }
        return -1;
    }

};

int main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Graph graph;

    int n, q, u, v, query;
    cin >> n >> q;
    graph.vertices.resize(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> u;
        graph.add_vertex(i);
        if(u == 0){
            graph.vertices[i].black_num = 0;
            graph.vertices[i].black = false;
        }
    }

    for(int qq = 0 ; qq < q ; qq++){
        cin >> query;
        if(query == 1){
            cin >> u >> v;
            graph.add_edge(u,v);
        }else if(query == 2){
            cin >> u;
            cout << graph.find_black(u) << '\n';
        }else{
            cin >> u;
            cout << graph.BFS(u) << '\n';
        }
    }

    return 0;
}