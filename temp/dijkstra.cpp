struct Edge {
  ll to, cost;
  bool operator<(const struct Edge& other) const
  {
    return cost < other.cost;
  }
};

vector<vector<Edge>> G;


vector<ll> dijkstra(ll start) {
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

vector<vector<Edge>> graph_input(int n, int m) {
  vector<vector<Edge>> G(n);
  rep(i, m) {
    int a, b, e;
    cin >> a >> b >> e;
    a--; b--;
    G[a].push_back(Edge{b, e});
    G[b].push_back(Edge{a, e});
  }
  return G;
}
