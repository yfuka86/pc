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
  priority_queue<LP, vector<LP>, greater<LP>> que; vector<ll> costs(G.size(), LINF); costs[start] = 0; que.push({0, start});
  while(!que.empty()) {
    auto [c, v] = que.top(); que.pop(); if (costs[v] < c) continue;
    for(auto &to: G[v]) { ll nc = costs[v] + to.cost; if (chmin(costs[to], nc)) que.push({nc, to}); } }
  return costs; }
vector<vl> floyd_warshall(Graph<ll> &G) {
  ll n = G.size(); vector<vl> costs(n, vl(n ,LINF)); rep(i, n) { costs[i][i] = 0; for(Edge e: G[i]) costs[i][e.to] = e.cost; }
  rep(k, n) rep(i, n) rep(j, n) { if (costs[i][k] == LINF || costs[k][j] == LINF) continue; costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]); }
  return costs; }
vl topo_sort(Graph<ll> G) {
  ll n = G.size(); vl deg(n), ret; priority_queue<ll, vl, greater<ll>> que;
  rep(i, n) for (Edge e: G[i]) deg[e.to]++; rep(i, n) if (deg[i] == 0) que.push(i);
  while (!que.empty()) { ll v = que.top(); que.pop(); ret.pb(v);
    for(ll next: G[v]) { deg[next]--; if (deg[next] == 0) que.push(next); } G[v].clear(); }
  if (accumulate(all(deg), 0LL) != 0) return {}; else return ret; }
pair<ll, LP> diameter(Graph<ll> &G) {
  LP deepest = mp(0, 0); function<void(ll, ll, ll)> dfs = [&](ll v, ll p, ll d) { chmax(deepest, mp(d, v)); for (auto to: G[v]) if (to != p) dfs(to, v, d + to.cost); };
  dfs(0, -1, 0); ll s = deepest.second; deepest = mp(0, 0); dfs(s, -1, 0);
  return mp(deepest.first, mp(s, deepest.second)); }

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
