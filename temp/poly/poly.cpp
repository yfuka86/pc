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
  if (a == 0) { f.erase(f.begin()); f.pb(0); rep(i, f.size()) f[i] /= b; }
  else {
    rep(i, f.size()) {
      f[i] /= a;
      if (i + n < f.size()) f[i + n] -= f[i] * b;
    }
  }
};

// 負の二項定理
// (1 - f) ^ -k の級数のf^n次の係数までを求める
vmi negative_comb(ll n, ll k) {
  vmi ret(n + 1); rep(i, n + 1) ret[i] = comb(i + k - 1, k - 1);
  return ret;
}
