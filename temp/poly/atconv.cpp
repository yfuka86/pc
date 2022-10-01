// 入出力マクロの上に
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353; using vmi = vector<mint>; using vvmi = vector<vmi>; using v3mi = vector<vvmi>; using v4mi = vector<v3mi>;
const ll mod = 998244353;
istream& operator>>(istream& in, mint &a) { long long e; in >> e; a = e; return in; }
ostream& operator<<(ostream& out, mint &a) { return out << a.val(); }
//------------------------------------------------------------------------------
const int max_n = 1 << 20;
mint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); }
  factinv[max_n - 1] = mint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
mint comb(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
mint combP(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, const ll &p = mod) { ll ret = 1; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
//------------------------------------------------------------------------------
// Nlog^2Nで複数配列を効率よくたたみ込むもの
vmi all_convolution(vvmi &a) {
  multimap<ll, vmi> que;
  for (auto &v: a) que.emplace(v.size(), v);
  while (que.size() > 1) {
    vmi a = que.begin()->se; que.erase(que.begin());
    vmi b = que.begin()->se; que.erase(que.begin());
    vmi c = convolution(a, b);
    que.emplace(c.size(), c);
  }
  return que.begin()->se;
}