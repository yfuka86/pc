struct Edge {
  ll to, cost;
  bool operator<(const struct Edge& other) const {
    return cost < other.cost; }
};

vector<ll> dijkstra(vector<vector<Edge>>& G, ll start) {
  priority_queue<LP, vector<LP>, greater<LP>> PQ; vector<ll> costs(G.size(), LINF);

  PQ.push(make_pair(0, start));
  while(!PQ.empty()) {
    LP p = PQ.top(); PQ.pop(); ll prev_cost = p.first; ll v = p.second;
    if (costs[v] <= prev_cost) continue;
    costs[v] = prev_cost;

    rep(i, G[v].size()) {
      Edge e = G[v][i]; ll next_cost = costs[v] + e.cost;
      if (costs[e.to] > next_cost) PQ.push(make_pair(next_cost, e.to));
    }
  }
  return costs;
}

  // ll N, M;
  // cin >> N >> M;
  // vector<vector<Edge>> G(N);
  // rep(i, M) {
  //   ll a, b, c; cin >> a >> b >> c; a--; b--;
  //   G[a].pb({b, c});
  //   G[b].pb({a, c});
  // }

// 重みなしグラフにおけるオイラーツアーとLCA doublingの合わせ↓
// TODO sparse table(RMQ)
//------------------------------------------------------------------------------
vector<vl> G, par; vl fs, ls, depth; ll cur = 0;
void dfs(ll v, ll p, ll d) {
  if (depth[v] != -1) return; // Already found
  if (p != -1) { par[v].pb(p); while (true) { vl &grand_par = par[par[v].back()]; ll parsize = par[v].size() - 1; if ((ll)grand_par.size() > parsize) { par[v].pb(grand_par[parsize]); } else break; } } // LCA doubling

  depth[v] = d; fs[v] = cur++;
  for(ll next: G[v]) {
    dfs(next, v, d + 1);
    cur++;
  }
  ls[v] = cur - 1;
};
void dfs_init(ll n) {
  par.resize(n); fs.resize(n); ls.resize(n); depth.resize(n); depth.assign(n, -1); cur = 0;
  dfs(0, -1, 0); cur = 0;
}

ll lca(ll n1, ll n2) {
  if (depth[n1] < depth[n2]) swap(n1, n2); while (depth[n1] != depth[n2]) n1 = par[n1][floor_pow2(depth[n1] - depth[n2])]; assert(depth[n1] == depth[n2]);
  if (n1 == n2) return n1; if (par[n1][0] == par[n2][0]) return par[n1][0]; rep(c, par[n1].size()) if (par[n1][c] == par[n2][c]) return lca(par[n1][c - 1], par[n2][c - 1]); return lca(par[n1].back(), par[n2].back()); // trace back to the different parents
}

ll dist(ll n1, ll n2) return depth[n1] + depth[n2] - 2 * depth[lca(n1, n2)];
//------------------------------------------------------------------------------
