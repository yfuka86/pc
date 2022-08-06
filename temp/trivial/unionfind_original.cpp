struct UnionFind {
  vector<ll> par, s, e;
  UnionFind(ll N) : par(N), s(N), e(N) {
    rep(i,N) {
      par[i] = i;
      s[i] = 1;
      e[i] = 0;
    }
  }
  ll root(ll x) {
    return par[x]==x ? x : par[x] = root(par[x]);
  }
  ll size(ll x) {
    return par[x]==x ? s[x] : s[x] = size(root(x));
  }
  ll edge(ll x) {
    return par[x]==x ? e[x] : e[x] = edge(root(x));
  }
  void unite(ll x, ll y) {
    ll rx=root(x), ry=root(y);
    if (size(rx)<size(ry)) swap(rx,ry);
    if (rx!=ry) {
      s[rx] += s[ry];
      par[ry] = rx;
      e[rx] += e[ry]+1;
    } else e[rx]++;
  }
  bool same(ll x, ll y) {
    ll rx=root(x), ry=root(y);
    return rx==ry;
  }
};
