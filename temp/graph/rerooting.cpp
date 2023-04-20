// CF1778のE
template <class G, class S, void(*merge)(S&, S&), void(*tmerge)(S&, S&, int, int), void(*upd)(S&, S&, S&), S(*e)()>
struct ReRooting {
  G& g; vector<S>&dp, &dpr;
  ReRooting(G& _g, vector<S> &dp, vector<S> &dpr): g(_g), dp(dp), dpr(dpr) {
    dfs(0, -1);
    dfsr(0, -1, e());
  }

  void dfs(int v, int p) {
    for(auto &&to: g[v]) { if (to == p) continue;
      dfs(to, v);
      tmerge(dp[v], dp[to], to.idx, v);
    }
  }

  void dfsr(int v, int p, S par) {
    ll n = g[v].size();
    vector<S> csum(n, e());
    rep(i, n) {
      if (g[v][i] == p) tmerge(csum[i], par, g[v][i].idx, g[v][i]);
      else tmerge(csum[i], dp[g[v][i]], g[v][i].idx, g[v][i]);
    }
    vector<S> crsum = csum;

    rep(i, n - 1) merge(csum[i + 1], csum[i]);
    rep_r(i, n - 1) merge(crsum[i], crsum[i + 1]);

    // 最後に取りたいDPの値
    upd(dpr[v], csum[n - 1], par);

    rep(i, n) { if (g[v][i] == p) continue;
      S nx = e(); nx.add(a[v]);
      if (i > 0) merge(nx, csum[i - 1]);
      if (i + 1 < n) merge(nx, crsum[i + 1]);
      dfsr(g[v][i], v, nx);
    }
  }
};

using S = xor_basis<ll>;
void merge(S& a, S& b) {
  a.merge(b);
}

void tmerge(S& a, S& b, int ei, int to) {
  a.merge(b);
}

void upd(S& lhs, S &sum, S &par){
  lhs = par;
}

S e() { return S(); }
