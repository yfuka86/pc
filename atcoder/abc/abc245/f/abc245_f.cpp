#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#include <atcoder/scc>

using namespace atcoder;
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM;
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
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }
  void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };
//------------------------------------------------------------------------------
struct UnionFind {
  vector<ll> par, s, e;
  UnionFind(ll N) : par(N), s(N), e(N) { rep(i,N) { par[i] = i; s[i] = 1; e[i] = 0; } }
  ll root(ll x) { return par[x]==x ? x : par[x] = root(par[x]); }
  ll size(ll x) { return par[x]==x ? s[x] : s[x] = size(root(x)); }
  ll edge(ll x) { return par[x]==x ? e[x] : e[x] = edge(root(x)); }
  void unite(ll x, ll y) { ll rx=root(x), ry=root(y); if (size(rx)<size(ry)) swap(rx,ry); if (rx!=ry) { s[rx] += s[ry]; par[ry] = rx; e[rx] += e[ry]+1; } else e[rx]++; }
  bool same(ll x, ll y) {  ll rx=root(x), ry=root(y); return rx==ry; }
};
//------------------------------------------------------------------------------


void solve() {
  ll n, m; cin >> n >> m;
  if (n == 1) { cout << 0 << "\n"; return; }

  Graph<ll> G(n);
  scc_graph g(n);
  rep(i, m) {
    ll u, v; cin >> u >> v; u--; v--;
    g.add_edge(u, v);
    G.add_directed_edge(u, v);
  }
  auto scc = g.scc();
  vl able(n, 0);
  for (auto v : scc) {
    if (v.size() > 1) for (auto i: v) able[i] = 1;
  }

  vl used(n, 0);
  function<void(ll)> dfs = [&](ll v) {
    if (used[v]) return;
    used[v] = 1;

    for (auto to: G[v]) {
      able[v] |= able[to];
      dfs(to);
    }
  };

  reverse(all(scc));
  for (auto v : scc) {
    for (ll from: v) {
      if (!used[from]) dfs(from);
    }
  }

  ll ans = 0;
  rep(i, n) if (able[i]) ans++;
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
