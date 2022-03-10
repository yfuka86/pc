// 重みなしグラフにおけるオイラーツアーとLCA doublingの合わせ
// TODO sparse table(RMQ)
//for tree only----------------------------------------------------------------
vector<vl> G, par; vl fs, ls, depth;
void dfs(ll v, ll p, ll d, ll &cur) {
  if (depth[v] != -1) return; // Already found
  if (p != -1) { par[v].pb(p); while (true) { vl &grand_par = par[par[v].back()]; ll parsize = par[v].size() - 1; if ((ll)grand_par.size() > parsize) { par[v].pb(grand_par[parsize]); } else break; } } // LCA doubling

  depth[v] = d; fs[v] = cur++;
  for(ll next: G[v]) {
    if (next == p) continue;
    dfs(next, v, d + 1, cur);
    cur++;
  }
  ls[v] = cur - 1;
};
void dfs_init(ll n) { par.resize(n); fs.resize(n, 0); ls.resize(n, 0); depth.resize(n, 0); depth.assign(n, -1); ll cur = 0; dfs(0, -1, 0, cur); }
ll lca(ll v1, ll v2) {
  if (depth[v1] < depth[v2]) swap(v1, v2); while (depth[v1] != depth[v2]) v1 = par[v1][floor_pow2(depth[v1] - depth[v2])]; assert(depth[v1] == depth[v2]);
  if (v1 == v2) return v1; if (par[v1][0] == par[v2][0]) return par[v1][0]; rep(c, par[v1].size()) if (par[v1][c] == par[v2][c]) return lca(par[v1][c - 1], par[v2][c - 1]); return lca(par[v1].back(), par[v2].back()); // trace back to the different parents
}
ll dist(ll v1, ll v2) { return depth[v1] + depth[v2] - 2 * depth[lca(v1, v2)]; }
ll edges_of_part(ll v) { return (ls[v] - fs[v]) / 2; }
//------------------------------------------------------------------------------



template< typename T = ll >
struct EulerTour : Graph< T > {
public:
  using Graph< T >::Graph; using Graph< T >::g; vector< int > in, out, dep, par, node, edge;
  void build() {
    ll n = g.size(); in.assign(n, 0); out.assign(n, 0); dep.assign(n, -1); par.assign(n, 0); node.assign(n * 2 - 1, 0); edge.assign(n * 2 - 1, 0);
    int t = 0; dfs(0, -1, 0, t); }
  /* k: 0-indexed */
  int lca(int u, int v) const { for(;; v = par[head[v]]) { if(in[u] > in[v]) swap(u, v); if(head[u] == head[v]) return u; } }
  int dist(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

  explicit HeavyLightDecomposition(const Graph< T > &g) : Graph< T >(g) {}
private:
  void dfs(int v, int p, int d, int &cur) {
    dep[v] = d; par[idx] = p; fs[v] = cur++;
    for(auto &to : g[v]) {
      if(to == p) continue;
      dfs(to, v, d + 1);
      cur++;
    }
    ls[v] = cur - 1;
  }
};
