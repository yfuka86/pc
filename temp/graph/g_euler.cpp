template< typename T = ll > struct Edge {
  int from, to; T cost; int idx; Edge() = default; Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; } bool operator<(const struct Edge& other) const { return cost < other.cost; } };
template< typename T = ll > struct Graph {
  vector< vector< Edge< T > > > g; int es; Graph() = default; explicit Graph(int n) : g(n), es(0) {}
  size_t size() const { return g.size(); }
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }
  void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };
template< typename T > struct SparseTable {
  vector< vector< T > > st; vector< int > lookup;
  SparseTable() = default;
  void build(const vector< T > &v) {
    int b = 0; while((1 << b) <= v.size()) ++b; st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) st[0][i] = v[i];
    for(int i = 1; i < b; i++) for(int j = 0; j + (1 << i) <= (1 << b); j++) st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    lookup.resize(v.size() + 1); for(int i = 2; i < lookup.size(); i++) lookup[i] = lookup[i >> 1] + 1; }
  inline T rmq(int l, int r) const { int b = lookup[r - l]; return min(st[b][l], st[b][r - (1 << b)]); } };

template< typename T = ll >
struct EulerTour : Graph<T> {
public:
  using Graph<T>::Graph; using Graph<T>::g; vector<int> in, out, par, dep, node, edge; vector<ll> edgec; SparseTable<LP> st;
  void build() {
    ll n = g.size(), len = n * 2; in.assign(n, -1); out.assign(n, -1); par.assign(n, -1); dep.assign(len, -1); node.assign(len - 1, -1); edge.assign(len, 0); edgec.assign(len, 0);
    int t = 0; dfs(Edge<T>(-1, 0, 0), 0, t);
    vector<LP> tmp(len); rep(i, len) tmp[i] = mp(dep[i], i); st.build(tmp);
  }
  int depth(int u) const { return dep[in[u]]; }
  int subtree_size(int u) const { return (out[u] - in[u] + 1) / 2; }
  int lca(int u, int v) const { int l = in[u], r = out[v] + 1; if (l > r) swap(l, r); return node[st.rmq(l, r).second]; }
  int dist(int u, int v) const { return depth(u) + depth(v) - 2 * depth(lca(u, v)); }

private:
  void dfs(Edge<T> e, int d, int &cur) {
    int p = e.from, v = e.to; par[v] = p; dep[cur] = d; node[cur] = v; edge[cur] = v; edgec[cur] = e.cost; in[v] = cur++;
    for(Edge<T> &next : g[v]) {
      if(next.to == p || in[next.to] != -1) continue;
      dfs(next, d + 1, cur);
      cur++;
    }
    out[v] = cur - 1; dep[cur] = d - 1; node[cur] = p; edge[cur] = -e.to; edgec[cur] = -e.cost;
  }
};
