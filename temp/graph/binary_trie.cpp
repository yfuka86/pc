vvl build_btrie(vl &a, ll maxb = 30) {
  ll n = a.size();
  vvl ret; ret.emplace_back({-1, -1});
  rep(i, n) {
    ll cur = 0;
    rep_r(b, maxb) {
      ll nx = (a[i] & 1 << b) ? 1 : 0;
      if (trie[cur][nx] == -1) { trie[cur][nx] = trie.size(); trie.emplace_back({-1, -1}); }
      cur = trie[cur][nx];
    }
  }
  return ret;
}
