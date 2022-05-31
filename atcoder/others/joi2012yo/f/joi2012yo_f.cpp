#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define vlin(name,sz,offset) vl name(sz); rep(i,sz){cin>>name[i]; name[i]--;}
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT; typedef tuple<ll, ll, ll, ll> LT4;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll l(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  vl vecl(ll l, ll a, ll b) { ud d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vecperm(ll l, ll from = 0) { vl perm(l); iota(all(perm), from); shuffle(perm); return perm; }
  string str(ll l, vector<char> op) { vl fig = vecl(l, 0, op.size()); string s; rep(i, l) s.pb(op[fig[i]]); return s; }
  string straz(ll l, ll a = 0, ll z = 26) { vl az = vecl(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string strnum(ll l, ll zero = 0, ll ten = 10) { vl zt = vecl(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
  void shuffle(vl &a) { std::shuffle(all(a), mt); }
};
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll digits(ll n) { ll ret = 0; while(n > 0) { ret++; n /= 10; } return ret; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a){ sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template <class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }

template<typename T> void coutarray(vector<T>& v, int offset = 0, string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset) cout << v[i] + offset; else cout << v[i]; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v, int offset = 0) { rep(i, v.size()) { coutarray(v[i], offset); } }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T, typename S> void coutpair(pair<T, S> & p) { cout << p.first << " " << p.second << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
const string drul = "DRUL"; vl dx = {1, 0, -1, 0}; vl dy = {0, 1, 0, -1};

ll solve(ll N, vl a) {
  ll ans = -1; return ans;
}

ll naive(ll N, vl a) {
  ll ans = 1; return ans;
}

void compare() {
  RandGen rg; ll c = 0, loop = 10;
  while (true) { c++; if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll N = 10;
    vl a = rg.vecl(N, 1, 1e2);
    auto s = solve(N, a); auto n = naive(N, a);
    if (n != s) {
      cout << c << "times tried" << "\n";
      cout << N << "\n"; coutarray(a);
      cout << "solve: " << s << "\n";
      cout << "naive: " << n << "\n";
      break;
    }
  }
}
const ll mod = 10000;
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
  static int get_mod() { return mod; }
};
using mint = ModInt< mod >; typedef vector<mint> vmi; typedef vector<vmi> vvmi; typedef vector<vvmi> vvvmi;
//------------------------------------------------------------------------------
const int max_n = 1 << 20;
mint fact[max_n], factinv[max_n];
void init_f() { fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); } factinv[max_n - 1] = mint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
mint comb(int a, int b) { assert(fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
mint combP(int a, int b) { assert(fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, const ll &p = mod) { ll ret = 1; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
ll mod_inv(ll x, ll m) { ll a = x, b = m, u = 1, v = 0, t; while(b) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } if (u < 0) u += m; return u % m; }
//------------------------------------------------------------------------------

ll M;
vl p10(600, 0);

void calcp10() {
  p10[0] = 1;
  rep(i, 600) {
    p10[i + 1] = p10[i] * 10;
    p10[i + 1] %= M;
  }
}

mint zigzag(vl a) {
  ll n = a.size();
  vector<vvvmi> dp(M, vvvmi(10, vvmi(3, vmi(2, 0)))), dpt(M, vvvmi(10, vvmi(3, vmi(2, 0))));;
  rep2(i, 1, a[0]) dp[i * p10[n - 1] % M][i][0][0] = 1;
  dp[a[0] * p10[n - 1] % M][a[0]][0][1] = 1;

  rep2(i, 1, n) {
    rep2(d, 1, 10) dpt[d * p10[n - i - 1] % M][d][0][0] += 1;
    rep(m, M) {
      rep(d, 10) rep(nd, 10) {
        if (d == nd) continue;
        ll add = nd * p10[n - i - 1];

        if (d > nd) {
          dpt[(m + add) % M][nd][1][0] += dp[m][d][0][0];
          dpt[(m + add) % M][nd][1][0] += dp[m][d][2][0];
          if (nd <= a[i]) {
            dpt[(m + add) % M][nd][1][nd == a[i]] += dp[m][d][0][1];
            dpt[(m + add) % M][nd][1][nd == a[i]] += dp[m][d][2][1];
          }
        } else {
          dpt[(m + add) % M][nd][2][0] += dp[m][d][0][0];
          dpt[(m + add) % M][nd][2][0] += dp[m][d][1][0];
          if (nd <= a[i]) {
            dpt[(m + add) % M][nd][2][nd == a[i]] += dp[m][d][0][1];
            dpt[(m + add) % M][nd][2][nd == a[i]] += dp[m][d][1][1];
          }
        }
      }
    }
    dp = dpt;
    dpt.assign(M, vvvmi(10, vvmi(3, vmi(2, 0))));
  }

  mint ans = 0;
  rep(d, 10) rep(i, 3) rep(j, 2) ans += dp[0][d][i][j];

  return ans;
}


void solve() {
  string A, B;
  cin >> A >> B >> M;
  calcp10();
  vl a, b;
  rep(i, A.size()) a.pb(A[i] - '0');
  rep(i, B.size()) b.pb(B[i] - '0');

  ll dsum = 0;
  rep(i, a.size()) dsum += a[i] * p10[a.size() - i - 1];
  bool valid = dsum % M == 0;
  rep(i, a.size() - 2) {
    if (a[i] < a[i + 1] && a[i + 1] > a[i + 2]) continue;
    if (a[i] > a[i + 1] && a[i + 1] < a[i + 2]) continue;
    valid = false; break;
  }
  cout << zigzag(b) - zigzag(a) + valid << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(15);
  int t = 1; // cin >> t;
  while (t--) solve();
  // while (t--) compare();
}
