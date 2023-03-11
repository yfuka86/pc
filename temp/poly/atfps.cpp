// 入出力マクロの上に
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353; using vmi = vector<mint>; using vvmi = vector<vmi>; using v3mi = vector<vvmi>; using v4mi = vector<v3mi>;
const ll mod = 998244353;
istream& operator>>(istream& in, mint &a) { long long e; in >> e; a = e; return in; }
ostream& operator<<(ostream& out, mint &a) { return out << a.val(); }
template<class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> const_cast<T&>(e); return is; }
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << const_cast<T&>(e) << ' '; return os; }
//------------------------------------------------------------------------------
//https://judge.yosupo.jp/submission/33048
template<class T>
struct FormalPowerSeries : vector<T> {
  using vector<T>::vector;
  using vector<T>::operator=;
  using F = FormalPowerSeries;

  F operator-() const {
    F res(*this);
    for (auto &e : res) e = -e;
    return res;
  }
  F &operator*=(const T &g) {
    for (auto &e : *this) e *= g;
    return *this;
  }
  F &operator/=(const T &g) {
    assert(g != T(0));
    *this *= g.inv();
    return *this;
  }
  F &operator+=(const F &g) {
    int n = this->size(), m = g.size();
    rep(i, min(n, m)) (*this)[i] += g[i];
    return *this;
  }
  F &operator-=(const F &g) {
    int n = this->size(), m = g.size();
    rep(i, min(n, m)) (*this)[i] -= g[i];
    return *this;
  }
  F &operator<<=(const int d) {
    int n = this->size();
    if (d >= n) *this = F(n);
    this->insert(this->begin(), d, 0);
    this->resize(n);
    return *this;
  }
  F &operator>>=(const int d) {
    int n = this->size();
    this->erase(this->begin(), this->begin() + min(n, d));
    this->resize(n);
    return *this;
  }

  // O(n log n)
  F inv(int d = -1) const {
    int n = this->size();
    assert(n != 0 && (*this)[0] != 0);
    if (d == -1) d = n;
    assert(d >= 0);
    F res{(*this)[0].inv()};
    for (int m = 1; m < d; m *= 2) {
      F f(this->begin(), this->begin() + min(n, 2*m));
      F g(res);
      f.resize(2*m), internal::butterfly(f);
      g.resize(2*m), internal::butterfly(g);
      rep(i, 2*m) f[i] *= g[i];
      internal::butterfly_inv(f);
      f.erase(f.begin(), f.begin() + m);
      f.resize(2*m), internal::butterfly(f);
      rep(i, 2*m) f[i] *= g[i];
      internal::butterfly_inv(f);
      T iz = T(2*m).inv(); iz *= -iz;
      rep(i, m) f[i] *= iz;
      res.insert(res.end(), f.begin(), f.begin() + m);
    }
    res.resize(d);
    return res;
  }

  // fast: FMT-friendly modulus only
  // O(n log n)
  F &multiply_inplace(const F &g, int d = -1) {
    int n = this->size();
    if (d == -1) d = n;
    assert(d >= 0);
    *this = convolution(move(*this), g);
    this->resize(d);
    return *this;
  }
  F multiply(const F &g, const int d = -1) const { return F(*this).multiply_inplace(g, d); }
  // O(n log n)
  F &divide_inplace(const F &g, int d = -1) {
    int n = this->size();
    if (d == -1) d = n;
    assert(d >= 0);
    *this = convolution(move(*this), g.inv(d));
    this->resize(d);
    return *this;
  }
  F divide(const F &g, const int d = -1) const { return F(*this).divide_inplace(g, d); }

  // // naive
  // // O(n^2)
  // F &multiply_inplace(const F &g) {
  //   int n = this->size(), m = g.size();
  //   rep_r(i, n) {
  //     (*this)[i] *= g[0];
  //     rep(j, 1, min(i+1, m)) (*this)[i] += (*this)[i-j] * g[j];
  //   }
  //   return *this;
  // }
  // F multiply(const F &g) const { return F(*this).multiply_inplace(g); }
  // // O(n^2)
  // F &divide_inplace(const F &g) {
  //   assert(g[0] != T(0));
  //   T ig0 = g[0].inv();
  //   int n = this->size(), m = g.size();
  //   rep(i, n) {
  //     rep(j, 1, min(i+1, m)) (*this)[i] -= (*this)[i-j] * g[j];
  //     (*this)[i] *= ig0;
  //   }
  //   return *this;
  // }
  // F divide(const F &g) const { return F(*this).divide_inplace(g); }

  // sparse
  // O(nk)
  F &multiply_inplace(vector<pair<int, T>> g) {
    int n = this->size();
    auto [d, c] = g.front();
    if (d == 0) g.erase(g.begin());
    else c = 0;
    rep_r(i, n) {
      (*this)[i] *= c;
      for (auto &[j, b] : g) {
        if (j > i) break;
        (*this)[i] += (*this)[i-j] * b;
      }
    }
    return *this;
  }
  F multiply(const vector<pair<int, T>> &g) const { return F(*this).multiply_inplace(g); }
  // O(nk)
  F &divide_inplace(vector<pair<int, T>> g) {
    int n = this->size();
    auto [d, c] = g.front();
    assert(d == 0 && c != T(0));
    T ic = c.inv();
    g.erase(g.begin());
    rep(i, n) {
      for (auto &[j, b] : g) {
        if (j > i) break;
        (*this)[i] -= (*this)[i-j] * b;
      }
      (*this)[i] *= ic;
    }
    return *this;
  }
  F divide(const vector<pair<int, T>> &g) const { return F(*this).divide_inplace(g); }

  // multiply and divide (1 + cz^d)
  // O(n)
  void multiply_inplace(const int d, const T c) {
    int n = this->size();
    if (c == T(1)) rep_r(i, n-d) (*this)[i+d] += (*this)[i];
    else if (c == T(-1)) rep_r(i, n-d) (*this)[i+d] -= (*this)[i];
    else rep_r(i, n-d) (*this)[i+d] += (*this)[i] * c;
  }
  // O(n)
  void divide_inplace(const int d, const T c) {
    int n = this->size();
    if (c == T(1)) rep(i, n-d) (*this)[i+d] -= (*this)[i];
    else if (c == T(-1)) rep(i, n-d) (*this)[i+d] += (*this)[i];
    else rep(i, n-d) (*this)[i+d] -= (*this)[i] * c;
  }

  // O(n)
  T eval(const T &a) const {
    T x(1), res(0);
    for (auto e : *this) res += e * x, x *= a;
    return res;
  }

  // O(n)
  F &integ_inplace() {
    int n = this->size();
    assert(n > 0);
    if (n == 1) return *this = F{0};
    this->insert(this->begin(), 0);
    this->pop_back();
    vector<T> inv(n);
    inv[1] = 1;
    int p = T::mod();
    rep(i, 2, n) inv[i] = - inv[p%i] * (p/i);
    rep(i, 2, n) (*this)[i] *= inv[i];
    return *this;
  }
  F integ() const { return F(*this).integ_inplace(); }

  // O(n)
  F &deriv_inplace() {
    int n = this->size();
    assert(n > 0);
    rep(i, 2, n) (*this)[i] *= i;
    this->erase(this->begin());
    this->push_back(0);
    return *this;
  }
  F deriv() const { return F(*this).deriv_inplace(); }

  // O(n log n)
  F &log_inplace(int d = -1) {
    int n = this->size();
    assert(n > 0 && (*this)[0] == 1);
    if (d == -1) d = n;
    assert(d >= 0);
    if (d < n) this->resize(d);
    F f_inv = this->inv();
    this->deriv_inplace();
    this->multiply_inplace(f_inv);
    this->integ_inplace();
    return *this;
  }
  F log(const int d = -1) const { return F(*this).log_inplace(d); }

  // O(n log n)
  // https://arxiv.org/abs/1301.5804 (Figure 1, right)
  F &exp_inplace(int d = -1) {
    int n = this->size();
    assert(n > 0 && (*this)[0] == 0);
    if (d == -1) d = n;
    assert(d >= 0);
    F g{1}, g_fft{1, 1};
    (*this)[0] = 1;
    this->resize(d);
    F h_drv(this->deriv());
    for (int m = 2; m < d; m *= 2) {
      // prepare
      F f_fft(this->begin(), this->begin() + m);
      f_fft.resize(2*m), internal::butterfly(f_fft);

      // Step 2.a'
      {
        F f(m);
        rep(i, m) f[i] = f_fft[i] * g_fft[i];
        internal::butterfly_inv(f);
        f.erase(f.begin(), f.begin() + m/2);
        f.resize(m), internal::butterfly(f);
        rep(i, m) f[i] *= g_fft[i];
        internal::butterfly_inv(f);
        f.resize(m/2);
        f /= T(-m) * m;
        g.insert(g.end(), f.begin(), f.begin() + m/2);
      }

      // Step 2.b'--d'
      F t(this->begin(), this->begin() + m);
      t.deriv_inplace();
      {
        // Step 2.b'
        F r{h_drv.begin(), h_drv.begin() + m-1};
        // Step 2.c'
        r.resize(m); internal::butterfly(r);
        rep(i, m) r[i] *= f_fft[i];
        internal::butterfly_inv(r);
        r /= -m;
        // Step 2.d'
        t += r;
        t.insert(t.begin(), t.back()); t.pop_back();
      }

      // Step 2.e'
      if (2*m < d) {
        t.resize(2*m); internal::butterfly(t);
        g_fft = g; g_fft.resize(2*m); internal::butterfly(g_fft);
        rep(i, 2*m) t[i] *= g_fft[i];
        internal::butterfly_inv(t);
        t.resize(m);
        t /= 2*m;
      }
      else { // この場合分けをしても数パーセントしか速くならない
        F g1(g.begin() + m/2, g.end());
        F s1(t.begin() + m/2, t.end());
        t.resize(m/2);
        g1.resize(m), internal::butterfly(g1);
        t.resize(m),  internal::butterfly(t);
        s1.resize(m), internal::butterfly(s1);
        rep(i, m) s1[i] = g_fft[i] * s1[i] + g1[i] * t[i];
        rep(i, m) t[i] *= g_fft[i];
        internal::butterfly_inv(t);
        internal::butterfly_inv(s1);
        rep(i, m/2) t[i+m/2] += s1[i];
        t /= m;
      }

      // Step 2.f'
      F v(this->begin() + m, this->begin() + min<int>(d, 2*m)); v.resize(m);
      t.insert(t.begin(), m-1, 0); t.push_back(0);
      t.integ_inplace();
      rep(i, m) v[i] -= t[m+i];

      // Step 2.g'
      v.resize(2*m); internal::butterfly(v);
      rep(i, 2*m) v[i] *= f_fft[i];
      internal::butterfly_inv(v);
      v.resize(m);
      v /= 2*m;

      // Step 2.h'
      rep(i, min(d-m, m)) (*this)[m+i] = v[i];
    }
    return *this;
  }
  F exp(const int d = -1) const { return F(*this).exp_inplace(d); }

  // O(n log n)
  F &pow_inplace(ll k, int d = -1) {
    int n = this->size();
    if (d == -1) d = n;
    assert(d >= 0 && k >= 0);
    if (k == 0) {
      *this = F(d);
      if (d > 0) (*this)[0] = 1;
      return *this;
    }
    int l = 0;
    while (l < n && (*this)[l] == 0) ++l;
    if (l > (d-1)/k) return *this = F(d);
    T c = (*this)[l];
    this->erase(this->begin(), this->begin() + l);
    *this /= c;
    this->log_inplace(d - l*k);
    *this *= k;
    this->exp_inplace();
    *this *= c.pow(k);
    this->insert(this->begin(), l*k, 0);
    this->resize(d);
    return *this;
  }
  F pow(const ll k, const int d = -1) const { return F(*this).pow_inplace(k, d); }

  F operator*(const T &g) const { return F(*this) *= g; }
  F operator/(const T &g) const { return F(*this) /= g; }
  F operator+(const F &g) const { return F(*this) += g; }
  F operator-(const F &g) const { return F(*this) -= g; }
  F operator<<(const int d) const { return F(*this) <<= d; }
  F operator>>(const int d) const { return F(*this) >>= d; }
};

using fps = FormalPowerSeries<mint>;
