// fにa + b * x^nを掛ける
template<typename T>
auto mul_simple(T &f, mint a, mint b, int n){
  rep_r(i, f.size()) {
    f[i] *= a;
    if (i >= n) f[i] += f[i - n] * b;
  }
};

// fからa + b * x^nを割る
template<typename T>
auto div_simple(T &f, mint a, mint b, int n){
  if (a == 0) { f.erase(f.begin()); f.pb(0); rep(i, f.size()) f[i] /= b; } // TODO: fix(bug)
  else {
    rep(i, f.size()) {
      f[i] /= a;
      if (i + n < f.size()) f[i + n] -= f[i] * b;
    }
  }
};
// 多項式除算 f / g
pair<fps, fps> divmod(const fps &f, const fps &g) {
  int n = f.size(), m = g.size();
  int k = n - m + 1;
  if (k <= 0) return { fps(), f }; // 次数がgの方が大きい場合

  // 商を求める
  fps f2 = fps(f), g2 = fps(g);
  reverse(f2.begin(), f2.end());
  reverse(g2.begin(), g2.end());
  f2.resize(k, 0); g2.resize(k, 0);
  fps q = f2.divide(g2);
  reverse(q.begin(), q.end());
  while (!q.empty() && q.back() == 0) q.pop_back();
  // 余りを求める
  fps r = fps(f);
  fps p = fps(g); p.resize(n, 0); p = p.multiply(q); // 次数nまで求めて引き算（m以上の次数を無視すると少し高速になる）
  r -= p;
  while (!r.empty() && r.back() == 0) r.pop_back();
  return { q, r };
}

// 負の二項定理
// (1 - f) ^ -k の級数のf^n次の係数までを求める
vmi negative_comb(ll n, ll k) {
  vmi ret(n + 1); rep(i, n + 1) ret[i] = comb(i + k - 1, k - 1);
  return ret;
}

