
struct Interpolation {
  int n; vmi a;
  Interpolation() {}
  Interpolation(const vmi& p) {
    // 階乗の逆元求める
    n = p.size(); a.resize(n);
    vmi invf(n, 1); mint f = 1;
    rep2_r(i, 1, n) f *= i;
    invf[n - 1] = mint(1) / f;
    rep2_r(i, 1, n) invf[i - 1] = invf[i] * i;
    // 本体
    rep(i, n) {
      mint b = invf[i] * invf[n-1-i];
      a[i] = p[i] * ((n-1-i)&1 ? -b : b);
    }
  }
  mint operator()(mint x) const {
    vmi r(n, 1);
    rep2_r(i, 1, n) r[i - 1] = r[i] * (x-i);
    mint l = 1, res;
    rep(i, n) {
      res += a[i] * l * r[i];
      l *= x-i;
    }
    return res;
  }
};
