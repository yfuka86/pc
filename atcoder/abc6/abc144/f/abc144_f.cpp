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
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 2 - 10; const ll LINF = LLONG_MAX / 2 - 10; const double DINF = numeric_limits<double>::infinity();

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

vl topo_sort(Graph<ll> G) {
  ll n = G.size(); vl deg(n), ret; priority_queue<ll, vl, greater<ll>> que;
  rep(i, n) for (Edge e: G[i]) deg[e.to]++; rep(i, n) if (deg[i] == 0) que.push(i);
  while (!que.empty()) { ll v = que.top(); que.pop(); ret.pb(v);
    for(ll next: G[v]) { deg[next]--; if (deg[next] == 0) que.push(next); } G[v].clear(); }
  if (accumulate(all(deg), 0LL) != 0) return {}; else return ret; }

void solve() {
  ll N, M; cin >> N >> M;
  Graph<ll> G(N);

  vector<LP> edges(M);
  rep(i, M) {
    ll s, t; cin >> s >> t; s--; t--;
    edges[i] = {s, t};
    G.add_directed_edge(s, t);
  }

  vl tv = topo_sort(G);

  // 確率
  vector<ld> dp(N, 0);
  dp[0] = 1;
  for (auto v: tv) {
    for (auto to: G[v]) {
      dp[to] += dp[v] / G[v].size();
    }
  }
  // coutarray(dp);

  // そこからの移動回数期待値
  vector<ld> dpt(N, 0);
  reverse(all(tv));
  for (auto v: tv) {
    ld sum = 0;
    for (auto to: G[v]) {
      sum += dpt[to] + 1;
    }
    dpt[v] = G[v].size() ? sum / G[v].size() : 0;
  }
  // coutarray(dpt);

  // 辺消去のシミュレーション
  ld subt = 0;
  rep(i, N) {
    if (G[i].size() < 2) continue;
    ld nextma = 0;
    for (auto to: G[i]) {
      chmax(nextma, dpt[to] + 1);
    }
    ld newdpt = (dpt[i] * G[i].size() - nextma) / (G[i].size() - 1);
    // cout << dp[i] << " " << G[i].size() << " " << nextma << " " << dpt[i] << " " << newdpt << "\n";
    // cout << dpt[i] << " " << newdpt << "\n";
    chmax(subt, dp[i] * (dpt[i] - newdpt));
  }

  cout << fixed << setprecision(10) << dpt[0] - subt << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
