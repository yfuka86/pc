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
  int lca(int u, int v) const { int l = in[u], r = out[v]; if (l > r) swap(l, r); return node[st.rmq(l, r).second]; }
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

void solve() {
  ll N, M; cin >> N >> M;
  EulerTour<ll> G(N);
  rep(i, M) {
    ll u,v; cin >> u >> v; u--; v--;
    G.add_edge(u, v);
  }
  G.build();
  string S; cin >> S;
  vl s(N, 0); rep(i, N) if (S[i] == '1') s[i] = 1;

  vl used(N, 0), ans;
  auto add = [&](ll n) { ans.pb(n); used[n]^= 1; };

  add(0);
  rep2(i, 1, G.node.size() - 1) {
    ll n = G.node[i];
    if (G.in[n] == G.out[n]) {
      // 葉の場合
      if (s[n]) add(n);
    } else {
      if (ans.back() != n) add(n);
      // 最後出る前に親との間を往復
      if (G.out[n] == i) if (s[n] ^ used[n]) { add(G.par[n]); add(n); }
    }
  }
  if (s[0] ^ used[0]) { ans.erase(ans.begin()); used[0] ^= 1; }

  cout << ans.size() << "\n";
  coutarray(ans, 1);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
