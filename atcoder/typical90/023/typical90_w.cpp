#pragma GCC optimize("Ofast")
// #pragma GCC target("avx512f")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 2 - 10; const ll LINF = LLONG_MAX / 2 - 10; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template <class T> T POW(T x, int n) { assert(n >= 0); T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};
const ll mod = 1000000007;
//------------------------------------------------------------------------------
template< int mod >
struct ModInt {
  int x; ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }
  ModInt &operator-=(const ModInt &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  ModInt &operator*=(const ModInt &p) { x = (int) (1LL * x * p.x % mod); return *this; }
  ModInt &operator/=(const ModInt &p) { *this *= p.inverse(); return *this; }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const { int a = x, b = mod, u = 1, v = 0, t; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } return ModInt(u); }
  ModInt pow(int64_t n) const { ModInt ret(1), mul(x); while(n > 0) { if(n & 1) ret *= mul; mul *= mul; n >>= 1; } return ret; }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
  static int get_mod() { return mod; }
};
using mint = ModInt< mod >;
typedef vector<mint> vmi; typedef vector<vmi> vvmi;
//------------------------------------------------------------------------------
const int max_n = 1 << 20;
mint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); }
  factinv[max_n - 1] = mint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
mint comb(int a, int b) { assert(fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
mint combP(int a, int b) { assert(fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, const ll &p = mod) { ll ret = 1; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
ll mod_inv(ll x, ll m) { ll a = x, b = m, u = 1, v = 0, t; while(b) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } if (u < 0) u += m; return u % m; }
//------------------------------------------------------------------------------


ll H, W;
bool check(ll S) {
  if (S & 1) return false;
  if (S >> (W + 1) & 1) return false;
  if (S >> W & 1) return false;
  if (S >> (W - 1) & 1) return false;
  return true;
}

void solve() {
  cin >> H >> W;
  vvl C(H, vl(W, 0));
  rep(i, H) {
    string s; cin >> s;
    rep(j, W) if (s[j] == '#') C[i][j] = 1;
  }

  set<ll> states;
  function<void(ll, ll)> dfs = [&](ll s, ll d) {
    states.insert(s);
    if (d == W + 2) return;
    if (!(s & 1)) { dfs((s << 1) | 1, d + 1); }
    dfs(s << 1, d + 1);
  };
  dfs(0, 0);

  // 遷移の前計算
  ll n = states.size();
  vl m; map<ll, ll> mrev;
  vl nms1(n), nmp1(n), nms2(n), nmp2(n);
  for(auto s: states) { m.pb(s); mrev[s] = m.size() - 1; }
  ll filter = (1 << (W + 2)) - 1;
  rep(i, n) {
    nms1[i] = mrev[m[i] << 1 & filter];
    nmp1[i] = mrev[(m[i] << 1 | 1) & filter];
    nms2[i] = mrev[m[i] << 2 & filter];
    nmp2[i] = mrev[(m[i] << 2 | 1) & filter];
  }

  vmi dp(n, 0), ndp(n, 0); dp[0] = 1;
  rep(i, H) rep(j, W) {
    rep(S, n) {
      if (dp[S] == 0) continue;
      ndp[j != 0 ? nms1[S] : nms2[S]] += dp[S];

      ll cS = m[S]; if (j == 0) cS <<= 1;
      if (check(cS) && !C[i][j]) {
        ndp[j != 0 ? nmp1[S] : nmp2[S]] += dp[S];
      }
    }
    dp = ndp;
    ndp.assign(n, 0);
  }

  cout << accumulate(all(dp), mint(0)) << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
