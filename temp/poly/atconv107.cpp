// 入出力マクロの上に
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;
typedef vector<mint> vmi;
istream& operator>>(istream &in, mint &a) { long long e; in >> e; a = e; return in; }
ostream& operator<<(ostream &out, mint &a) { return out << a.val(); }
using namespace atcoder;

// https://judge.yosupo.jp/submission/87815
template <typename mint, internal::is_modint_t<mint>* = nullptr>
vector<mint> arbitrary_mod_convolution(const vector<mint>& a, const vector<mint>& b) {
  int n = int(a.size()), m = int(b.size());
  if (n == 0 or m == 0) return {};

  static constexpr long long MOD1 = 754974721;  // 2^24
  static constexpr long long MOD2 = 167772161;  // 2^25
  static constexpr long long MOD3 = 469762049;  // 2^26
  static constexpr long long M1M2 = MOD1 * MOD2;
  static constexpr long long INV_M1_MOD2 = internal::inv_gcd(MOD1, MOD2).second;
  static constexpr long long INV_M1M2_MOD3 = internal::inv_gcd(M1M2, MOD3).second;

  vector<int> a2(n), b2(m);
  for (int i = 0; i < n; ++i) a2[i] = a[i].val();
  for (int i = 0; i < m; ++i) b2[i] = b[i].val();

  auto c1 = convolution<MOD1>(a2, b2);
  auto c2 = convolution<MOD2>(a2, b2);
  auto c3 = convolution<MOD3>(a2, b2);

  vector<mint> c(n + m - 1);
  for (int i = 0; i < n + m - 1; ++i) {
    long long x1 = c1[i];
    long long x2 = (static_modint<MOD2>(c2[i] - x1) * INV_M1_MOD2).val();
    long long x3 = (static_modint<MOD3>(c3[i] - x1 - x2 * MOD1) * INV_M1M2_MOD3).val();
    c[i] = x1 + x2 * MOD1 + x3 * mint(M1M2).val();
  }
  return c;
}
