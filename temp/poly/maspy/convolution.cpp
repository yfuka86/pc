const ll mod = 998244353;
//------------------------------------------------------------------------------
template< int mod > struct ModInt {
  int x; ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }  ModInt &operator-=(const ModInt &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  ModInt &operator*=(const ModInt &p) { x = (int) (1LL * x * p.x % mod); return *this; }  ModInt &operator/=(const ModInt &p) { *this *= p.inv(); return *this; }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inv() const { int a = x, b = mod, u = 1, v = 0, t; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } return ModInt(u); }
  ModInt pow(int64_t n) const { ModInt ret(1), mul(x); while(n > 0) { if(n & 1) ret *= mul; mul *= mul; n >>= 1; } return ret; }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
  static constexpr int get_mod() { return mod; }
};
using mint = ModInt< mod >; using vmi = vector<mint>; using vvmi = vector<vmi>; using v3mi = vector<vvmi>; using v4mi = vector<v3mi>;
//------------------------------------------------------------------------------
const int max_n = (1 << 20) + 1;
mint fact[max_n], factinv[max_n];
void init_f() { fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); } factinv[max_n - 1] = mint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
mint comb(int a, int b) { assert(fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
mint combP(int a, int b) { assert(fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, ll p = mod) { ll ret = 1; x %= p; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
ll mod_inv(ll x, ll m) { ll a = x, b = m, u = 1, v = 0, t; while(b) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } if (u < 0) u += m; return u % m; }
//------------------------------------------------------------------------------

using modint107 = ModInt<1'000'000'007>;
using modint998 = ModInt<998'244'353>;

template <class T>
vector<T> convolution_naive(const vector<T>& a, const vector<T>& b) {
  int n = int(a.size()), m = int(b.size());
  vector<T> ans(n + m - 1);
  if (n < m) {
    rep(j, m) rep(i, n) ans[i + j] += a[i] * b[j];
  } else {
    rep(i, n) rep(j, m) ans[i + j] += a[i] * b[j];
  }
  return ans;
}

template <class mint>
struct fft_info {
  static constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
  }

  static constexpr int rank2 = bsf_constexpr(mint::get_mod() - 1);
  array<mint, rank2 + 1> root;
  array<mint, rank2 + 1> iroot;
  array<mint, max(0, rank2 - 1)> rate2;
  array<mint, max(0, rank2 - 1)> irate2;
  array<mint, max(0, rank2 - 2)> rate3;
  array<mint, max(0, rank2 - 2)> irate3;

  fft_info() {
    int g = primitive_root(mint::get_mod());
    root[rank2] = mint(g).pow((mint::get_mod() - 1) >> rank2);
    iroot[rank2] = mint(1) / root[rank2];
    rep_r(i, rank2) {
      root[i] = root[i + 1] * root[i + 1];
      iroot[i] = iroot[i + 1] * iroot[i + 1];
    }

    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 2; i++) {
        rate2[i] = root[i + 2] * prod;
        irate2[i] = iroot[i + 2] * iprod;
        prod *= iroot[i + 2];
        iprod *= root[i + 2];
      }
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 3; i++) {
        rate3[i] = root[i + 3] * prod;
        irate3[i] = iroot[i + 3] * iprod;
        prod *= iroot[i + 3];
        iprod *= root[i + 3];
      }
    }
  }

  constexpr int primitive_root(int m) {
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 880803841) return 26;
    if (m == 998244353) return 3;
  }
};

template <class mint>
void ntt(vector<mint>& a, bool inverse) {
  int n = int(a.size());
  int h = topbit(n);
  assert(n == 1 << h);
  static const fft_info<mint> info;
  if (!inverse) {
    int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed

    while (len < h) {
      if (h - len == 1) {
        int p = 1 << (h - len - 1);
        mint rot = 1;
        rep(s, 1 << len) {
          int offset = s << (h - len);
          rep(i, p) {
            auto l = a[i + offset];
            auto r = a[i + offset + p] * rot;
            a[i + offset] = l + r;
            a[i + offset + p] = l - r;
          }
          rot *= info.rate2[topbit(~s & -~s)];
        }
        len++;
      } else {
        int p = 1 << (h - len - 2);
        mint rot = 1, imag = info.root[2];
        for (int s = 0; s < (1 << len); s++) {
          mint rot2 = rot * rot;
          mint rot3 = rot2 * rot;
          int offset = s << (h - len);
          for (int i = 0; i < p; i++) {
            auto mod2 = 1ULL * mint::get_mod() * mint::get_mod();
            auto a0 = 1ULL * a[i + offset].x;
            auto a1 = 1ULL * a[i + offset + p].x * rot.x;
            auto a2 = 1ULL * a[i + offset + 2 * p].x * rot2.x;
            auto a3 = 1ULL * a[i + offset + 3 * p].x * rot3.x;
            auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).x * imag.x;
            auto na2 = mod2 - a2;
            a[i + offset] = a0 + a2 + a1 + a3;
            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
          }
          rot *= info.rate3[topbit(~s & -~s)];
        }
        len += 2;
      }
    }
  } else {
    mint coef = mint(1) / mint(len(a));
    rep(i, len(a)) a[i] *= coef;
    int len = h;
    while (len) {
      if (len == 1) {
        int p = 1 << (h - len);
        mint irot = 1;
        rep(s, 1 << (len - 1)) {
          int offset = s << (h - len + 1);
          rep(i, p) {
            auto l = a[i + offset];
            auto r = a[i + offset + p];
            a[i + offset] = l + r;
            a[i + offset + p]
                = (unsigned long long)(mint::get_mod() + l.x - r.x)
                  * irot.x;
            ;
          }
          irot *= info.irate2[topbit(~s & -~s)];
        }
        len--;
      } else {
        int p = 1 << (h - len);
        mint irot = 1, iimag = info.iroot[2];
        rep(s, (1 << (len - 2))) {
          mint irot2 = irot * irot;
          mint irot3 = irot2 * irot;
          int offset = s << (h - len + 2);
          for (int i = 0; i < p; i++) {
            auto a0 = 1ULL * a[i + offset + 0 * p].x;
            auto a1 = 1ULL * a[i + offset + 1 * p].x;
            auto a2 = 1ULL * a[i + offset + 2 * p].x;
            auto a3 = 1ULL * a[i + offset + 3 * p].x;

            auto a2na3iimag
                = 1ULL * mint((mint::get_mod() + a2 - a3) * iimag.x).x;

            a[i + offset] = a0 + a1 + a2 + a3;
            a[i + offset + 1 * p]
                = (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.x;
            a[i + offset + 2 * p]
                = (a0 + a1 + (mint::get_mod() - a2) + (mint::get_mod() - a3))
                  * irot2.x;
            a[i + offset + 3 * p]
                = (a0 + (mint::get_mod() - a1) + (mint::get_mod() - a2na3iimag))
                  * irot3.x;
          }
          irot *= info.irate3[topbit(~s & -~s)];
        }
        len -= 2;
      }
    }
  }
}

template <class mint>
vector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {
  int n = int(a.size()), m = int(b.size());
  int sz = 1;
  while (sz < n + m - 1) sz *= 2;
  a.resize(sz), b.resize(sz);
  bool same = a == b;
  ntt(a, 0);
  if(same){
    b = a;
  } else {
    ntt(b, 0);
  }
  rep(i, sz) a[i] *= b[i];
  ntt(a, 1);
  a.resize(n + m - 1);
  return a;
}

template <typename mint>
vector<mint> convolution_garner(const vector<mint>& a, const vector<mint>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  static const long long nttprimes[] = {754974721, 167772161, 469762049};
  using mint0 = ModInt<754974721>;
  using mint1 = ModInt<167772161>;
  using mint2 = ModInt<469762049>;
  vector<mint0> a0(n), b0(m);
  vector<mint1> a1(n), b1(m);
  vector<mint2> a2(n), b2(m);
  rep(i, n) a0[i] = a[i].x, a1[i] = a[i].x, a2[i] = a[i].x;
  rep(i, m) b0[i] = b[i].x, b1[i] = b[i].x, b2[i] = b[i].x;
  auto c0 = convolution_ntt<mint0>(a0, b0);
  auto c1 = convolution_ntt<mint1>(a1, b1);
  auto c2 = convolution_ntt<mint2>(a2, b2);
  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];
  static const long long m0_inv_m1 = mint1(nttprimes[0]).inv().x;
  static const long long m01_inv_m2 = mint2(m01).inv().x;
  static const int mod = mint::get_mod();
  auto garner = [&](mint0 x0, mint1 x1, mint2 x2) -> mint {
    int r0 = x0.x, r1 = x1.x, r2 = x2.x;
    int v1 = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];
    auto v2 = (mint2(r2) - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);
    return mint(r0 + 1LL * nttprimes[0] * v1 + m01 % mod * v2.x);
  };
  vector<mint> c(len(c0));
  rep(i, len(c)) c[i] = garner(c0[i], c1[i], c2[i]);
  return c;
}

namespace CFFT {
using real = double;

struct C {
  real x, y;

  C() : x(0), y(0) {}

  C(real x, real y) : x(x), y(y) {}
  inline C operator+(const C& c) const { return C(x + c.x, y + c.y); }
  inline C operator-(const C& c) const { return C(x - c.x, y - c.y); }
  inline C operator*(const C& c) const {
    return C(x * c.x - y * c.y, x * c.y + y * c.x);
  }

  inline C conj() const { return C(x, -y); }
};

const real PI = acosl(-1);
int base = 1;
vector<C> rts = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

void ensure_base(int nbase) {
  if (nbase <= base) return;
  rev.resize(1 << nbase);
  rts.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++) {
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  }
  while (base < nbase) {
    real angle = PI * 2.0 / (1 << (base + 1));
    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      rts[i << 1] = rts[i];
      real angle_i = angle * (2 * i + 1 - (1 << base));
      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
    }
    ++base;
  }
}

void fft(vector<C>& a, int n) {
  assert((n & (n - 1)) == 0);
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; i++) {
    if (i < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }
  }
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        C z = a[i + j + k] * rts[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}

template <typename R>
vector<double> convolution_fft(const vector<R>& a, const vector<R>& b) {
  int need = (int)a.size() + (int)b.size() - 1;
  int nbase = 1;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  vector<C> fa(sz);
  for (int i = 0; i < sz; i++) {
    int x = (i < (int)a.size() ? a[i] : 0);
    int y = (i < (int)b.size() ? b[i] : 0);
    fa[i] = C(x, y);
  }
  fft(fa, sz);
  C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
    fa[i] = z;
  }
  for (int i = 0; i < (sz >> 1); i++) {
    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
    C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
    fa[i] = A0 + A1 * s;
  }
  fft(fa, sz >> 1);
  vector<double> ret(need);
  for (int i = 0; i < need; i++) {
    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
  }
  return ret;
}
} // namespace CFFT


vector<ll> convolution(vector<ll>& a, vector<ll>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  ll abs_sum_a = 0, abs_sum_b = 0;
  rep(i, n) abs_sum_a += abs(a[i]);
  rep(i, n) abs_sum_b += abs(b[i]);
  assert(abs_sum_a * abs_sum_b < 1e15);
  vector<double> c = CFFT::convolution_fft(a, b);
  vector<ll> res(len(c));
  rep(i, len(c)) res[i] = ll(floor(c[i] + .5));
  return res;
}

template<typename mint>
enable_if_t<is_same<mint, modint998>::value, vector<mint>> convolution(const vector<mint>& a, const vector<mint>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  return convolution_ntt(a, b);
}

template<typename mint>
enable_if_t<!is_same<mint, modint998>::value, vector<mint>> convolution(const vector<mint>& a, const vector<mint>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  return convolution_garner(a, b);
}

vector<ull> convolution_mod_2_64(const vector<ull>& a, const vector<ull>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  constexpr int P0 = 998244353;
  constexpr int P1 = 754974721;
  constexpr int P2 = 167772161;
  constexpr int P3 = 469762049;
  constexpr int P4 = 880803841;
  using M0 = ModInt<P0>;
  using M1 = ModInt<P1>;
  using M2 = ModInt<P2>;
  using M3 = ModInt<P3>;
  using M4 = ModInt<P4>;
  vector<M0> a0(n), b0(m);
  vector<M1> a1(n), b1(m);
  vector<M2> a2(n), b2(m);
  vector<M3> a3(n), b3(m);
  vector<M4> a4(n), b4(m);
  rep(i, n) a0[i] = a[i] % P0;
  rep(i, m) b0[i] = b[i] % P0;
  rep(i, n) a1[i] = a[i] % P1;
  rep(i, m) b1[i] = b[i] % P1;
  rep(i, n) a2[i] = a[i] % P2;
  rep(i, m) b2[i] = b[i] % P2;
  rep(i, n) a3[i] = a[i] % P3;
  rep(i, m) b3[i] = b[i] % P3;
  rep(i, n) a4[i] = a[i] % P4;
  rep(i, m) b4[i] = b[i] % P4;
  a0 = convolution_ntt<M0>(a0, b0);
  a1 = convolution_ntt<M1>(a1, b1);
  a2 = convolution_ntt<M2>(a2, b2);
  a3 = convolution_ntt<M3>(a3, b3);
  a4 = convolution_ntt<M4>(a4, b4);
  static const M1 inv10 = M1(1) / M1(P0);
  static const M2 inv21 = M2(1) / M2(P1), inv20 = inv21 / M2(P0);
  static const M3 inv32 = M3(1) / M3(P2), inv31 = inv32 / M3(P1),
                  inv30 = inv31 / M3(P0);
  static const M4 inv43 = M4(1) / M4(P3), inv42 = inv43 / M4(P2),
                  inv41 = inv42 / M4(P1), inv40 = inv41 / M4(P0);
  vector<ull> c(len(a0));
  rep(i, len(c)) {
    ll x0 = a0[i].x;
    ll x1 = (M1(a1[i] - x0) * inv10).x;
    ll x2 = (M2(a2[i] - x0) * inv20 - M2(x1) * inv21).x;
    ll x3 = (M3(a3[i] - x0) * inv30 - M3(x1) * inv31 - M3(x2) * inv32).x;
    ll x4 = (M4(a4[i] - x0) * inv40 - M4(x1) * inv41 - M4(x2) * inv42
             - M4(x3) * inv43)
                .x;
    c[i] = x0 + P0 * (x1 + P1 * (x2 + P2 * (x3 + P3 * ull(x4))));
  }
  return c;
}

template<typename mint>
vector<mint> convolution_huge(const vector<mint>& A, const vector<mint>& B) {
  int N = len(A), M = len(B);
  if (N + M - 1 <= (1 << 23)) return convolution(A, B);
  ll L = 22;
  vv(mint, C, 4, 2 << L);
  vv(mint, D, 4, 2 << L);
  int mask = (1 << L) - 1;
  rep(i, N) C[i >> L][i & mask] = A[i];
  rep(i, M) D[i >> L][i & mask] = B[i];
  rep(i, 4) ntt(C[i], false);
  rep(i, 4) ntt(D[i], false);

  vector<mint> ANS(8 << L);

  rep(i, 7) {
    vector<mint> E(2 << L);
    rep(c, 4) rep(d, 4) if(c + d == i) {
      rep(k, 2 << L) E[k] += C[c][k] * D[d][k];
    }
    ntt(E, true);
    rep(k, 2 << L) ANS[(i << L) + k] += E[k];
  }
  ANS.resize(N + M - 1);
  return ANS;
}
