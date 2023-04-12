#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using uint = unsigned int; using ull = unsigned long long; using ld = long double; using i128 = __int128_t;
using P = pair<int, int>; using LP = pair<ll, ll>; using LT = tuple<ll, ll, ll>; using LT4 =  tuple<ll, ll, ll, ll>;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> v3l; typedef vector<v3l> v4l; typedef vector<v4l> v5l;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<LT> vlt; typedef vector<vlt> vvlt; typedef vector<LT4> vlt4; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb; typedef vector<vb> vvb;
template<typename T> using pq = priority_queue<T>; template<typename T> using mpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> class infinity{ public: static constexpr T MAX=numeric_limits<T>::max(); static constexpr T MIN=numeric_limits<T>::min(); static constexpr T val=numeric_limits<T>::max()/2-1e6; static constexpr T mval=numeric_limits<T>::min()/2+1e6; };
const int INF = infinity<int>::val; const ll LINF = infinity<ll>::val; const ld DINF = infinity<ld>::val;
#define _overload5(a, b, c, d, e, name, ...) name
#define _overload4(a, b, c, d, name, ...) name
#define _overload3(a, b, c, name, ...) name
#define _rep0(n) for(ll i = 0; i < (ll)(n); ++i)
#define _rep1(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define _rep2(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define _rep3(i, a, b, c) for(ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define rep(...) _overload4(__VA_ARGS__, _rep3, _rep2, _rep1, _rep0)(__VA_ARGS__)
#define _per0(n) for(ll i = 0; i < (ll)(n); ++i)
#define _per1(i, n) for(ll i = (ll)(n)-1; i >= 0; --i)
#define _per2(i, a, b) for(ll i = (ll)(b)-1; i >= (ll)(a); --i)
#define _per3(i, a, b, c) for(ll i = (ll)(b)-1; i >= (ll)(a); i -= (ll)(c))
#define rep_r(...) _overload4(__VA_ARGS__, _per3, _per2, _per1, _per0)(__VA_ARGS__)
#define _fore0(a) rep(a.size())
#define _fore1(i, a) for(auto &&i : a)
#define _fore2(a, b, v) for(auto &&[a, b] : v)
#define _fore3(a, b, c, v) for(auto &&[a, b, c] : v)
#define _fore4(a, b, c, d, v) for(auto &&[a, b, c, d] : v)
#define fore(...) _overload5(__VA_ARGS__, _fore4, _fore3, _fore2, _fore1, _fore0)(__VA_ARGS__)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rng_of(v, l, r) (v).begin() + l, (v).begin() + r
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define v3(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define v4(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll l(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  LP lp(ll a, ll b, bool rng = true) { ll x = l(a, b - 1), y = l(rng ? x + 1 : a, b - 1); return {x, y}; }
  vl vecl(ll n, ll a, ll b) { ud d(a, b - 1); vl ret(n); rep(i, n) ret[i] = d(mt); return ret; }
  vl vecperm(ll n, ll from = 0) { vl perm(n); iota(all(perm), from); shuffle(perm); return perm; }
  string str(ll n, string op) { vl fig = vecl(n, 0, op.size()); string s; rep(i, n) s.pb(op[fig[i]]); return s; }
  string straz(ll n, ll a = 0, ll z = 26) { vl az = vecl(n, a, z); string s; rep(i, n) s.pb('a' + az[i]); return s; }
  string strnum(ll n, ll zero = 0, ll ten = 10) { vl zt = vecl(n, zero, ten); string s; rep(i, n) s.pb('0' + zt[i]); return s; }
  template<typename T> void shuffle(vector<T> &a) { std::shuffle(all(a), mt); }
};
// 入出力マクロの上に
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353; using vmi = vector<mint>; using vvmi = vector<vmi>; using v3mi = vector<vvmi>; using v4mi = vector<v3mi>;
const ll mod = 998244353;
istream& operator>>(istream& in, mint &a) { long long e; in >> e; a = e; return in; }
ostream& operator<<(ostream& out, mint &a) { return out << a.val(); }
template<class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> const_cast<T&>(e); return is; }
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << const_cast<T&>(e) << ' '; return os; }
//------------------------------------------------------------------------------
// デバッグ系
#define dout cout
template<typename T, typename=void> struct is_specialize:false_type{};
template<typename T> struct is_specialize<T, typename conditional<false,typename T::iterator, void>::type>:true_type{};
template<typename T> struct is_specialize<T, typename conditional<false,decltype(T::first), void>::type>:true_type{};
template<typename T> struct is_specialize<T, enable_if_t<is_integral<T>::value, void>>:true_type{};
void dump(const char &t) { dout<<t; } void dump(const string &t) { dout<<t; } void dump(const bool &t) { dout<<(t ? "true" : "false"); }
template<typename T, enable_if_t<!is_specialize<T>::value, nullptr_t> =nullptr> void dump(const T&t) { dout << const_cast<T &>(t); }
template<typename T> void dump(const T&t, enable_if_t<is_integral<T>::value>* =nullptr) { string tmp;if(t==infinity<T>::val||t==infinity<T>::MAX)tmp="inf";if(is_signed<T>::value&&(t==infinity<T>::mval||t==infinity<T>::MIN))tmp="-inf";if(tmp.empty())tmp=to_string(t);dout<<tmp; }
template<typename T, typename U, typename V> void dump(const tuple<T, U, V>&t) { dout<<"("; dump(get<0>(t)); dout<<" "; dump(get<1>(t)); dout << " "; dump(get<2>(t)); dout << ")"; }
template<typename T, typename U, typename V, typename S> void dump(const tuple<T, U, V, S>&t) { dout<<"("; dump(get<0>(t)); dout<<" "; dump(get<1>(t)); dout << " "; dump(get<2>(t)); dout << " "; dump(get<3>(t)); dout << ")"; }
template<typename T,typename U> void dump(const pair<T,U>&);
template<typename T> void dump(const T&t, enable_if_t<!is_void<typename T::iterator>::value>* =nullptr) { dout << "{ "; for(auto it=t.begin();it!=t.end();){ dump(*it); dout << (++it==t.end() ? "" : " "); } dout<<" }"; }
template<typename T,typename U> void dump(const pair<T,U>&t) { dout<<"("; dump(t.first); dout<<" "; dump(t.second); dout << ")"; }
void trace() { dout << "\n"; } template<typename Head, typename... Tail> void trace(Head&&head, Tail&&... tail) { dump(head); if(sizeof...(tail)) dout<<", "; trace(forward<Tail>(tail)...); }
#ifdef ONLINE_JUDGE
#define debug(...) (void(0))
#else
#define debug(...) do {dout<<#__VA_ARGS__<<" = ";trace(__VA_ARGS__); } while(0)
#endif
// 入出力系
#define LL(...) ll __VA_ARGS__; IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; IN(__VA_ARGS__)
#define _vl(name, size) vl name(size); IN(name)
#define _vl2(name, size, off) vl name(size); IN(name); rep(i, size) name[i]-=off
#define VL(...) _overload3(__VA_ARGS__, _vl2, _vl)(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); IN(name)
#define VEC2(type, name1, name2, size) vector<type> name1(size), name2(size); for(int i = 0; i < size; i++) IN(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size) vector<type> name1(size), name2(size), name3(size); for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])
#define VEC4(type, name1, name2, name3, name4, size) vector<type> name1(size), name2(size), name3(size), name4(size); for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i], name4[i]);
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); IN(name)
void scan(int &a) { cin >> a; } void scan(long long &a) { cin >> a; } void scan(char &a) { cin >> a; } void scan(double &a) { cin >> a; } void scan(string &a) { cin >> a; }
template <class T> void scan(T &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &a) { for(auto &i : a) scan(i); }
void IN() {} template <class Head, class... Tail> void IN(Head &head, Tail &...tail) { scan(head); IN(tail...); }
#define OUTRET(...) { { OUT(__VA_ARGS__); return; } }
#define YES(ok) { if (ok) { OUT("YES"); } else OUT("NO"); }
#define Yes(ok) { if (ok) { OUT("Yes"); } else OUT("No"); }
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) { return os << p.first << " " << p.second; }
void OUT() { cout << '\n'; } template <typename Head, typename... Tail> void OUT(const Head &head, const Tail &...tail) { cout << head; if(sizeof...(tail)) cout << ' '; OUT(tail...); }
template<class T, class S = ll> void OUTARRAY(vector<T>& v, S offset = S(0), string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset != T(0)) { T t; t = v[i] + offset; cout << t; } else cout << v[i]; } cout << "\n"; }
template<class T, class S = ll> void OUTMAT(vector<vector<T>>& v, S offset = S(0)) { rep(i, v.size()) { OUTARRAY(v[i], offset); } }
template<typename T> void OUTBIN(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<typename Q, typename A> void IQUERY(initializer_list<Q> q, A &a, string str = "? ") { cout << str; vector<Q> v(q); OUTARRAY(v); cout.flush(); cin >> a; }
// template<typename Q, typename A> void IQUERY(initializer_list<Q> q, A &a, string str = "? ") { vector<Q> query(q); RandGen rg;
//   a = query[0] ? A() : A();
// }
template<typename A> void IANSWER(initializer_list<A> a, string str = "! ") { cout << str; vector<A> v(a); OUTARRAY(v); cout.flush(); }
// 数値系
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (ull)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (ull)(n)) x++; return x; }
pair<ll, ll> sqrtll(ll n) { ll x = round(sqrt(n)); if (x * x > n) --x; return {x, x + (x * x != n)}; }
ll POW(__uint128_t x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
vl primes(const ll n) { vb isp(n + 1, true); for(ll i = 2; i * i <= n; i++) { if ((i > 2 && i % 2 == 0) || !isp[i]) continue; for(ll j = i * i; j <= n; j += i) isp[j] = 0; } vl ret; for(ll i = 2; i <= n; i++) if (isp[i]) ret.emplace_back(i); return ret; }
vector<pair<ll, ll>> factorize(ll n) { vector<pair<ll, ll>> res; for (ll a = 2; a * a <= n; ++a) { if (n % a != 0) continue; ll ex = 0; while (n % a == 0) { ++ex; n /= a; } res.emplace_back(a, ex); } if (n != 1) res.emplace_back(n, 1); return res; }
vl divisor(ll n) { vl ret; for (ll i = 1; i * i <= n; i++) { if (n % i == 0) { ret.pb(i); if (i * i != n) ret.pb(n / i); } } sort(all(ret)); return ret; }
template<typename T> vl digits(T n) { assert(n >= 0); vl ret; while(n > 0) { ret.pb(n % 10); n /= 10; } return ret; }
template<class T, enable_if_t<is_integral<T>::value, nullptr_t> = nullptr> int msb(T x){ if (sizeof(x) == 4) return 31 - __builtin_clz(x); else return 63 - __builtin_clzll(x); }
template<class T, enable_if_t<is_integral<T>::value, nullptr_t> = nullptr> int lsb(T x){ if (sizeof(x) == 4) return __builtin_ctz(x); else return __builtin_ctzll(x); }
template<typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template<typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T = ll> T sum_of(const vector<T> &v, int l = 0, int r = INF) { return accumulate(rng_of(v, l, min(r, (int)v.size())), T(0)); }
template<class... T> constexpr auto min(T... a){ return min(initializer_list<common_type_t<T...>>{a...}); }
template<class... T> constexpr auto mine(T... a) { return min(a..., LINF, LINF); }
template<class... T> constexpr auto max(T... a){ return max(initializer_list<common_type_t<T...>>{a...}); }
template<class... T> constexpr auto maxe(T... a) { return max(a..., -LINF, -LINF); }
ll mex(vl& v) { ll n = v.size(); vb S(n + 1); for (auto a: v) if (a <= n) S[a] = 1; ll ret = 0; while (S[ret]) ret++; return ret; }
// 操作系
template<class T> void rotate(vector<vector<T>> &a) { ll n = a.size(), m = a[0].size(); vector<vector<T>> ret(m, vector<T>(n, 0)); rep(i, n) rep(j, m) ret[j][n - 1 - i] = a[i][j]; a = ret; }
template<typename T> void uniq(vector<T>&a) { sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a) { vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T = ll> pair<unordered_map<ll, ll>, unordered_map<ll, ll>> compmap(vector<T> &a) { vector<T> ca = a; comp(ca); unordered_map<ll, ll> ret, rev; rep(i, ca.size()) { ret[a[i]] = ca[i]; rev[ca[i]] = a[i]; } return mp(ret, rev); }
template<class T, class U> bool chmin(T &a, const U &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T, class U> bool chmax(T &a, const U &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
ll binary_search(function<bool(ll)> check, ll ok, ll ng, bool safe=true) { if (safe) { assert(check(ok)); assert(!check(ng)); } while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template<class T> vector<T> csum(vector<T> &a) { vector<T> ret(a.size() + 1, 0); rep(i, a.size()) ret[i + 1] = ret[i] + a[i]; return ret; }
template<class T> vector<int> argsort(const vector<T> &a) { vector<int> ids(a.size()); iota(all(ids), 0); sort(all(ids), [&](int i, int j) { return a[i] == a[j] ? i < j : a[i] < a[j]; }); return ids; }
template<class T> vector<T> rearrange(const vector<T> &orig, const vector<int> &rep) { assert(orig.size() == rep.size()); ll n = rep.size(); vector<T> ret(n); rep(i, n) ret[i] = orig[rep[i]]; return ret; }
template<class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
template <class T, class S, class U> bool incl(const T &x, const S &l, const U &r) { return l <= x and x < r; }
void change_bit(ll &x, int b, int i) { assert(b < 63); if (!!(x & 1ll << b) ^ i) x ^= 1ll << b;  }
bool is_palindrome(string s) { rep(i, (s.size() + 1) / 2) if (s[i] != s[s.size() - 1 - i]) { return false; } return true; }
// グラフ系
template< typename T = ll > struct Edge {
  int from, to; T cost; int idx; Edge() = default; Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; } bool operator<(const struct Edge& other) const { return cost < other.cost; } };
template< typename T = ll > struct Graph {
  vector< vector< Edge< T > > > g; int es; Graph() = default; explicit Graph(int n) : g(n), es(0) {}
  size_t size() const { return g.size(); }
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }
  void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };
const string drul = "DRUL"; const vl dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

ll solve(ll n, vl a) {
  ll ans = n - a[0]; return ans;
}

ll naive(ll n, vl a) {
  ll ans = n + a[0]; return ans;
}

void compare(bool check = true) { RandGen rg; ll c = 0, loop = 10;
  while (++c) { if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll n = 10;
    vl a = rg.vecl(n, 1, 1e2);
    auto so = solve(n, a); auto na = naive(n, a);
    if (!check || na != so) { cout << c << "times tried" << "\n";
      debug(n, a); debug(so); debug(na);
    if (check || (!check && c > loop)) break; }
  }
}

//------------------------------------------------------------------------------
//https://judge.yosupo.jp/submission/33048
template<class T>
struct FormalPowerSeries : vector<T> {
  using vector<T>::vector;
  using vector<T>::operator=;
  using F = FormalPowerSeries;

  F operator-() const {
    F res(*this);
    for (auto &e : res) e = -e;
    return res;
  }
  F &operator*=(const T &g) {
    for (auto &e : *this) e *= g;
    return *this;
  }
  F &operator/=(const T &g) {
    assert(g != T(0));
    *this *= g.inv();
    return *this;
  }
  F &operator+=(const F &g) {
    int n = this->size(), m = g.size();
    rep(i, min(n, m)) (*this)[i] += g[i];
    return *this;
  }
  F &operator-=(const F &g) {
    int n = this->size(), m = g.size();
    rep(i, min(n, m)) (*this)[i] -= g[i];
    return *this;
  }
  F &operator<<=(const int d) {
    int n = this->size();
    if (d >= n) *this = F(n);
    this->insert(this->begin(), d, 0);
    this->resize(n);
    return *this;
  }
  F &operator>>=(const int d) {
    int n = this->size();
    this->erase(this->begin(), this->begin() + min(n, d));
    this->resize(n);
    return *this;
  }

  // O(n log n)
  F inv(int d = -1) const {
    int n = this->size();
    assert(n != 0 && (*this)[0] != 0);
    if (d == -1) d = n;
    assert(d >= 0);
    F res{(*this)[0].inv()};
    for (int m = 1; m < d; m *= 2) {
      F f(this->begin(), this->begin() + min(n, 2*m));
      F g(res);
      f.resize(2*m), internal::butterfly(f);
      g.resize(2*m), internal::butterfly(g);
      rep(i, 2*m) f[i] *= g[i];
      internal::butterfly_inv(f);
      f.erase(f.begin(), f.begin() + m);
      f.resize(2*m), internal::butterfly(f);
      rep(i, 2*m) f[i] *= g[i];
      internal::butterfly_inv(f);
      T iz = T(2*m).inv(); iz *= -iz;
      rep(i, m) f[i] *= iz;
      res.insert(res.end(), f.begin(), f.begin() + m);
    }
    res.resize(d);
    return res;
  }

  // fast: FMT-friendly modulus only
  // O(n log n)
  F &multiply_inplace(const F &g, int d = -1) {
    int n = this->size();
    if (d == -1) d = n;
    assert(d >= 0);
    *this = convolution(move(*this), g);
    this->resize(d);
    return *this;
  }
  F multiply(const F &g, const int d = -1) const { return F(*this).multiply_inplace(g, d); }
  // O(n log n)
  F &divide_inplace(const F &g, int d = -1) {
    int n = this->size();
    if (d == -1) d = n;
    assert(d >= 0);
    *this = convolution(move(*this), g.inv(d));
    this->resize(d);
    return *this;
  }
  F divide(const F &g, const int d = -1) const { return F(*this).divide_inplace(g, d); }

  // // naive
  // // O(n^2)
  // F &multiply_inplace(const F &g) {
  //   int n = this->size(), m = g.size();
  //   rep_r(i, n) {
  //     (*this)[i] *= g[0];
  //     rep(j, 1, min(i+1, m)) (*this)[i] += (*this)[i-j] * g[j];
  //   }
  //   return *this;
  // }
  // F multiply(const F &g) const { return F(*this).multiply_inplace(g); }
  // // O(n^2)
  // F &divide_inplace(const F &g) {
  //   assert(g[0] != T(0));
  //   T ig0 = g[0].inv();
  //   int n = this->size(), m = g.size();
  //   rep(i, n) {
  //     rep(j, 1, min(i+1, m)) (*this)[i] -= (*this)[i-j] * g[j];
  //     (*this)[i] *= ig0;
  //   }
  //   return *this;
  // }
  // F divide(const F &g) const { return F(*this).divide_inplace(g); }

  // sparse
  // O(nk)
  F &multiply_inplace(vector<pair<int, T>> g) {
    int n = this->size();
    auto [d, c] = g.front();
    if (d == 0) g.erase(g.begin());
    else c = 0;
    rep_r(i, n) {
      (*this)[i] *= c;
      for (auto &[j, b] : g) {
        if (j > i) break;
        (*this)[i] += (*this)[i-j] * b;
      }
    }
    return *this;
  }
  F multiply(const vector<pair<int, T>> &g) const { return F(*this).multiply_inplace(g); }
  // O(nk)
  F &divide_inplace(vector<pair<int, T>> g) {
    int n = this->size();
    auto [d, c] = g.front();
    assert(d == 0 && c != T(0));
    T ic = c.inv();
    g.erase(g.begin());
    rep(i, n) {
      for (auto &[j, b] : g) {
        if (j > i) break;
        (*this)[i] -= (*this)[i-j] * b;
      }
      (*this)[i] *= ic;
    }
    return *this;
  }
  F divide(const vector<pair<int, T>> &g) const { return F(*this).divide_inplace(g); }

  // multiply and divide (1 + cz^d)
  // O(n)
  void multiply_inplace(const int d, const T c) {
    int n = this->size();
    if (c == T(1)) rep_r(i, n-d) (*this)[i+d] += (*this)[i];
    else if (c == T(-1)) rep_r(i, n-d) (*this)[i+d] -= (*this)[i];
    else rep_r(i, n-d) (*this)[i+d] += (*this)[i] * c;
  }
  // O(n)
  void divide_inplace(const int d, const T c) {
    int n = this->size();
    if (c == T(1)) rep(i, n-d) (*this)[i+d] -= (*this)[i];
    else if (c == T(-1)) rep(i, n-d) (*this)[i+d] += (*this)[i];
    else rep(i, n-d) (*this)[i+d] -= (*this)[i] * c;
  }

  // O(n)
  T eval(const T &a) const {
    T x(1), res(0);
    for (auto e : *this) res += e * x, x *= a;
    return res;
  }

  // O(n)
  F &integ_inplace() {
    int n = this->size();
    assert(n > 0);
    if (n == 1) return *this = F{0};
    this->insert(this->begin(), 0);
    this->pop_back();
    vector<T> inv(n);
    inv[1] = 1;
    int p = T::mod();
    rep(i, 2, n) inv[i] = - inv[p%i] * (p/i);
    rep(i, 2, n) (*this)[i] *= inv[i];
    return *this;
  }
  F integ() const { return F(*this).integ_inplace(); }

  // O(n)
  F &deriv_inplace() {
    int n = this->size();
    assert(n > 0);
    rep(i, 2, n) (*this)[i] *= i;
    this->erase(this->begin());
    this->push_back(0);
    return *this;
  }
  F deriv() const { return F(*this).deriv_inplace(); }

  // O(n log n)
  F &log_inplace(int d = -1) {
    int n = this->size();
    assert(n > 0 && (*this)[0] == 1);
    if (d == -1) d = n;
    assert(d >= 0);
    if (d < n) this->resize(d);
    F f_inv = this->inv();
    this->deriv_inplace();
    this->multiply_inplace(f_inv);
    this->integ_inplace();
    return *this;
  }
  F log(const int d = -1) const { return F(*this).log_inplace(d); }

  // O(n log n)
  // https://arxiv.org/abs/1301.5804 (Figure 1, right)
  F &exp_inplace(int d = -1) {
    int n = this->size();
    assert(n > 0 && (*this)[0] == 0);
    if (d == -1) d = n;
    assert(d >= 0);
    F g{1}, g_fft{1, 1};
    (*this)[0] = 1;
    this->resize(d);
    F h_drv(this->deriv());
    for (int m = 2; m < d; m *= 2) {
      // prepare
      F f_fft(this->begin(), this->begin() + m);
      f_fft.resize(2*m), internal::butterfly(f_fft);

      // Step 2.a'
      {
        F f(m);
        rep(i, m) f[i] = f_fft[i] * g_fft[i];
        internal::butterfly_inv(f);
        f.erase(f.begin(), f.begin() + m/2);
        f.resize(m), internal::butterfly(f);
        rep(i, m) f[i] *= g_fft[i];
        internal::butterfly_inv(f);
        f.resize(m/2);
        f /= T(-m) * m;
        g.insert(g.end(), f.begin(), f.begin() + m/2);
      }

      // Step 2.b'--d'
      F t(this->begin(), this->begin() + m);
      t.deriv_inplace();
      {
        // Step 2.b'
        F r{h_drv.begin(), h_drv.begin() + m-1};
        // Step 2.c'
        r.resize(m); internal::butterfly(r);
        rep(i, m) r[i] *= f_fft[i];
        internal::butterfly_inv(r);
        r /= -m;
        // Step 2.d'
        t += r;
        t.insert(t.begin(), t.back()); t.pop_back();
      }

      // Step 2.e'
      if (2*m < d) {
        t.resize(2*m); internal::butterfly(t);
        g_fft = g; g_fft.resize(2*m); internal::butterfly(g_fft);
        rep(i, 2*m) t[i] *= g_fft[i];
        internal::butterfly_inv(t);
        t.resize(m);
        t /= 2*m;
      }
      else { // この場合分けをしても数パーセントしか速くならない
        F g1(g.begin() + m/2, g.end());
        F s1(t.begin() + m/2, t.end());
        t.resize(m/2);
        g1.resize(m), internal::butterfly(g1);
        t.resize(m),  internal::butterfly(t);
        s1.resize(m), internal::butterfly(s1);
        rep(i, m) s1[i] = g_fft[i] * s1[i] + g1[i] * t[i];
        rep(i, m) t[i] *= g_fft[i];
        internal::butterfly_inv(t);
        internal::butterfly_inv(s1);
        rep(i, m/2) t[i+m/2] += s1[i];
        t /= m;
      }

      // Step 2.f'
      F v(this->begin() + m, this->begin() + min<int>(d, 2*m)); v.resize(m);
      t.insert(t.begin(), m-1, 0); t.push_back(0);
      t.integ_inplace();
      rep(i, m) v[i] -= t[m+i];

      // Step 2.g'
      v.resize(2*m); internal::butterfly(v);
      rep(i, 2*m) v[i] *= f_fft[i];
      internal::butterfly_inv(v);
      v.resize(m);
      v /= 2*m;

      // Step 2.h'
      rep(i, min(d-m, m)) (*this)[m+i] = v[i];
    }
    return *this;
  }
  F exp(const int d = -1) const { return F(*this).exp_inplace(d); }

  // O(n log n)
  F &pow_inplace(ll k, int d = -1) {
    int n = this->size();
    if (d == -1) d = n;
    assert(d >= 0 && k >= 0);
    if (k == 0) {
      *this = F(d);
      if (d > 0) (*this)[0] = 1;
      return *this;
    }
    int l = 0;
    while (l < n && (*this)[l] == 0) ++l;
    if (l > (d-1)/k) return *this = F(d);
    T c = (*this)[l];
    this->erase(this->begin(), this->begin() + l);
    *this /= c;
    this->log_inplace(d - l*k);
    *this *= k;
    this->exp_inplace();
    *this *= c.pow(k);
    this->insert(this->begin(), l*k, 0);
    this->resize(d);
    return *this;
  }
  F pow(const ll k, const int d = -1) const { return F(*this).pow_inplace(k, d); }

  F operator*(const T &g) const { return F(*this) *= g; }
  F operator/(const T &g) const { return F(*this) /= g; }
  F operator+(const F &g) const { return F(*this) += g; }
  F operator-(const F &g) const { return F(*this) -= g; }
  F operator<<(const int d) const { return F(*this) <<= d; }
  F operator>>(const int d) const { return F(*this) >>= d; }
};

using fps = FormalPowerSeries<mint>;

// 集合sの部分集合で和がT以下になるものの個数を1,2,,,Tについて全て求める
template<class T> fps subset_sum(vector<T> s, ll t) {
  ll n = s.size(); vl cnt(t + 1); rep(i, n) if (s[i] <= t) cnt[s[i]]++;
  // sの各要素は1以上
  fps log(t + 1);
  rep(k, 1, t + 1) { if (!cnt[k]) continue;
    ll c = cnt[k];
    rep(i, k, t + 1, k) { // テイラー展開したlog(1 + x^k)をt以下の次数について足していく
      ll sgn = i / k & 1 ? 1 : -1;
      log[i] += mint(c) * sgn / (i / k);
    }
  }
  return log.exp();
}

void solve() {
  LL(n, t);
  VL(s, n);
  vmi ans = subset_sum(s, t);
  ans.erase(ans.begin());
  OUT(ans);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout << fixed << setprecision(20);
  int t = 1; // cin >> t;
  while (t--) if (1) solve(); else compare();
}
