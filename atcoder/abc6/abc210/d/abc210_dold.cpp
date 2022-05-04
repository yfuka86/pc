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

template< typename T = ll > struct Edge {
  int from, to; T cost; int idx; Edge() = default; Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; } bool operator<(const struct Edge& other) const { return cost < other.cost; } };
template< typename T = ll > struct Graph {
  vector< vector< Edge< T > > > g; int es; Graph() = default; explicit Graph(int n) : g(n), es(0) {}
  size_t size() const { return g.size(); }
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }
  void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };

vector<ll> dijkstra(Graph<ll> &G, ll start) {
  priority_queue<LP, vector<LP>, greater<LP>> PQ; vector<ll> costs(G.size(), LINF); PQ.push(make_pair(0, start));
  while(!PQ.empty()) {
    auto [c, v] = PQ.top(); PQ.pop(); if (costs[v] <= c) continue; else costs[v] = c;
    for(Edge e: G[v]) { ll nc = costs[v] + e.cost; if (costs[e.to] > nc) PQ.push(make_pair(nc, e.to)); } }
  return costs; }

vl dx = {1, -1, 0, 0};
vl dy = {0, 0, 1, -1};

void solve() {
  ll H, W, C; cin >> H >> W >> C;
  vector<vl> a(H, vl(W, 0)); rep(i, H) rep(j, W) cin >> a[i][j];

  vector<vl> dp(H + 1, vl(W + 1, LINF));
  vector<vl> dprev(H + 1, vl(W + 1, LINF));

  ll ans = LINF;
  rep(i, H) {
    rep(j, W) {
      if (i != 0 || j != 0) chmin(ans, dp[i][j] + a[i][j]);
      chmin(dp[i][j], a[i][j]);
      if (i < H - 1) chmin(dp[i + 1][j], dp[i][j] + C);
      if (j < W - 1) chmin(dp[i][j + 1], dp[i][j] + C);
    }
  }

  rep(i, H) {
    rep_r(j, W) {
      if (i != 0 || j != W - 1) chmin(ans, dprev[i][j] + a[i][j]);
      chmin(dprev[i][j], a[i][j]);
      if (i < H - 1) chmin(dprev[i + 1][j], dprev[i][j] + C);
      if (j > 0) chmin(dprev[i][j - 1], dprev[i][j] + C);
    }
  }

  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
