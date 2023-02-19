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

using BS = bitset<64>;

class Solution {
public:
  bool isPossibleToCutPath(vector<vector<int>>& grid) {
    ll n = grid.size(), m = grid[0].size();
    Graph<ll> G(n * m), rG(n * m);
    rep(i, n) rep(j, m) {
      if (i < n - 1 && grid[i][j] && grid[i + 1][j]) {
        G.add_directed_edge(i * m + j, (i + 1) * m + j);
        rG.add_directed_edge((i + 1) * m + j, i * m + j);
      }
      if (j < m - 1 && grid[i][j] && grid[i][j + 1]) {
        G.add_directed_edge(i * m + j, i * m + j + 1);
        rG.add_directed_edge(i * m + j + 1, i * m + j);
      }
    }
    if (bfs(G, 0)[n * m - 1] == LINF) return true;

    vl test;
    rep(i, n) rep(j, m) {
      if (i == 0 && j == 0) continue;
      if (i == n - 1 && j == m - 1) continue;
      if (grid[i][j]) test.pb(i * m + j);
    }

    vl mp(n * m, -1);
    BS all1; all1.flip();
    vb vis(n * m);
    vector<BS> dp(n * m);
    while (test.size()) {
      rep(i, n * m) dp[i].reset();
      dp[n * m - 1] = all1;
      vl t; while (test.size() && t.size() < 64) { t.pb(test.back()); test.pop_back(); }
      rep(i, t.size()) mp[t[i]] = i;

      queue<ll> que; que.push(n * m - 1);
      while (!que.empty()) {
        ll v = que.front(); que.pop();
        fore(from, rG[v]) {
          dp[from] |= dp[v];
          if (mp[from] != -1) dp[from].reset(mp[from]);
          if (!vis[from]) { que.push(from); vis[from] = 1; }
        }
      }

      rep(i, n * m) vis[i] = 0;
      rep(i, t.size()) mp[t[i]] = -1;
      if (dp[0].count() < 64) return true;
    }
    return false;
  }
};
