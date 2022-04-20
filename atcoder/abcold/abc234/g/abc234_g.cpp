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
const ll mod = 998244353;
//------------------------------------------------------------------------------
template< int mod > struct ModInt {
  int x; ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }  ModInt &operator-=(const ModInt &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  ModInt &operator*=(const ModInt &p) { x = (int) (1LL * x * p.x % mod); return *this; }  ModInt &operator/=(const ModInt &p) { *this *= p.inverse(); return *this; }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const { int a = x, b = mod, u = 1, v = 0, t; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } return ModInt(u); }
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

//------------------------------------------------------------------------------
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
  segtree() : segtree(0) {}
  explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
  explicit segtree(const std::vector<S>& v) : _n(int(v.size())) { log = ceil_pow2(_n); size = 1 << log; d = std::vector<S>(2 * size, e()); for (int i = 0; i < _n; i++) d[size + i] = v[i]; for (int i = size - 1; i >= 1; i--) update(i); }
  void set(int p, S x) { assert(0 <= p && p < _n); p += size; d[p] = x; for (int i = 1; i <= log; i++) update(p >> i); }
  S get(int p) const { assert(0 <= p && p < _n); return d[p + size]; }
  S prod(int l, int r) const { assert(0 <= l && l <= r && r <= _n); S sml = e(), smr = e(); l += size; r += size; while (l < r) { if (l & 1) sml = op(sml, d[l++]); if (r & 1) smr = op(d[--r], smr); l >>= 1; r >>= 1; } return op(sml, smr); }
  S all_prod() const { return d[1]; }
  template <bool (*f)(S)> int max_right(int l) const { return max_right(l, [](S x) { return f(x); }); }
  template <class F> int max_right(int l, F f) const { assert(0 <= l && l <= _n); assert(f(e())); if (l == _n) return _n; l += size; S sm = e();
    do { while (l % 2 == 0) l >>= 1; if (!f(op(sm, d[l]))) { while (l < size) { l = (2 * l); if (f(op(sm, d[l]))) { sm = op(sm, d[l]); l++; } } return l - size; } sm = op(sm, d[l]); l++; } while ((l & -l) != l); return _n; }
  template <bool (*f)(S)> int min_left(int r) const { return min_left(r, [](S x) { return f(x); }); }
  template <class F> int min_left(int r, F f) const { assert(0 <= r && r <= _n); assert(f(e())); if (r == 0) return 0; r += size; S sm = e();
    do { r--; while (r > 1 && (r % 2)) r >>= 1; if (!f(op(d[r], sm))) { while (r < size) { r = (2 * r + 1); if (f(op(d[r], sm))) { sm = op(d[r], sm); r--; } } return r + 1 - size; } sm = op(d[r], sm); } while ((r & -r) != r); return 0; }
  private:
  int _n, size, log; std::vector<S> d;
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
//------------------------------------------------------------------------------

using S = ll;
S minop(S l, S r) { return min(l, r); }
S mine() { return LINF; }
S maxop(S l, S r) { return max(l, r); }
S maxe() { return 0; }

struct R {
  int h; mint w;
  R(int h, mint w): h(h), w(w) {};
};

struct D {
  stack<R> st;
  mint tot;
  D() {}
  void add(int h, mint w) {
    while (!st.empty() && st.top().h <= h) {
      auto [nh, nw] = st.top();
      tot -= nw * nh;
      w += nw;
      st.pop();
    }
    tot += w * h;
    st.emplace(h, w);
  }
};

void solve() {
  ll N; cin >> N;
  vl A(N); rep(i, N) cin >> A[i];
  // segtree<S, minop, mine> mins(A);
  // segtree<S, maxop, maxe> maxs(A);

  vmi dp(N + 1);
  D dmax, dmin;
  dp[0] = 1;
  rep(i, N) {
    dmax.add(A[i], dp[i]);
    dmin.add(-A[i], dp[i]);
    // cout << i <<" "<<  dmax.tot << " " << dmin.tot << "\n";
    dp[i + 1] = dmax.tot + dmin.tot;
  }
  cout << dp[N] << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
