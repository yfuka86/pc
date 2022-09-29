Graph<ll> build_aux_tree(HeavyLightDecomposition<Graph<ll>> &hld, vl& vs) {
  vlp v;
  for(auto &vv: vs) v.pb({hld.down[vv], vv});
  sort(all(v));

  ll sz = v.size();
  rep(i, sz) {
    ll lca = hld.lca(v[i].second, v[(i + 1) % sz].second);
    v.pb({hld.down[lca], lca});
  }
  sort(all(v)); v.erase(unique(all(v)), v.end());

  Graph<ll> G(hld.g.size()); stack<ll> st;
  st.push(v[0].second);
  rep(i, 1, v.size()) {
    auto [_, next] = v[i];
    while (hld.up[st.top()] < hld.up[next]) st.pop();
    G.add_edge(st.top(), next);
    st.push(next);
  }
  return G;
}
