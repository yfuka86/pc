// 集合sの部分集合で和がT以下になるものの個数を1,2,,,Tについて全て求める
template<class T> fps subset_sum(vector<T> s, ll t) {
  ll n = s.size(); vl cnt(t + 1); rep(i, n) if (s[i] <= t) cnt[s[i]]++;
  // sの各要素は1以上
  fps log(t + 1);
  rep(k, 1, t + 1) { if (!cnt[k]) continue;
    ll c = cnt[k];
    rep(i, k, t + 1, k) { // テイラー展開したlog(1 + x^k)をt以下の次数について足していく
      ll sgn = i / k & 1 ? 1 : -1;
      log[i] += mint(c) * sgn / (i / k);
    }
  }
  return log.exp();
}
