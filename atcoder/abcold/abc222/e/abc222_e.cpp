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
const int max_n = 1 << 20;
mint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); }
  factinv[max_n - 1] = mint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
mint comb(int a, int b) { assert(fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
mint combP(int a, int b) { assert(fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, const ll &p = mod) { ll ret = 1; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
//------------------------------------------------------------------------------
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

void solve() {
  ll N, M, K; cin >> N >> M >> K;
  vl a(M);
  rep(i, M) { cin >> a[i]; a[i]--; }
  HeavyLightDecomposition<ll> hld(N);
  rep(i, N - 1) {
    ll u, v; cin >> u >> v; u--; v--;
    hld.add_edge(u, v);
  }
  hld.build();

  map<LP, ll> freq;
  rep(i, M - 1) {
    ll lca = hld.lca(a[i], a[i + 1]);
    ll a1 = a[i], a2 = a[i + 1];
    while (a1 != lca) {
      ll pa = hld.par[a1];
      if (pa > a1) freq[mp(a1, pa)]++; else freq[mp(pa, a1)]++;
      a1 = pa;
    }
    while (a2 != lca) {
      ll pa = hld.par[a2];
      if (pa > a2) freq[mp(a2, pa)]++; else freq[mp(pa, a2)]++;
      a2 = pa;
    }
  }

  // for (auto[p, n]: freq) {
  //   cout << p.first << ":" << p.second << " " << n << "\n";
  // }

  vmi dp(200000, 0), dptmp(200000, 0);
  dp[100000] = 1;

  for (auto[p, n]: freq) {
    rep(i, 200000) {
      if (dp[i] == 0) continue;
      if (i + n > 0 && i + n < 200000) dptmp[i + n] += dp[i];
      if (i - n > 0 && i - n < 200000) dptmp[i - n] += dp[i];
    }
    dp = dptmp;
    dptmp.clear(); dptmp.assign(200000, 0);
  }

  cout << dp[100000 + K] * mod_pow(2, N - 1 - freq.size()) << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
