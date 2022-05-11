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

vector<ll> dijkstra(Graph<ll> &G, ll start) {
  priority_queue<LP, vector<LP>, greater<LP>> que; vector<ll> costs(G.size(), LINF); que.push(make_pair(0, start));
  while(!que.empty()) {
    auto [c, v] = que.top(); que.pop(); if (costs[v] <= c) continue; else costs[v] = c;
    for(auto &to: G[v]) { ll nc = costs[v] + to.cost; if (costs[to] > nc) que.push(make_pair(nc, to)); } }
  return costs; }

using LT = tuple<ll, ll, ll>;

void solve() {
  ll n, m, k, l; cin >> n >> m >> k >> l;
  vl a(n), b(l);
  rep(i, n) { cin >> a[i]; a[i]--; }
  rep(i, l) { cin >> b[i]; b[i]--; }
  Graph<ll> G(n);
  rep(i, m) {
    ll u, v, c; cin >> u >> v >> c; u--; v--;
    G.add_edge(u, v, c);
  }
  priority_queue<LT, vector<LT>, greater<LT>> que;
  vector<vlp> costs(G.size(), vlp(2, mp(LINF, -1)));

  rep(i, l) {
    que.push({0, b[i], a[b[i]]});
    costs[b[i]][0] = mp(0, a[b[i]]);
  }

  vl cnt(n, 0);
  while(!que.empty()) {
    ll c, v, country; tie(c, v, country) = que.top(); que.pop();

    if (cnt[v] == 0) {
      costs[v][0] = mp(c, country);
      cnt[v]++;
    } else if (cnt[v] == 1 && costs[v][0].second != country) {
      costs[v][1] = mp(c, country);
      cnt[v]++;
    } else continue;

    for(Edge to: G[v]) {
      if (cnt[to] == 2) continue;
      ll nc = c + to.cost;
      que.push({nc, to, country});
    }
  }

  rep(i, n) {
    auto [c1, co1] = costs[i][0];
    auto [c2, co2] = costs[i][1];
    if (c1 != LINF && co1 != a[i]) cout << c1 << " ";
    else if (c2 != LINF) cout << c2 << " ";
    else cout << -1 << " ";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
