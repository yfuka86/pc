#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll lint(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  vl vlint(ll l, ll a, ll b) { ud d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vlperm(ll l) { vl perm(l); iota(all(perm), 1); random_shuffle(all(perm)); return perm; }
  string saz(ll l, ll a = 0, ll z = 26) { vl az = vlint(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string snum(ll l, ll zero = 0, ll ten = 10) { vl zt = vlint(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
};
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a){ sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};

// https://nyaannyaan.github.io/library/tree/heavy-light-decomposition.hpp

template< typename T = ll > struct Edge {
  int from, to; T cost; int idx; Edge() = default; Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; } bool operator<(const struct Edge& other) const { return cost < other.cost; } };
template< typename T = ll > struct Graph {
  vector< vector< Edge< T > > > g; int es; Graph() = default; explicit Graph(int n) : g(n), es(0) {}
  size_t size() const { return g.size(); }
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }
  void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };

template <typename G>
struct HeavyLightDecomposition {
 private:
  void dfs_sz(int cur) {
    size[cur] = 1;
    for (auto& dst : g[cur]) {
      if (dst == par[cur]) { if (g[cur].size() >= 2 && int(dst) == int(g[cur][0])) swap(g[cur][0], g[cur][1]); else continue; }
      depth[dst] = depth[cur] + 1; par[dst] = cur; dfs_sz(dst); size[cur] += size[dst]; if (size[dst] > size[g[cur][0]]) swap(dst, g[cur][0]);
    }
  }
  void dfs_hld(int cur) {
    down[cur] = id++;
    for (auto dst : g[cur]) { if (dst == par[cur]) continue; nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst)); dfs_hld(dst); }
    up[cur] = id;
  }
  // [u, v)
  vector<pair<int, int>> ascend(int u, int v) const {
    vector<pair<int, int>> res;
    while (nxt[u] != nxt[v]) { res.emplace_back(down[u], down[nxt[u]]); u = par[nxt[u]]; }
    if (u != v) res.emplace_back(down[u], down[v] + 1); return res;
  }
  // (u, v]
  vector<pair<int, int>> descend(int u, int v) const {
    if (u == v) return {};
    if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};
    auto res = descend(u, par[nxt[v]]);
    res.emplace_back(down[nxt[v]], down[v]);
    return res;
  }
 public:
  G& g; int id; vector<int> size, depth, down, up, nxt, par;
  HeavyLightDecomposition(G& _g, int root = 0): g(_g), id(0), size(g.size(), 0), depth(g.size(), 0), down(g.size(), -1), up(g.size(), -1), nxt(g.size(), root), par(g.size(), root) { dfs_sz(root); dfs_hld(root); }
  void build(int root) { dfs_sz(root); dfs_hld(root); }
  pair<int, int> idx(int i) const { return make_pair(down[i], up[i]); }
  template <typename F>
  void path_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) { int s = a + 1, t = b; s > t ? f(t, s) : f(s, t); }
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) { int s = a, t = b + 1; s > t ? f(t, s) : f(s, t); }
  }
  template <typename F>
  void path_noncommutative_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) f(a, b + 1);
  }
  template <typename F>
  void subtree_query(int u, bool vertex, const F& f) { f(down[u] + int(!vertex), up[u]); }
  int lca(int a, int b) { while (nxt[a] != nxt[b]) { if (down[a] < down[b]) swap(a, b); a = par[nxt[a]]; } return depth[a] < depth[b] ? a : b; }
  int dist(int a, int b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }
};

Graph<ll> build_aux_tree(HeavyLightDecomposition<Graph<ll>> &hld, vl& vs) {
  vlp v;
  for(auto &vv: vs) v.pb({hld.down[vv], vv});
  sort(all(v));

  ll sz = v.size();
  rep(i, sz) {
    ll lca = hld.lca(v[i].second, v[(i + 1) % sz].second);
    v.pb({hld.down[lca], lca});
  }
  sort(all(v)); v.erase(unique(all(v)), v.end());

  Graph<ll> G(hld.g.size()); stack<ll> st;
  st.push(v[0].second);
  rep2(i, 1, v.size()) {
    auto [_, next] = v[i];
    while (hld.up[st.top()] < hld.up[next]) st.pop();
    G.add_edge(st.top(), next);
    st.push(next);
  }
  return G;
}

void solve() {
  ll n, k; cin >> n >> k;
  ll x, y; cin >> x >> y; x--; y--;
  vl a(k); rep(i, k) { cin >> a[i]; a[i]--; }
  Graph<ll> G(n);
  rep(i, n - 1) {
    ll u, v; cin >> u >> v; u--; v--;
    G.add_edge(u, v);
  }
  HeavyLightDecomposition hld(G);
  // auxiliary tree構築
  a.pb(x); a.pb(y);
  Graph<ll> aG = build_aux_tree(hld, a);

  vl dp(n, 0);
  function<void(ll, ll)> dfs = [&](ll v, ll p) {
    for (auto to: aG[v]) {
      if (to == p) continue;
      dp[v] += hld.dist(v, to) * 2;
      dfs(to, v);
      dp[v] += dp[to];
    }
  };

  dfs(x, -1);
  cout << dp[x] - hld.dist(x, y) << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}
