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
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};

struct Barrett {
  using u32 = unsigned int;
  using i64 = long long;
  using u64 = unsigned long long;
  u32 m;
  u64 im;
  Barrett() : m(), im() {}
  Barrett(int n) : m(n), im(u64(-1) / m + 1) {}
  constexpr inline i64 quo(u64 n) {
    u64 x = u64((__uint128_t(n) * im) >> 64);
    u32 r = n - x * m;
    return m <= r ? x - 1 : x;
  }
  constexpr inline i64 rem(u64 n) {
    u64 x = u64((__uint128_t(n) * im) >> 64);
    u32 r = n - x * m;
    return m <= r ? r + m : r;
  }
  constexpr inline pair<i64, int> quorem(u64 n) {
    u64 x = u64((__uint128_t(n) * im) >> 64);
    u32 r = n - x * m;
    if (m <= r) return {x - 1, r + m};
    return {x, r};
  }
  constexpr inline i64 pow(u64 n, i64 p) {
    u32 a = rem(n), r = m == 1 ? 0 : 1;
    while (p) {
      if (p & 1) r = rem(u64(r) * a);
      a = rem(u64(a) * a);
      p >>= 1;
    }
    return r;
  }
};

struct ArbitraryModInt {
  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y) {
    int z = y % get_mod();
    if (z < 0) z += get_mod();
    x = z;
  }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if ((x += p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    x = rem((unsigned long long)x * p.x);
    return *this;
  }

  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }

  ArbitraryModInt operator+(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) += p;
  }

  ArbitraryModInt operator-(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) -= p;
  }

  ArbitraryModInt operator*(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) *= p;
  }

  ArbitraryModInt operator/(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) /= p;
  }

  bool operator==(const ArbitraryModInt &p) const { return x == p.x; }

  bool operator!=(const ArbitraryModInt &p) const { return x != p.x; }

  ArbitraryModInt inverse() const {
    int a = x, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }

  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }

  int get() const { return x; }

  inline unsigned int rem(unsigned long long p) { return barrett().rem(p); }

  static inline Barrett &barrett() {
    static Barrett b;
    return b;
  }

  static inline int &get_mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) {
    assert(0 < md && md <= (1LL << 30) - 1);
    get_mod() = md;
    barrett() = Barrett(md);
  }
};

using mint = ArbitraryModInt;
typedef vector<mint> vmi; typedef vector<vmi> vvmi; typedef vector<vvmi> vvvmi;

void solve() {
  ll N, P; cin >> N >> P;
  mint::set_mod(P);

  vvmi dp(N, vmi(N + 1, 0));
  vvmi dpsum(N, vmi(N + 2, 0));
  dp[0][0] = 1;

  rep(i, N) {
    rep(j, N + 1) {
      // rep2(k, 1, N - i + 1) {
      //   ll add = 0;
      //   if (k < 10) add = 2;
      //   else if (k < 100) add = 3;
      //   else if (k < 1000) add = 4;
      //   else add = 5;
      //   dp[i + k][j + add] += dp[i][j] * (i == 0 ? 26 : 25) % P;
      //   dp[i + k][j + add] %= P;
      // }
      if (i >= 2) { dp[i][j] += (dpsum[i - 2][j] - dpsum[i - 2][max<ll>(0, j - 9)]) * (i - 2 == 0 ? 26 : 25); }
      if (i >= 3) { dp[i][j] += (dpsum[i - 3][max<ll>(0, j - 9)] - dpsum[i - 3][max<ll>(0, j - 99)]) * (i - 3 == 0 ? 26 : 25); }
      if (i >= 4) { dp[i][j] += (dpsum[i - 4][max<ll>(0, j - 99)] - dpsum[i - 4][max<ll>(0, j - 999)]) * (i - 4 == 0 ? 26 : 25); }
      if (i >= 5) { dp[i][j] += (dpsum[i - 5][max<ll>(0, j - 999)] - dpsum[i - 5][0]) * (i - 5 == 0 ? 26 : 25); }

      dpsum[i][j + 1] = dpsum[i][j] + dp[i][j];
    }
  }

  mint ans = 0;
  rep(i, N) ans += dp[i][N];
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
