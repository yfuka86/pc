// ベルマンフォード法 : O(NM)
//   - (dist, cycle) のペアを返す
//   - 負閉路が存在しない場合，cycle はサイズ 0
//   - 負閉路が存在する場合，cycle は負閉路に含まれる頂点配列
//   - 負閉路が複数あれば頂点が混ざり合うことに注意
//   - 負閉路を一つだけ見つけたい場合は "find_negative_cycle.cpp" を使う
pair<vl, vl> bellman_ford(const Graph<ll>& G, int s) {
  int n = G.size(); assert(0 <= s && s < n);
  vl dist(n, LINF); dist[s] = 0;
  vl cycle;  // 負閉路に含まれる頂点配列
  for (int i = 0; i < n; i++) {
    for (int u = 0; u < n; u++) if (dist[u] != INF) {
      for (const auto& v : G[u]) {
        if (chmin(dist[v], dist[u] + v.cost)) {
          if (i == n-1) cycle.push_back(v);
        }
      }
    }
  }
  return make_pair(dist, cycle);
}
