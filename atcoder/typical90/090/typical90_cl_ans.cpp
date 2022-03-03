#include <atcoder/all>
using namespace std;
using namespace atcoder;

template <typename mint>
struct FormalPowerSeries : vector<mint> {
  using vector<mint>::vector;
  using vector<mint>::operator=;
  using fps = FormalPowerSeries;

  fps &operator+=(const fps &other) {
    if (this->size() < other.size()) this->resize(other.size());
    for (int i = 0; i < (int)other.size(); i++) (*this)[i] += other[i];
    return *this;
  }

  fps &operator-=(const fps &other) {
    if (this->size() < other.size()) this->resize(other.size());
    for (int i = 0; i < (int)other.size(); i++) (*this)[i] -= other[i];
    return *this;
  }

  fps &operator*=(const fps &other) {
    *this = convolution(move(*this), other);
    return *this;
  }

  fps &operator*=(const mint &other) {
    for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= other;
    return *this;
  }

  fps operator+(const FormalPowerSeries &other) const { return FormalPowerSeries(*this) += other; }
  fps operator-(const FormalPowerSeries &other) const { return FormalPowerSeries(*this) -= other; }
  fps operator*(const FormalPowerSeries &other) const { return FormalPowerSeries(*this) *= other; }
  fps operator*(const mint &other) const { return FormalPowerSeries(*this) *= other; }

  fps operator-() const {
    fps res(this->size());
    for (int i = 0; i < (int)this->size(); i++) res[i] = -(*this)[i];
    return res;
  }

  fps operator>>(int d) const {
    if ((int)this->size() <= d) return {};
    fps res(*this);
    res.erase(res.begin(), res.begin() + d);
    return res;
  }

  fps operator<<(int d) const {
    fps res(*this);
    res.insert(res.begin(), d, mint(0));
    return res;
  }

  void ntt() { internal::butterfly(*this); }

  void intt() {
    internal::butterfly_inv(*this);
    mint iz = mint((int)this->size()).inv();
    for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= iz;
  }

  void ntt_doubling() {
    int m = (int)this->size();
    fps F = fps(*this);
    F.intt();
    mint coeff = mint(1);
    mint zeta = mint(internal::primitive_root<mint::mod()>).pow((mint::mod() - 1) / (2 * m));
    for (int i = 0; i < m; i++) {
      F[i] *= coeff;
      coeff *= zeta;
    }
    F.ntt();
    this->resize(2 * m);
    for (int i = 0; i < m; i++) (*this)[i + m] = F[i];
  }

  fps inv(int deg = -1) const {
    if (deg == -1) deg = (int)this->size() - 1;
    fps res(deg + 1);
    res[0] = (*this)[0].inv();
    for (int m = 1; m <= deg; m <<= 1) {
      fps F(2 * m), G(2 * m);
      for (int j = 0; j < min((int)this->size(), 2 * m); j++) F[j] = (*this)[j];
      for (int j = 0; j < m; j++) G[j] = res[j];
      F.ntt();
      G.ntt();
      for (int j = 0; j < 2 * m; j++) F[j] *= G[j];
      F.intt();
      for (int j = 0; j < m; j++) F[j] = 0;
      F.ntt();
      for (int j = 0; j < 2 * m; j++) F[j] *= G[j];
      F.intt();
      for (int j = m; j < min(2 * m, deg + 1); j++) res[j] = -F[j];
    }
    return res;
  }
};

template <typename mint>
mint poly_coeff(FormalPowerSeries<mint> Q, FormalPowerSeries<mint> P, long long n) {
  int m = 1;
  while (m < (int)Q.size()) m <<= 1;
  P.resize(2 * m);
  Q.resize(2 * m);
  P.ntt();
  Q.ntt();
  FormalPowerSeries<mint> S(2 * m), T(2 * m);
  vector<int> btr(m);
  for (int i = 0, logn = __builtin_ctz(m); i < m; i++) btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (logn - 1));
  mint dw = mint(internal::primitive_root<mint::mod()>).inv().pow((mint::mod() - 1) / (2 * m));
  while (n) {
    mint inv2 = mint(2).inv();
    S.resize(m);
    T.resize(m);
    for (int i = 0; i < m; i++) {
      T[i] = Q[i << 1 | 0] * Q[i << 1 | 1];
    }
    if (n & 1) {
      for (auto &i: btr) {
        S[i] = (P[i << 1 | 0] * Q[i << 1 | 1] - P[i << 1 | 1] * Q[i << 1 | 0]) * inv2;
        inv2 *= dw;
      }
    } else {
      for (int i = 0; i < m; i++) S[i] = (P[i << 1 | 0] * Q[i << 1 | 1] + P[i << 1 | 1] * Q[i << 1 | 0]) * inv2;
    }
    swap(P, S);
    swap(Q, T);
    n >>= 1;
    if (n < m) break;
    P.ntt_doubling();
    Q.ntt_doubling();
  }
  P.intt();
  Q.intt();
  return (P * Q.inv())[n];
}

using mint = modint998244353;
using fps = FormalPowerSeries<mint>;

int main() {
  long n, k;
  cin >> n >> k;
  fps F = {1, 1};
  for(int m = k - 1; m > 0; m--) {
    int c = k / m;
    fps G = fps({1}) - (F << 1);
    F *= G.inv(c);
    F.resize(c + 1);
  }
  fps G = fps({1}) - (F << 1);
  mint ans = poly_coeff(G, F, n);
  cout << ans.val() << '\n';
}
