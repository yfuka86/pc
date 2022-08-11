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