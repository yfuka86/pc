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

// struct Barrett {
//   using u32 = unsigned int;
//   using i64 = long long;
//   using u64 = unsigned long long;
//   u32 m;
//   u64 im;
//   Barrett() : m(), im() {}
//   Barrett(int n) : m(n), im(u64(-1) / m + 1) {}
//   constexpr inline i64 quo(u64 n) {
//     u64 x = u64((__uint128_t(n) * im) >> 64);
//     u32 r = n - x * m;
//     return m <= r ? x - 1 : x;
//   }
//   constexpr inline i64 rem(u64 n) {
//     u64 x = u64((__uint128_t(n) * im) >> 64);
//     u32 r = n - x * m;
//     return m <= r ? r + m : r;
//   }
//   constexpr inline pair<i64, int> quorem(u64 n) {
//     u64 x = u64((__uint128_t(n) * im) >> 64);
//     u32 r = n - x * m;
//     if (m <= r) return {x - 1, r + m};
//     return {x, r};
//   }
//   constexpr inline i64 pow(u64 n, i64 p) {
//     u32 a = rem(n), r = m == 1 ? 0 : 1;
//     while (p) {
//       if (p & 1) r = rem(u64(r) * a);
//       a = rem(u64(a) * a);
//       p >>= 1;
//     }
//     return r;
//   }
// };

// struct ArbitraryModInt {
//   int x;

//   ArbitraryModInt() : x(0) {}

//   ArbitraryModInt(int64_t y) {
//     int z = y % get_mod();
//     if (z < 0) z += get_mod();
//     x = z;
//   }

//   ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
//     if ((x += p.x) >= get_mod()) x -= get_mod();
//     return *this;
//   }

//   ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
//     if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
//     return *this;
//   }

//   ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
//     x = rem((unsigned long long)x * p.x);
//     return *this;
//   }

//   ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
//     *this *= p.inverse();
//     return *this;
//   }

//   ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }

//   ArbitraryModInt operator+(const ArbitraryModInt &p) const {
//     return ArbitraryModInt(*this) += p;
//   }

//   ArbitraryModInt operator-(const ArbitraryModInt &p) const {
//     return ArbitraryModInt(*this) -= p;
//   }

//   ArbitraryModInt operator*(const ArbitraryModInt &p) const {
//     return ArbitraryModInt(*this) *= p;
//   }

//   ArbitraryModInt operator/(const ArbitraryModInt &p) const {
//     return ArbitraryModInt(*this) /= p;
//   }

//   bool operator==(const ArbitraryModInt &p) const { return x == p.x; }

//   bool operator!=(const ArbitraryModInt &p) const { return x != p.x; }

//   ArbitraryModInt inverse() const {
//     int a = x, b = get_mod(), u = 1, v = 0, t;
//     while (b > 0) {
//       t = a / b;
//       swap(a -= t * b, b);
//       swap(u -= t * v, v);
//     }
//     return ArbitraryModInt(u);
//   }

//   ArbitraryModInt pow(int64_t n) const {
//     ArbitraryModInt ret(1), mul(x);
//     while (n > 0) {
//       if (n & 1) ret *= mul;
//       mul *= mul;
//       n >>= 1;
//     }
//     return ret;
//   }

//   friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
//     return os << p.x;
//   }

//   friend istream &operator>>(istream &is, ArbitraryModInt &a) {
//     int64_t t;
//     is >> t;
//     a = ArbitraryModInt(t);
//     return (is);
//   }

//   int get() const { return x; }

//   inline unsigned int rem(unsigned long long p) { return barrett().rem(p); }

//   static inline Barrett &barrett() {
//     static Barrett b;
//     return b;
//   }

//   static inline int &get_mod() {
//     static int mod = 0;
//     return mod;
//   }

//   static void set_mod(int md) {
//     assert(0 < md && md <= (1LL << 30) - 1);
//     get_mod() = md;
//     barrett() = Barrett(md);
//   }
// };

// using mint = ArbitraryModInt;
// typedef vector<mint> vmi; typedef vector<vmi> vvmi; typedef vector<vvmi> v3mi; typedef vector<v3mi> v4mi;


#include <cassert>
#include <numeric>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif


#include <utility>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

struct barrett {
    unsigned int _m;
    unsigned long long im;

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    unsigned int umod() const { return _m; }

    unsigned int mul(unsigned int a, unsigned int b) const {

        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  // namespace internal

}  // namespace atcoder


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt(998244353);

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder

using namespace atcoder;
using mint = modint; using vmi = vector<mint>; using vvmi = vector<vmi>; using v3mi = vector<vvmi>; using v4mi = vector<v3mi>;

const int max_n = (1 << 20) + 1;
mint fact[max_n], factinv[max_n];
void init_f() { fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); } factinv[max_n - 1] = mint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
mint comb(int a, int b) { assert(a < max_n && fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
mint combP(int a, int b) { assert(a < max_n && fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }


void solve() {
  LL(t, u);
  ll MA = 701;
  vmi divn(MA), divn4;
  if (u == 2) {
    LL(m);
    mint::set_mod(m);

    rep(i, MA) {
      vmi dp(i + 1); dp[0] = 1;
      rep(j, 1, i + 1) {
        rep(k, i + 1) {
          if (j + k <= i) dp[k + j] += dp[k];
        }
      }
      divn[i] = dp[i];
    }

    vmi dp(MA), dpt(MA);
    dp[0] = 1;
    rep(_, 4) {
      rep(i, MA) rep(j, MA) {
        if (i + j >= MA) break;
        dpt[i + j] += dp[i] * divn[j];
      }
      dp = dpt;
      dpt.assign(MA, 0);
    }
    divn4 = dp;
  }

  while (t--) {
    LL(n);
    ll mi = LINF;
    vlp ps;
    rep(i, max(1, sqrtll(n).fi - 50), sqrtll(n).fi + 50) {
      ll j = ceil(n, i);
      ll rem = i * j - n;
      if (rem >= i || rem >= j) continue;
      if (chmin(mi, (i + j) * 2)) {
        ps.clear();
        ps.pb({i, j});
      } else if (mi == (i + j) * 2) {
        ps.pb({i, j});
      }
    }
    // debug(ps);

    if (u == 1) {
      auto [h, w] = ps[0];
      vs g(h, string(w, '#'));
      rep(i, h * w - n) {
        g[i][0] = '.';
      }
      OUT(h, w);
      rep(i, h) {
        OUT(g[i]);
      }
    } else {
      mint ans = 0;
      fore(h, w, ps) {
        ll rem = h * w - n;
        ans += divn4[rem];
      }
      OUT(mi, ans.val());
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0); cout << fixed << setprecision(20);
  int t = 1; //cin >> t;
  init_f();
  while (t--) solve();
  // while (t--) compare();
}
