#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<typename T>
struct lca {
  int n, root, l;
  vector<vector<int>> to;
  vector<vector<T>> co;
  vector<int> dep;
  vector<T> costs;
  vector<vector<int>> par;
  lca(int n):n(n),to(n),co(n),dep(n),costs(n) {
    l = 0;
    while ((1<<l) < n) ++l;
    par = vector<vector<int>>(n+1,vector<int>(l,n));
  }
  void addEdge(int a, int b, T c=0) {
    to[a].push_back(b); co[a].push_back(c);
    to[b].push_back(a); co[b].push_back(c);
  }
  void dfs(int v, int d=0, T c=0, int p=-1) {
    if (p != -1) par[v][0] = p;
    dep[v] = d;
    costs[v] = c;
    for (int i = 0; i < to[v].size(); ++i) {
      int u = to[v][i];
      if (u == p) continue;
      dfs(u, d+1, c+co[v][i], v);
    }
  }

  void init(int _root=0) {
    root = _root;
    dfs(root);
    for (int i = 0; i < l-1; ++i) {
      for (int v = 0; v < n; ++v) {
        par[v][i+1] = par[par[v][i]][i];
      }
    }
  }
  // LCA
  int operator()(int a, int b) {
    if (dep[a] > dep[b]) swap(a,b);
    int gap = dep[b]-dep[a];
    for (int i = l-1; i >= 0; --i) {
      int len = 1<<i;
      if (gap >= len) {
        gap -= len;
        b = par[b][i];
      }
    }
    if (a == b) return a;
    for (int i = l-1; i >= 0; --i) {
      int na = par[a][i];
      int nb = par[b][i];
      if (na != nb) a = na, b = nb;
    }
    return par[a][0];
  }
  int length(int a, int b) {
    int c = lca(a,b);
    return dep[a]+dep[b]-dep[c]*2;
  }
  T dist(int a, int b) {
    int c = lca(a,b);
    return costs[a]+costs[b]-costs[c]*2;
  }
};


const int MX = 100005;
struct Edge {
  int to, co, col;
  Edge(int to, int co, int col):to(to),co(co),col(col) {}
};
vector<Edge> es[MX];

vector<ll> ans;
struct Query {
  int col, qid, coeff, y;
  Query(int col, int qid, int coeff, int y):col(col),qid(qid),coeff(coeff),y(y) {}
};
vector<Query> qs[MX];
int cnt[MX];
ll sum[MX];

void dfs2(int v, int p=-1) {
  for (auto q : qs[v]) {
    ll x = -sum[q.col];
    x += (ll)q.y*cnt[q.col];
    ans[q.qid] += x*q.coeff;
  }
  for (auto e : es[v]) {
    if (e.to == p) continue;
    cnt[e.col]++; sum[e.col] += e.co;
    dfs2(e.to, v);
    cnt[e.col]--; sum[e.col] -= e.co;
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  lca<ll> g(n);
  rep(i,n-1) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a; --b;
    es[a].emplace_back(b,d,c);
    es[b].emplace_back(a,d,c);
    g.addEdge(a,b,d);
  }
  g.init();
  ans = vector<ll>(q);
  rep(i,q) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    --a; --b;
    int c = g(a,b);
    ans[i] = g.costs[a]+g.costs[b]-g.costs[c]*2;
    qs[a].emplace_back(x,i,1,y);
    qs[b].emplace_back(x,i,1,y);
    qs[c].emplace_back(x,i,-2,y);
  }
  dfs2(0);
  rep(i,q) {
    printf("%lld\n",ans[i]);
  }
  return 0;
}
