#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define int long long int

struct Dinic {
  struct edge {
    int to, cap, flow, rev;
  };
  static constexpr int MAXN = 1100, MAXF = 1e9; // Adjust MAXN according to the problem constraint
  vector<edge> v[MAXN];
  int top[MAXN], deep[MAXN], side[MAXN], s, t;
  void make_edge(int s, int t, int cap) {
    v[s].push_back({t, cap, 0, (int)v[t].size()});
    v[t].push_back({s, 0, 0, (int)v[s].size() - 1});
  }
  int dfs(int a, int flow) {
    if (a == t || !flow) return flow;
    for (int &i = top[a]; i < v[a].size(); i++) {
      edge &e = v[a][i];
      if (deep[a] + 1 == deep[e.to] && e.cap - e.flow) {
        int x = dfs(e.to, min(e.cap - e.flow, flow));
        if (x) {
          e.flow += x, v[e.to][e.rev].flow -= x;
          return x;
        }
      }
    }
    deep[a] = -1;
    return 0;
  }
  bool bfs() {
    queue<int> q;
    fill_n(deep, MAXN, 0);
    q.push(s), deep[s] = 1;
    int tmp;
    while (!q.empty()) {
      tmp = q.front(), q.pop();
      for (edge e : v[tmp])
        if (!deep[e.to] && e.cap != e.flow)
          deep[e.to] = deep[tmp] + 1, q.push(e.to);
    }
    return deep[t];
  }
  int max_flow(int _s, int _t) {
    s = _s, t = _t;
    int flow = 0, tflow;
    while (bfs()) {
      fill_n(top, MAXN, 0);
      while ((tflow = dfs(s, MAXF))) flow += tflow;
    }
    return flow;
  }
  void reset() {
    fill_n(side, MAXN, 0);
    for (auto &i : v) i.clear();
  }
};

signed main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  
  Dinic graph;
  
  int source = 0, sink = n + m + 1;

  for (int i = 1; i <= n; ++i) {
    int vi;
    cin >> vi;
    graph.make_edge(source, i, vi);
  }
  
  int price = 0;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph.make_edge(u, n+i, INF);
    graph.make_edge(v, n+i, INF);
    graph.make_edge(n+i, sink, w);
    price += w;
  }
  
  int max_value = graph.max_flow(source, sink);

  
  cout << price - max_value << endl;
  
  return 0;
}
