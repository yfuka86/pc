#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define vlin(name,sz,offset) vl name(sz); rep(i,sz){cin>>name[i]; name[i]-=offset;}
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT; typedef tuple<ll, ll, ll, ll> LT4;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> v3l; typedef vector<v3l> v4l; typedef vector<v4l> v5l;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll l(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  LP lp(ll a, ll b, bool rng = true) { ll x = l(a, b - 1), y = l(rng ? x + 1 : a, b - 1); return {x, y}; }
  vl vecl(ll l, ll a, ll b) { ud d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vecperm(ll l, ll from = 0) { vl perm(l); iota(all(perm), from); shuffle(perm); return perm; }
  string str(ll l, string op) { vl fig = vecl(l, 0, op.size()); string s; rep(i, l) s.pb(op[fig[i]]); return s; }
  string straz(ll l, ll a = 0, ll z = 26) { vl az = vecl(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string strnum(ll l, ll zero = 0, ll ten = 10) { vl zt = vecl(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
  void shuffle(vl &a) { std::shuffle(all(a), mt); }
};
template<typename T> void coutarray(vector<T>& v, int offset = 0, string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset) cout << v[i] + offset; else cout << v[i]; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v, int offset = 0) { rep(i, v.size()) { coutarray(v[i], offset); } }
template<typename T> void coutset(set<T> & s) { for (const auto& a : s) { cout << a << " "; } cout << "\n"; }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T, typename S> void coutpair(pair<T, S> & p, string sep = " ") { cout << p.first << ":" << p.second << sep; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<typename Q, typename A> void iquery(initializer_list<Q> q, A &a, string str = "? ") { cout << str; vector<Q> v(q); coutarray(v); cout.flush(); cin >> a; }
// template<typename Q, typename A> void iquery(initializer_list<Q> q, A &a, string str = "? ") { vector<Q> query(q); RandGen rg;
//   a = query[0] ? A() : A();
// }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll digits(ll n) { ll ret = 0; while(n > 0) { ret++; n /= 10; } return ret; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template<typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template<typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a){ sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template<class T> vector<T> csum(vector<T> &a) { vl ret(a.size() + 1, 0); rep(i, a.size()) ret[i + 1] = ret[i] + a[i]; return ret; }
template<class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
const string drul = "DRUL"; vl dx = {1, 0, -1, 0}; vl dy = {0, 1, 0, -1};

ll solve(ll N, vl a) {
  ll ans = -1; return ans;
}

ll naive(ll N, vl a) {
  ll ans = 1; return ans;
}

void compare(bool check = true) { RandGen rg; ll c = 0, loop = 10;
  while (++c) { if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll N = 10;
    vl a = rg.vecl(N, 1, 1e2);
    auto s = solve(N, a); auto n = naive(N, a);
    if (!check || n != s) { cout << c << "times tried" << "\n";
      cout << N << "\n"; coutarray(a);
      cout << "solve: " << s << "\n";
      cout << "naive: " << n << "\n";
    if (check || (!check && c > loop)) break; }
  }
}

// https://rsm9.hatenablog.com/entry/2021/02/01/220408
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
  public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
  explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) { log = ceil_pow2(_n); size = 1 << log; d = std::vector<S>(2 * size, e()); lz = std::vector<F>(size, id()); for (int i = 0; i < _n; i++) d[size + i] = v[i]; for (int i = size - 1; i >= 1; i--) update(i); }
  void set(int p, S x) { assert(0 <= p && p < _n); p += size; for (int i = log; i >= 1; i--) push(p >> i); d[p] = x; for (int i = 1; i <= log; i++) update(p >> i); }
  S get(int p) { assert(0 <= p && p < _n); p += size; for (int i = log; i >= 1; i--) push(p >> i); return d[p]; }
  S prod(int l, int r) { assert(0 <= l && l <= r && r <= _n); if (l == r) return e(); l += size; r += size; for (int i = log; i >= 1; i--) { if (((l >> i) << i) != l) push(l >> i); if (((r >> i) << i) != r) push((r - 1) >> i); } S sml = e(), smr = e();
    while (l < r) { if (l & 1) sml = op(sml, d[l++]); if (r & 1) smr = op(d[--r], smr); l >>= 1; r >>= 1; } return op(sml, smr); }
  S all_prod() { return d[1]; }
  void apply(int p, F f) { assert(0 <= p && p < _n); p += size; for (int i = log; i >= 1; i--) push(p >> i); d[p] = mapping(f, d[p]); for (int i = 1; i <= log; i++) update(p >> i); }
  void apply(int l, int r, F f) { assert(0 <= l && l <= r && r <= _n); if (l == r) return; l += size; r += size; for (int i = log; i >= 1; i--) { if (((l >> i) << i) != l) push(l >> i); if (((r >> i) << i) != r) push((r - 1) >> i); }
    { int l2 = l, r2 = r; while (l < r) { if (l & 1) all_apply(l++, f); if (r & 1) all_apply(--r, f); l >>= 1; r >>= 1; } l = l2; r = r2; } for (int i = 1; i <= log; i++) { if (((l >> i) << i) != l) update(l >> i); if (((r >> i) << i) != r) update((r - 1) >> i); } }
  template <bool (*g)(S)> int max_right(int l) { return max_right(l, [](S x) { return g(x); }); }
  template <class G> int max_right(int l, G g) { assert(0 <= l && l <= _n); assert(g(e())); if (l == _n) return _n; l += size; for (int i = log; i >= 1; i--) push(l >> i); S sm = e();
    do { while (l % 2 == 0) l >>= 1; if (!g(op(sm, d[l]))) { while (l < size) { push(l); l = (2 * l); if (g(op(sm, d[l]))) { sm = op(sm, d[l]); l++; } } return l - size; } sm = op(sm, d[l]); l++; } while ((l & -l) != l); return _n; }
  template <bool (*g)(S)> int min_left(int r) { return min_left(r, [](S x) { return g(x); }); }
  template <class G> int min_left(int r, G g) { assert(0 <= r && r <= _n); assert(g(e())); if (r == 0) return 0; r += size; for (int i = log; i >= 1; i--) push((r - 1) >> i); S sm = e();
    do { r--; while (r > 1 && (r % 2)) r >>= 1; if (!g(op(d[r], sm))) { while (r < size) { push(r); r = (2 * r + 1); if (g(op(d[r], sm))) { sm = op(d[r], sm); r--; } } return r + 1 - size; } sm = op(d[r], sm); } while ((r & -r) != r); return 0; }
  private:
  int _n, size, log; std::vector<S> d; std::vector<F> lz;
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) { d[k] = mapping(f, d[k]); if (k < size) { lz[k] = composition(f, lz[k]); if (d[k].fail) push(k), update(k); } }
  void push(int k) { all_apply(2 * k, lz[k]); all_apply(2 * k + 1, lz[k]); lz[k] = id(); }
};

// https://atcoder.jp/contests/abc256/tasks/abc256_h
namespace Beats {
using T = ll;
T secondmi(T a, T a2, T c, T c2) { return a == c ? min(a2, c2) : a2 <= c ? a2 : c2 <= a ? c2 : max(a, c); }
T secondma(T a, T a2, T b, T b2) { return a == b ? max(a2, b2) : a2 >= b ? a2 : b2 >= a ? b2 : min(a, b); }

struct S {
  T sum, lo, lo2, hi, hi2;
  int sz, nlo, nhi;
  bool fail;
  S(): sum(0), lo(LINF), lo2(LINF), hi(-LINF), hi2(-LINF), sz(0), nlo(0), nhi(0), fail(0) {}
  S(T x, unsigned sz_ = 1): sum(x * sz_), lo(x), hi(x), lo2(LINF), hi2(-LINF), sz(sz_), nlo(sz_), nhi(sz_), fail(0) {}
};
S e() { return S(); }
S op(S l, S r) {
  S ret; ret.sum = l.sum + r.sum;
  ret.lo = min(l.lo, r.lo), ret.lo2 = secondmi(l.lo, l.lo2, r.lo, r.lo2), ret.hi = max(l.hi, r.hi), ret.hi2 = secondma(l.hi, l.hi2, r.hi, r.hi2);
  ret.sz = l.sz + r.sz, ret.nlo = l.nlo * (l.lo <= r.lo) + r.nlo * (r.lo <= l.lo), ret.nhi = l.nhi * (l.hi >= r.hi) + r.nhi * (r.hi >= l.hi);
  return ret;
}
struct F {
  T lb, ub, bias;
  static F noop() noexcept { return {-LINF, LINF, 0}; }
  static F chmin(T x) noexcept { return {-LINF, x, 0}; }
  static F chmax(T x) noexcept { return {x, LINF, 0}; }
  static F add(T x) noexcept { return {-LINF, LINF, x}; }
};
S mapping(F f, S x) {
  if (x.sz == 0) return e();
  else if (x.lo == x.hi or f.lb == f.ub or f.lb >= x.hi or f.ub < x.lo) {
    return S(min(max(x.lo, f.lb), f.ub) + f.bias, x.sz);
  } else if (x.lo2 == x.hi) {
    x.lo = x.hi2 = max(x.lo, f.lb) + f.bias;
    x.hi = x.lo2 = min(x.hi, f.ub) + f.bias;
    x.sum = x.lo * x.nlo + x.hi * x.nhi;
    return x;
  } else if (f.lb < x.lo2 and f.ub > x.hi2) {
    T nxt_lo = max(x.lo, f.lb), nxt_hi = min(x.hi, f.ub);
    x.sum += (nxt_lo - x.lo) * x.nlo - (x.hi - nxt_hi) * x.nhi + f.bias * x.sz;
    x.lo = nxt_lo + f.bias, x.hi = nxt_hi + f.bias, x.lo2 += f.bias, x.hi2 += f.bias;
    return x;
  }
  x.fail = 1;
  return x;
}
F composition(F fnew, F fold) {
  return {
    max(min(fold.lb + fold.bias, fnew.ub), fnew.lb) - fold.bias,
    min(max(fold.ub + fold.bias, fnew.lb), fnew.ub) - fold.bias,
    fold.bias + fnew.bias
  };
}
F id() { return F::noop(); }
using segtree = lazy_segtree<S, op, e, F, mapping, composition, id>;
}


void solve() {
  ll n, q; cin >> n >> q;
  vlin(a, n, 0);

  vector<Beats::S> s(n);
  rep(i, n) s[i] = Beats::S(a[i]);
  Beats::segtree seg(s);

  rep(i, q) {
    ll cmd, l, r; cin >> cmd >> l >> r;
    ll b; if (cmd != 3) cin >> b;
    if (cmd == 0) {
      seg.apply(l, r, Beats::F::chmin(b));
    } else if (cmd == 1) {
      seg.apply(l, r, Beats::F::chmax(b));
    } else if (cmd == 2) {
      seg.apply(l, r, Beats::F::add(b));
    } else {
      cout << seg.prod(l, r).sum << "\n";
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(15);
  int t = 1; // cin >> t;
  while (t--) solve();
  // while (t--) compare();
}
