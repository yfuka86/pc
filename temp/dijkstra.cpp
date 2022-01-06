struct Edge {
  ll to, cost;
  bool operator<(const struct Edge& other) const {
    return cost < other.cost; }
};

vector<ll> dijkstra(vector<vector<Edge>>& G, ll start) {
  priority_queue<LP> PQ;
  vector<ll> costs(G.size(), LINF);

  PQ.push(make_pair(0, start));

  while(!PQ.empty()) {
    LP p = PQ.top(); PQ.pop();
    ll prev_cost = -p.first;
    ll v = p.second;
    if(costs[v] <= prev_cost) continue;
    costs[v] = prev_cost;

    rep(i, G[v].size()) {
      Edge e = G[v][i];
      ll next_cost = costs[v] + e.cost;
      if (costs[e.to] > next_cost) {
        PQ.push(make_pair(-next_cost, e.to));
      }
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
