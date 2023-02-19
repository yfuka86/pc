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
#define _overload5(a, b, c, d, e, name, ...) name
#define _overload4(a, b, c, d, name, ...) name
#define _overload3(a, b, c, name, ...) name
#define _rep0(n) for(ll i = 0; i < (ll)(n); ++i)
#define _rep1(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define _rep2(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define _rep3(i, a, b, c) for(ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1, _rep0)(__VA_ARGS__)
#define _per0(n) for(ll i = 0; i < (ll)(n); ++i)
#define _per1(i, n) for(ll i = (ll)(n)-1; i >= 0; --i)
#define _per2(i, a, b) for(ll i = (ll)(b)-1; i >= (ll)(a); --i)
#define _per3(i, a, b, c) for(ll i = (ll)(b)-1; i >= (ll)(a); i -= (ll)(c))
#define rep_r(...) _overload4(__VA_ARGS__, _per3, _per2, _per1, _per0)(__VA_ARGS__)
#define _fore0(a) rep(a.size())
#define _fore1(i, a) for(auto &&i : a)
#define _fore2(a, b, v) for(auto &&[a, b] : v)
#define _fore3(a, b, c, v) for(auto &&[a, b, c] : v)
#define _fore4(a, b, c, d, v) for(auto &&[a, b, c, d] : v)
#define fore(...) _overload5(__VA_ARGS__, _fore4, _fore3, _fore2, _fore1, _fore0)(__VA_ARGS__)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rng_of(v, l, r) (v).begin() + l, (v).begin() + r
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define v3(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define v4(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
template<class T, class U> bool chmin(T &a, const U &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T, class U> bool chmax(T &a, const U &b) { if (b > a) { a = b; return 1;} return 0; }

template< typename T = ll > struct Edge {
  int from, to; T cost; int idx; Edge() = default; Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; } bool operator<(const struct Edge& other) const { return cost < other.cost; } };
template< typename T = ll > struct Graph {
  vector< vector< Edge< T > > > g; int es; Graph() = default; explicit Graph(int n) : g(n), es(0) {}
  size_t size() const { return g.size(); }
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }
  void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };
vector<ll> bfs(Graph<ll> &G, ll start) {
  queue<ll> que; vl cost(G.size(), LINF);
  cost[start] = 0; que.push(start);
  while(!que.empty()) {
    auto v = que.front(); que.pop();
    // costは1でないといけない
    for(auto &to: G[v]) { if (chmin(cost[to], cost[v] + to.cost)) que.push(to); }
  }
  return cost;
}

template< typename T = ll >
pair<vi, vector<Edge<T>>> bridges(Graph<T> &G) {
  int n = G.size(); vector<int> used(n), ord(n), low(n), articulation; vector<Edge<T>> bridge;
  function<int(int, int, int)> dfs = [&](int idx, int k, int par) {
    used[idx] = true; ord[idx] = k++; low[idx] = ord[idx];
    bool is_articulation = false, beet = false; int cnt = 0;
    for(auto &to : G[idx]) {
      if(to == par && !exchange(beet, true)) continue;
      if(!used[to]) {
        ++cnt; k = dfs(to, k, idx); low[idx] = min(low[idx], low[to]);
        is_articulation |= par >= 0 && low[to] >= ord[idx];
        if(ord[idx] < low[to]) bridge.emplace_back(to);
      } else low[idx] = min(low[idx], ord[to]);
    }
    is_articulation |= par == -1 && cnt > 1; if (is_articulation) articulation.push_back(idx);
    return k;
  };
  int k = 0; for(int i = 0; i < n; i++) if(!used[i]) k = dfs(i, k, -1);
  return mp(articulation, bridge);
}

class Solution {
public:
  bool isPossibleToCutPath(vector<vector<int>>& grid) {
    ll n = grid.size(), m = grid[0].size();
    Graph<ll> G(n * m);
    rep(i, n) rep(j, m) {
      if (i < n - 1 && grid[i][j] && grid[i + 1][j]) G.add_edge(i * m + j, (i + 1) * m + j);
      if (j < m - 1 && grid[i][j] && grid[i][j + 1]) G.add_edge(i * m + j, i * m + j + 1);
    }
    if (bfs(G, 0)[n * m - 1] == LINF) return true;

    auto [a, b] = bridges(G);
    set<ll> arts; fore(v, a) arts.insert(v);

    vb art(n * m);

    set<ll> route;
    vb vis(n * m);
    function<void(ll)> dfs = [&](ll v) {
      vis[v] = 1;

      if (arts.find(v) != arts.end() && v != 0 && v != n * m - 1) {
        bool has0 = route.find(0) != route.end();
        bool hasnm = route.find(n * m - 1) != route.end();
        if (!(has0 && hasnm)) art[v] = 1;
      }

      route.insert(v);
      fore(to, G[v]) {
        if (!vis[to]) dfs(to);
      }
      route.erase(v);
    };
    dfs(0);
    vb art0 = art;
    vis.assign(n * m, 0); art.assign(n * m, 0);
    dfs(n * m - 1);

    vl artf;
    fore(v, arts) if (art0[v] && art[v]) artf.pb(v);
    if (artf.size()) return true; else return false;
  }
};
