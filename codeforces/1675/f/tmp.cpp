raph<ll> aG(n);
  // stack<ll> st;
  // st.push(v[0].second);
  // rep2(i, 1, v.size()) {
  //   auto [_, next] = v[i];
  //   while (hld.up[st.top()] < hld.up[next]) {
  //     st.pop();
  //     assert(st.size());
  //   }
  //   aG.add_edge(st.top(), next);
  //   st.push(next);
  // }

  // vl dp(n, 0);
  // function<void(ll, ll)> dfs = [&](ll v, ll p) {
  //   for (auto to: aG[v]) {
  //     if (to == p) continue;
  //     dp[v] += hld.dist(v, to) * 2;
  //     dfs(to, v);
  //     dp[v] += dp[to];
  //   }
  // };

  // dfs(x, -1);
  // c