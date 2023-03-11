const ll mod = 1000000007;
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
namespace COM {
  vector<mint> fact, factinv, inv; int cur = 2;
  struct init { init() { for(int i = 0; i < 2; ++i) { fact.push_back(1); factinv.push_back(1); inv.push_back(1); } } } init;
  void incr() { fact.push_back(fact.back() * cur); inv.push_back(-inv[mod % cur] * (mod / cur)); factinv.push_back(factinv.back() * inv[cur]); cur++; }
  mint combp(int n, int k) { assert(n < 1e8); if (n < 0 || k < 0 || n < k) return 0; while (cur <= n) incr(); return fact[n] * factinv[n - k]; }
  mint comb(int n, int k) { mint p = combp(n, k); if (p == 0) return 0; else return p * factinv[k]; }
}; using COM::combp, COM::comb;
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, ll p = mod) { ll ret = 1; x %= p; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
ll mod_inv(ll x, ll m) { ll a = x, b = m, u = 1, v = 0, t; while(b) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } if (u < 0) u += m; return u % m; }
//------------------------------------------------------------------------------


