template< typename T = ll > struct Edge {
  int from, to; T cost; int idx; Edge() = default; Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; } bool operator<(const struct Edge& other) const { return cost < other.cost; } };
template< typename T = ll > struct Graph {
  vector< vector< Edge< T > > > g; int es; Graph() = default; explicit Graph(int n) : g(n), es(0) {}
  size_t size() const { return g.size(); }
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }
  void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };

template <typename T, typename D, D (*merge)(D, D), D (*e)(),
          D (*leaf)(), D (*apply)(D, int, int, T)>
struct Rerooting : Graph<T> {
  vector<D> dp, memo;
  Rerooting(int n) : Graph<T>::Graph(n) {}
  vector<D> run() {
    memo.resize((*this).size(), e());
    dp.resize((*this).size());
    dfs1(0, -1);
    dfs2(0, -1, e());
    return dp;
  }
  void dfs1(int c, int p) {
    bool upd = false;
    for (Edge<T> &d : (*this)[c]) {
      if (d == p) continue;
      dfs1(d, c);
      upd = true;
      memo[c] = merge(memo[c], apply(memo[d], d, c, d.T));
    }
    if (!upd) memo[c] = leaf();
  }
  void dfs2(int c, int p, const D &val) {
    vector<D> ds{val};
    for (Edge<T> &d : (*this)[c]) {
      if (d == p) continue;
      ds.push_back(apply(memo[d], d, c, d.T));
    }
    int n = ds.size(), idx = 1;
    vector<D> head(n + 1, e()), tail(n + 1, e());
    for (int i = 0; i++ < n;) head[i] = merge(head[i - 1], ds[i - 1]);
    for (int i = n; i-- > 0;) tail[i] = merge(tail[i + 1], ds[i]);
    dp[c] = head[n];
    for (Edge<T> &d : (*this)[c]) {
      if (d == p) continue;
      D sub = merge(head[idx], tail[idx + 1]);
      dfs2(d, c, apply(sub, c, d, d.T));
      idx++;
    }
  }
};

using D = long long;
using T = long long;
D merge(D a, D b) { return max(a, b); }
D e() { return 0; }
D leaf() { return 0; }
D apply(D a, int c, int, T w) { return max<D>(a, D[c]) + w; }
Rerooting<T, D, merge, e, leaf, apply> g(N);
