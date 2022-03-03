#pragma GCC optimize("Ofast")
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
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template <class T> T POW(T x, int n) { T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

const ll mod = 998244353;
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
using modint = ModInt< mod >;
typedef vector<modint> vmi;
//------------------------------------------------------------------------------
const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
modint comb(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
modint combP(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, const ll &p = mod) { ll ret = 1; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
//------------------------------------------------------------------------------
template<typename T> vector<T> m_map(vector<vector<T>>& l, vector<T>& r) {
  assert(l.size() > 0 || r.size() > 0); assert(l[0].size() == r.size()); vector<T> ans(l.size(), 0);
  for(int i = 0; i < l.size(); i++) for (int j = 0; j < r.size(); j++) ans[i] += l[i][j] * r[j]; return ans; }
template<typename T> vector<vector<T>> m_product(vector<vector<T>>& l, vector<vector<T>>& r) {
  assert(l.size() > 0 || r.size() > 0); assert(l[0].size() == r.size());
  vector<vector<T>> ans(l.size(), vector<T>(r[0].size(), 0));
  for(int i = 0; i < l.size(); i++) { assert(l[i].size() == l[0].size());
    for(int j = 0; j < r[0].size(); j++) for(int k = 0; k < l[0].size(); k++) { assert(r[k].size() == r[0].size()); ans[i][j] += l[i][k] * r[k][j]; }
  }
  return ans; }
template <typename T> T m_pow(T m, ll n) { assert(n > 0); T res = m; n--; for(; n; n >>= 1, m = m_product(m, m)) if(n & 1) res = m_product(res, m); return res; }

void solve() {
  ll N, K; cin >> N >> K;

  if (K != 1) return;

  if (N == 1) { cout << 2 << "\n"; return; }
  vector<vmi> m = {{1, 1}, {1, 0}};
  m = m_pow(m, N - 1);
  vmi initial = {1, 1};
  vmi ans = m_map(m, initial);
  cout << ans[0] + ans[1] << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
