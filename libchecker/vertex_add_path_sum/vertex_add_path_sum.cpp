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
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template <class T> T POW(T x, int n) { assert(n >= 0); T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

template< typename T = ll > struct Edge {
  int from, to; T cost; int idx; Edge() = default; Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; } bool operator<(const struct Edge& other) const { return cost < other.cost; } };
template< typename T = ll > struct Graph {
  vector< vector< Edge< T > > > g; int es; Graph() = default; explicit Graph(int n) : g(n), es(0) {}
  size_t size() const { return g.size(); }
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); } void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };

template< typename T = ll >
struct HeavyLightDecomposition : Graph< T > {
public:
  using Graph< T >::Graph; using Graph< T >::g; vector< int > sz, in, out, head, rev, par, dep;
  void build() {
    sz.assign(g.size(), 0); in.assign(g.size(), 0); out.assign(g.size(), 0); head.assign(g.size(), 0); rev.assign(g.size(), 0); par.assign(g.size(), 0); dep.assign(g.size(), 0);
    dfs_sz(0, -1, 0); int t = 0; dfs_hld(0, -1, t); }
  /* k: 0-indexed */
  int la(int v, int k) { while(1) { int u = head[v]; if(in[v] - k >= in[u]) return rev[in[v] - k]; k -= in[v] - in[u] + 1; v = par[u]; } }
  int lca(int u, int v) const { for(;; v = par[head[v]]) { if(in[u] > in[v]) swap(u, v); if(head[u] == head[v]) return u; } }
  int dist(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
  template< typename E, typename Q, typename F, typename S >
  E query(int u, int v, const E &ti, const Q &q, const F &f, const S &s, bool edge = false) {
    E l = ti, r = ti; for(;; v = par[head[v]]) { if(in[u] > in[v]) swap(u, v), swap(l, r); if(head[u] == head[v]) break; l = f(q(in[head[v]], in[v] + 1), l); }
    return s(f(q(in[u] + edge, in[v] + 1), l), r); }
  template< typename E, typename Q, typename F >
  E query(int u, int v, const E &ti, const Q &q, const F &f, bool edge = false) { return query(u, v, ti, q, f, f, edge); }
  template< typename Q >
  void add(int u, int v, const Q &q, bool edge = false) { for(;; v = par[head[v]]) { if(in[u] > in[v]) swap(u, v); if(head[u] == head[v]) break; q(in[head[v]], in[v] + 1); } q(in[u] + edge, in[v] + 1); }
  /* {parent, child} */
  vector< pair< int, int > > compress(vector< int > &remark) {
    auto cmp = [&](int a, int b) { return in[a] < in[b]; };
    sort(begin(remark), end(remark), cmp); remark.erase(unique(begin(remark), end(remark)), end(remark));
    int K = (int) remark.size(); for(int k = 1; k < K; k++) remark.emplace_back(lca(remark[k - 1], remark[k]));
    sort(begin(remark), end(remark), cmp); remark.erase(unique(begin(remark), end(remark)), end(remark));
    vector< pair< int, int > > es; stack< int > st;
    for(auto &k : remark) { while(!st.empty() && out[st.top()] <= in[k]) st.pop(); if(!st.empty()) es.emplace_back(st.top(), k); st.emplace(k); }
    return es; }
  explicit HeavyLightDecomposition(const Graph< T > &g) : Graph< T >(g) {}
private:
  void dfs_sz(int idx, int p, int d) {
    dep[idx] = d; par[idx] = p; sz[idx] = 1;
    if(g[idx].size() && g[idx][0] == p) swap(g[idx][0], g[idx].back());
    for(auto &to : g[idx]) { if(to == p) continue; dfs_sz(to, idx, d + 1); sz[idx] += sz[to]; if(sz[g[idx][0]] < sz[to]) swap(g[idx][0], to); } }
  void dfs_hld(int idx, int p, int &times) {
    in[idx] = times++; rev[in[idx]] = idx;
    for(auto &to : g[idx]) { if(to == p) continue; head[to] = (g[idx][0] == to ? head[idx] : to); dfs_hld(to, idx, times); }
    out[idx] = times; }
};
template<typename T>
struct BIT {
  int n; vector<T> bit;
  BIT(int _n = 0) : n(_n), bit(n + 1) {}
  // sum of [0, i), 0 <= i <= n
  T sum(int i) { T s = 0; while (i > 0) { s += bit[i]; i -= i & -i; } return s;}
  // 0 <= i < n
  void add(int i, T x) { ++i; while (i <= n) { bit[i] += x; i += i & -i; } }
  //[l, r) 0 <= l < r < n
  T sum(int l, int r) { return sum(r) - sum(l); }
  // smallest i, sum(i) >= w, none -> n
  int lower_bound(T w) {
    if (w <= 0) return 0; int x = 0, l = 1; while (l * 2 <= n) l <<= 1;
    for (int k = l; k > 0; k /= 2) if (x + k <= n && bit[x + k] < w) { w -= bit[x + k]; x += k; }
    return x; }
};


void solve() {
  ll N, Q; cin >> N >> Q;
  vl a(N); rep(i, N) cin >> a[i];
  HeavyLightDecomposition<ll> G(N);
  rep2(i, 1, N) {
    ll u, v; cin >> u >> v;
    G.add_edge(u, v);
  }
  G.build();
  BIT<ll> bs(N);
  rep(i, N) { bs.add(G.in[i], a[i]); }

  rep(i, Q) {
    ll q; cin >> q;
    if (q) {
      ll u, v; cin >> u >> v;
      ll lca = G.lca(u, v), ans = 0;
      ans += G.query(lca, u, 0LL, [&](ll a, ll b) { return bs.sum(a, b); }, [](ll a, ll b) {return a + b;});
      ans += G.query(lca, v, 0LL, [&](ll a, ll b) { return bs.sum(a, b); }, [](ll a, ll b) {return a + b;});
      cout << ans - bs.sum(G.in[lca], G.in[lca] + 1) << "\n";
    } else {
      ll p, x; cin >> p >> x;
      ll v = G.in[p];
      bs.add(v, x);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
