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
struct RandGen {
  using uidll = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll lint(ll a, ll b) { uidll d(a, b - 1); return d(mt); }
  vl vlint(ll l, ll a, ll b) { uidll d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vlperm(ll l) { vl perm(l); iota(all(perm), 1); random_shuffle(all(perm)); return perm; }
  string saz(ll l, ll a = 0, ll z = 26) { vl az = vlint(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string snum(ll l, ll zero = 0, ll ten = 10) { vl zt = vlint(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
};
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a){ sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};

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
S op(S l, S r) { return min(l, r); }
S e() { return LINF; }

void solve() {
  ll n, s; cin >> n >> s;
  vl a(n), c(n + 1, 0);
  rep(i, n) cin >> a[i];
  rep(i, n) c[i + 1] = c[i] + a[i];

  segtree<S, op, e> seg(c);

  ll num = 0;
  ll ans = -1;
  rep(l, n) {
    ll from = c[l];
    ll r = seg.max_right<function<bool(S)>>(l,
      [&](S x) {
        return x - from >= -s;
      }
    );
    if (chmax(num, r - l - 1)) ans = l;
  }

  if (ans == -1) cout << -1 << "\n";
  else cout << ans + 1 << " " << ans + num << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}
