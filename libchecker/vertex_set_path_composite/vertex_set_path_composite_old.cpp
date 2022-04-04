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
const int INF = numeric_limits<int>::max(); const ll LINF = LLONG_MAX; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
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
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};

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

const ll mod = 998244353;
//------------------------------------------------------------------------------
template< int mod >
struct ModInt {
  int x; ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }
  ModInt &operator-=(const ModInt &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  ModInt &operator*=(const ModInt &p) { x = (int) (1LL * x * p.x % mod); return *this; }
  ModInt &operator/=(const ModInt &p) { *this *= p.inverse(); return *this; }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const { int a = x, b = mod, u = 1, v = 0, t; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } return ModInt(u); }
  ModInt pow(int64_t n) const { ModInt ret(1), mul(x); while(n > 0) { if(n & 1) ret *= mul; mul *= mul; n >>= 1; } return ret; }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
  static int get_mod() { return mod; }
};
using mint = ModInt< mod >;
typedef vector<mint> vmi;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
  segtree() : segtree(0) {}
  explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
  explicit segtree(const std::vector<S>& v) : _n(int(v.size())) { log = ceil_pow2(_n); size = 1 << log; d = std::vector<S>(2 * size, e()); for (int i = 0; i < _n; i++) d[size + i] = v[i]; for (int i = size - 1; i >= 1; i--) update(i); }
  void set(int p, S x) { assert(0 <= p && p < _n); p += size; d[p] = x; for (int i = 1; i <= log; i++) update(p >> i); }
  S get(int p) const { assert(0 <= p && p < _n); return d[p + size]; }
  S prod(int l, int r) const { assert(0 <= l && l <= r && r <= _n); S sml = e(), smr = e(); l += size; r += size; while (l < r) { if (l & 1) sml = op(sml, d[l++]); if (r & 1) smr = op(d[--r], smr); l >>= 1; r >>= 1; } return op(sml, smr); }
  S all_prod() const { return d[1]; }
  template <bool (*f)(S)> int max_right(int l) const { return max_right(l, [](S x) { return f(x); }); }
  template <class F> int max_right(int l, F f) const { assert(0 <= l && l <= _n); assert(f(e())); if (l == _n) return _n; l += size; S sm = e();
    do { while (l % 2 == 0) l >>= 1; if (!f(op(sm, d[l]))) { while (l < size) { l = (2 * l); if (f(op(sm, d[l]))) { sm = op(sm, d[l]); l++; } } return l - size; } sm = op(sm, d[l]); l++; } while ((l & -l) != l); return _n; }
  template <bool (*f)(S)> int min_left(int r) const { return min_left(r, [](S x) { return f(x); }); }
  template <class F> int min_left(int r, F f) const { assert(0 <= r && r <= _n); assert(f(e())); if (r == 0) return 0; r += size; S sm = e();
    do { r--; while (r > 1 && (r % 2)) r >>= 1; if (!f(op(d[r], sm))) { while (r < size) { r = (2 * r + 1); if (f(op(d[r], sm))) { sm = op(d[r], sm); r--; } } return r + 1 - size; } sm = op(d[r], sm); } while ((r & -r) != r); return 0; }
  private:
  int _n, size, log; std::vector<S> d;
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
//------------------------------------------------------------------------------

struct S { mint a, b; };
S op(S l, S r) { return { l.a * r.a, l.b * r.a + r.b }; }
S oprev(S r, S l) { return { l.a * r.a, l.b * r.a + r.b }; }
S opinv(S l, S r) { return { l.a / r.a, (l.b - r.b) / r.a }; }
S e() { return { mint(1), mint(0) }; }

void solve() {
  ll N, Q; cin >> N >> Q;
  vector<S> f(N); rep(i, N) { ll a, b; cin >> a >> b; f[i] = S{ a, b }; }
  HeavyLightDecomposition<ll> G(N);
  rep(i, N - 1) {
    ll u, v; cin >> u >> v;
    G.add_edge(u, v);
  }
  G.build();

  vector<S> b(N); rep(i, N) { b[G.in[i]] = f[i]; }
  segtree<S, op, e> seg(b);
  segtree<S, oprev, e> segrev(b);

  rep(i, Q) {
    ll q; cin >> q;
    if (q == 0) {
      ll p, c, d; cin >> p >> c >> d;
      seg.set(G.in[p], {c, d});
      segrev.set(G.in[p], {c, d});
    } else {
      ll u, v, x; cin >> u >> v >> x;
      ll lca = G.lca(u, v);
      S tmp = G.query(u, lca, e(), [&](ll l, ll r){ return segrev.prod(l, r); }, oprev);
      S ans = op(opinv(tmp, seg.get(G.in[lca])), G.query(lca, v, e(), [&](ll l, ll r){ return seg.prod(l, r); }, op));
      cout << ans.a * x + ans.b << "\n";
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
