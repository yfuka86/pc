#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using uint = unsigned int; using ull = unsigned long long; using ld = long double; using i128 = __int128_t;
using P = pair<int, int>; using LP = pair<ll, ll>; using LT = tuple<ll, ll, ll>; using LT4 =  tuple<ll, ll, ll, ll>;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> v3l; typedef vector<v3l> v4l; typedef vector<v4l> v5l;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<LT> vlt; typedef vector<vlt> vvlt; typedef vector<LT4> vlt4; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb; typedef vector<vb> vvb;
template<typename T> using pq = priority_queue<T>; template<typename T> using mpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> class infinity{ public: static constexpr T MAX=numeric_limits<T>::max(); static constexpr T MIN=numeric_limits<T>::min(); static constexpr T val=numeric_limits<T>::max()/2-1e6; static constexpr T mval=numeric_limits<T>::min()/2+1e6; };
const int INF = infinity<int>::val; const ll LINF = infinity<ll>::val; const ld DINF = infinity<ld>::val;

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

vvl G;


ll cnt = 0;
vb vis;
void dfs(ll v) {
  vis[v] = 1;
  cnt++; cout << cnt << "\n"; cout.flush();
  for(ll to: G[v]) {
    if (vis[to]) continue;
    vis[to] = 1;
    dfs(to);
  }
}

void solve() {
  ll n, q; cin >> n >> q;
  vl a(n - 1), b(n - 1), c(n - 1), d(n - 1);
  for(ll i = 0; i < n - 1; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  for(ll i = 0; i < n - 1; i++) {
    a[i]--; b[i]--;
  }

  G.resize(n);
  vis.resize(n);
  for(ll i = 0; i < n - 1; i++) {
    G[i].push_back(i + 1);
    G[i + 1].push_back(i);
    // G[a[i]].push_back(b[i]);
    // G[b[i]].push_back(a[i]);
  }
  dfs(0);

  // stack<LP> st;
  // st.push({0, 1});
  // ll cnt = 0;
  // while(!st.empty()) {
  //   auto [v, cmd] = st.top(); st.pop();
  //   if (cmd) {
  //     cnt++; cout << cnt << "\n"; cout.flush();
  //     vis[v] = true;
  //     st.push({v, 0});
  //     for (auto to: G[v]) {
  //       if (vis[to]) continue;
  //       st.push({to, 1});
  //     }
  //   } else {
  //     // 帰りがけの処理
  //   }
  // }

}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0); cout << fixed << setprecision(20);
  int t = 1; // cin >> t;
  while (t--) solve();
  // while (t--) compare();
}
