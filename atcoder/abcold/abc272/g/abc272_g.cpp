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
#define _rep0(n) for(ll i = 0; (ll)(i) < n; ++i)
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
template<typename T, enable_if_t<!is_specialize<T>::value, nullptr_t> =nullptr> void dump(const T&t) { dout << t; }
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
template<typename T> void OUTARRAY(vector<T>& v, T offset = T(0), string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset != T(0)) { T t; t = v[i] + offset; cout << t; } else cout << v[i]; } cout << "\n"; }
template<typename T> void OUTMAT(vector<vector<T>>& v, T offset = T(0)) { rep(i, v.size()) { OUTARRAY(v[i], offset); } }
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
vl divisor(ll n) { vl ret; for (ll i = 1; i * i <= n; i++) { if (n % i == 0) { ret.pb(i); if (i * i != n) ret.pb(n / i); } } sort(all(ret)); return ret; }
template<typename T> vl digits(T n) { assert(n >= 0); vl ret; while(n > 0) { ret.pb(n % 10); n /= 10; } return ret; }
template<class T, enable_if_t<is_integral<T>::value, nullptr_t> = nullptr> int msb(T x){ if (sizeof(x) == 4) return 31 - __builtin_clz(x); else return 63 - __builtin_clzll(x); }
template<class T, enable_if_t<is_integral<T>::value, nullptr_t> = nullptr> int lsb(T x){ if (sizeof(x) == 4) return __builtin_ctz(x); else return __builtin_ctzll(x); }
template<typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template<typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T = ll> T sum_of(const vector<T> &v, int l = 0, int r = INF) { return accumulate(rng_of(v, l, min(r, (int)v.size())), T(0)); }
ll max(int x, ll y) { return max((ll)x, y); } ll max(ll x, int y) { return max(x, (ll)y); }
ll min(int x, ll y) { return min((ll)x, y); } ll min(ll x, int y) { return min(x, (ll)y); }
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
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template<class T> vector<T> csum(vector<T> &a) { vl ret(a.size() + 1, 0); rep(i, a.size()) ret[i + 1] = ret[i] + a[i]; return ret; }
template<class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
template <class T, class S, class U> bool incl(const T &x, const S &l, const U &r) { return l <= x and x < r; }
void change_bit(ll &x, int b, int i) { assert(b < 63); if (!!(x & 1ll << b) ^ i) x ^= 1ll << b;  }
bool is_palindrome(string s) { rep(i, (s.size() + 1) / 2) if (s[i] != s[s.size() - 1 - i]) { return false; } return true; }
const string drul = "DRUL"; vl dx = {1, 0, -1, 0}; vl dy = {0, 1, 0, -1};

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

// https://nyaannyaan.github.io/library/inner/inner_math.hpp
namespace inner {
  using i32 = int32_t; using u32 = uint32_t; using i64 = int64_t; using u64 = uint64_t;
  template <typename T> T gcd(T a, T b) { while (b) swap(a %= b, b); return a; }
  template <typename T> T inv(T a, T p) { T b = p, x = 1, y = 0; while (a) { T q = b / a; swap(a, b %= a); swap(x, y -= q * x); } assert(b == 1); return y < 0 ? y + p : y; }
  template <typename T, typename U>
  T modpow(T a, U n, T p) { T ret = 1 % p; for (; n; n >>= 1, a = U(a) * a % p) if (n & 1) ret = U(ret) * a % p; return ret; }
}  // namespace inner

// https://nyaannyaan.github.io/library/misc/rng.hpp
namespace my_rand {
  // [0, 2^64 - 1)
  uint64_t rng() {
    static uint64_t x_ = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()) * 10150724397891781847ULL;
    x_ ^= x_ << 7; return x_ ^= x_ >> 9; }
  // [l, r)
  int64_t randint(int64_t l, int64_t r) { assert(l < r); return l + rng() % (r - l); }
  // choose n numbers from [l, r) without overlapping
  vector<int64_t> randset(int64_t l, int64_t r, int64_t n) { assert(l <= r && n <= r - l);
    unordered_set<int64_t> s; for (int64_t i = n; i; --i) { int64_t m = randint(l, r + 1 - i); if (s.find(m) != s.end()) m = r - i; s.insert(m); }
    vector<int64_t> ret; for (auto& x : s) ret.push_back(x); return ret; }
  // [0.0, 1.0)
  double rnd() { union raw_cast { double t; uint64_t u; }; constexpr uint64_t p = uint64_t(1023 - 64) << 52; return rng() * ((raw_cast*)(&p))->t; }
  template <typename T> void randshf(vector<T>& v) { int n = v.size(); for (int loop = 0; loop < 2; loop++) for (int i = 0; i < n; i++) swap(v[i], v[randint(0, n)]); }
}  // namespace my_rand
using my_rand::randint;
using my_rand::randset;
using my_rand::randshf;
using my_rand::rnd;
using my_rand::rng;

// https://nyaannyaan.github.io/library/modint/arbitrary-prime-modint.hpp
struct ArbitraryLazyMontgomeryModInt {
  using mint = ArbitraryLazyMontgomeryModInt; using i32 = int32_t; using u32 = uint32_t; using u64 = uint64_t;
  static u32 mod; static u32 r; static u32 n2;
  static u32 get_r() { u32 ret = mod; for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret; return ret; }
  static void set_mod(u32 m) { assert(m < (1 << 30)); assert((m & 1) == 1); mod = m; n2 = -u64(m) % m; r = get_r(); assert(r * mod == 1); }
  u32 a;
  ArbitraryLazyMontgomeryModInt() : a(0) {}
  ArbitraryLazyMontgomeryModInt(const int64_t &b): a(reduce(u64(b % mod + mod) * n2)){};
  static u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r)) * mod) >> 32; }
  mint &operator+=(const mint &b) { if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod; return *this; }
  mint &operator-=(const mint &b) { if (i32(a -= b.a) < 0) a += 2 * mod; return *this; }
  mint &operator*=(const mint &b) { a = reduce(u64(a) * b.a); return *this; }
  mint &operator/=(const mint &b) { *this *= b.inverse(); return *this; }
  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }
  bool operator==(const mint &b) const { return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a); }
  bool operator!=(const mint &b) const { return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a); }
  mint operator-() const { return mint() - mint(*this); }
  mint pow(u64 n) const { mint ret(1), mul(*this); while (n > 0) { if (n & 1) ret *= mul; mul *= mul; n >>= 1; } return ret; }
  friend ostream &operator<<(ostream &os, const mint &b) { return os << b.get(); }
  friend istream &operator>>(istream &is, mint &b) { int64_t t; is >> t; b = ArbitraryLazyMontgomeryModInt(t); return (is); }
  mint inverse() const { return pow(mod - 2); }
  u32 get() const { u32 ret = reduce(a); return ret >= mod ? ret - mod : ret; }
  static u32 get_mod() { return mod; }
};
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::mod;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::r;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::n2;

// https://nyaannyaan.github.io/library/modint/modint-montgomery64.hpp
struct montgomery64 {
  using mint = montgomery64; using i64 = int64_t; using u64 = uint64_t; using u128 = __uint128_t;
  static u64 mod; static u64 r; static u64 n2;
  static u64 get_r() { u64 ret = mod; for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret; return ret; }
  static void set_mod(u64 m) { assert(m < (1LL << 62)); assert((m & 1) == 1); mod = m; n2 = -u128(m) % m; r = get_r(); assert(r * mod == 1); }
  u64 a;
  montgomery64() : a(0) {}
  montgomery64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};
  static u64 reduce(const u128 &b) { return (b + u128(u64(b) * u64(-r)) * mod) >> 64; }
  mint &operator+=(const mint &b) { if (i64(a += b.a - 2 * mod) < 0) a += 2 * mod; return *this; }
  mint &operator-=(const mint &b) { if (i64(a -= b.a) < 0) a += 2 * mod; return *this; }
  mint &operator*=(const mint &b) { a = reduce(u128(a) * b.a); return *this; }
  mint &operator/=(const mint &b) { *this *= b.inverse(); return *this; }
  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }
  bool operator==(const mint &b) const { return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a); }
  bool operator!=(const mint &b) const { return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a); }
  mint operator-() const { return mint() - mint(*this); }
  mint pow(u128 n) const { mint ret(1), mul(*this); while (n > 0) { if (n & 1) ret *= mul; mul *= mul; n >>= 1; } return ret; }
  friend ostream &operator<<(ostream &os, const mint &b) { return os << b.get(); }
  friend istream &operator>>(istream &is, mint &b) { int64_t t; is >> t; b = montgomery64(t); return (is); }
  mint inverse() const { return pow(mod - 2); }
  u64 get() const { u64 ret = reduce(a); return ret >= mod ? ret - mod : ret; }
  static u64 get_mod() { return mod; }
};
typename montgomery64::u64 montgomery64::mod, montgomery64::r, montgomery64::n2;

// https://nyaannyaan.github.io/library/prime/fast-factorize.hpp
namespace fast_factorize {
using u64 = uint64_t;
template <typename mint>
bool miller_rabin(u64 n, vector<u64> as) {
  if (mint::get_mod() != n) mint::set_mod(n);
  u64 d = n - 1;
  while (~d & 1) d >>= 1;
  mint e{1}, rev{int64_t(n - 1)};
  for (u64 a : as) {
    if (n <= a) break;
    u64 t = d;
    mint y = mint(a).pow(t);
    while (t != n - 1 && y != e && y != rev) {
      y *= y;
      t *= 2;
    }
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool is_prime(u64 n) {
  if (~n & 1) return n == 2;
  if (n <= 1) return false;
  if (n < (1LL << 30))
    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n, {2, 7, 61});
  else
    return miller_rabin<montgomery64>(
        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

template <typename mint, typename T>
T pollard_rho(T n) {
  if (~n & 1) return 2;
  if (is_prime(n)) return n;
  if (mint::get_mod() != n) mint::set_mod(n);
  mint R, one = 1;
  auto f = [&](mint x) { return x * x + R; };
  auto rnd_ = [&]() { return rng() % (n - 2) + 2; };
  while (1) {
    mint x, y, ys, q = one;
    R = rnd_(), y = rnd_();
    T g = 1;
    constexpr int m = 128;
    for (int r = 1; g == 1; r <<= 1) {
      x = y;
      for (int i = 0; i < r; ++i) y = f(y);
      for (int k = 0; g == 1 && k < r; k += m) {
        ys = y;
        for (int i = 0; i < m && i < r - k; ++i) q *= x - (y = f(y));
        g = inner::gcd<T>(q.get(), n);
      }
    }
    if (g == n) do
        g = inner::gcd<T>((x - (ys = f(ys))).get(), n);
      while (g == 1);
    if (g != n) return g;
  }
  exit(1);
}

using i64 = long long;

vector<i64> inner_factorize(u64 n) {
  if (n <= 1) return {};
  u64 p;
  if (n <= (1LL << 30))
    p = pollard_rho<ArbitraryLazyMontgomeryModInt, uint32_t>(n);
  else
    p = pollard_rho<montgomery64, uint64_t>(n);
  if (p == n) return {i64(p)};
  auto l = inner_factorize(p);
  auto r = inner_factorize(n / p);
  copy(begin(r), end(r), back_inserter(l));
  return l;
}

vector<i64> factorize(u64 n) {
  auto ret = inner_factorize(n);
  sort(begin(ret), end(ret));
  return ret;
}

map<i64, i64> factor_count(u64 n) {
  map<i64, i64> mp;
  for (auto &x : factorize(n)) mp[x]++;
  return mp;
}

vector<i64> divisors(u64 n) {
  if (n == 0) return {};
  vector<pair<i64, i64>> v;
  for (auto &p : factorize(n)) {
    if (v.empty() || v.back().first != p) {
      v.emplace_back(p, 1);
    } else {
      v.back().second++;
    }
  }
  vector<i64> ret;
  auto f = [&](auto rc, int i, i64 x) -> void {
    if (i == (int)v.size()) {
      ret.push_back(x);
      return;
    }
    for (int j = v[i].second;; --j) {
      rc(rc, i + 1, x);
      if (j == 0) break;
      x *= v[i].first;
    }
  };
  f(f, 0, 1);
  sort(begin(ret), end(ret));
  return ret;
}

}  // namespace fast_factorize

using fast_factorize::divisors;
using fast_factorize::factor_count;
using fast_factorize::factorize;
using fast_factorize::is_prime;

//-------------------------------------------------------
// https://atcoder.jp/contests/abc238/submissions/29086825
// https://cp-algorithms.com/algebra/prime-sieve-linear.html
struct PrimeSieve {
  int n; vector<bool> is_prime; vector<int> pr, mu, pf;
  // pr := primes, mu := moebius, pf[i] := smallest prime p s.t. p | i
  PrimeSieve(int _n){
    n = ++_n; is_prime.assign(n, true); mu.assign(n, 0); pf.assign(n, 0);
    is_prime[0] = is_prime[1] = false; mu[1] = 1;
    for (int i = 2; i < n; i++) {
      if (is_prime[i]) { pr.emplace_back(i); pf[i] = i; mu[i] = -1; }
      for (int p : pr) {
        if (ll(i) * p >= n) break;
        is_prime[i * p] = false; mu[i * p] = -mu[i]; pf[i * p] = p;
        if (i % p == 0) { mu[i * p] = 0; break; }
      }
    }
  }
  vector<pair<int, int>> factorize(int x) { assert(x < n); vector<pair<int, int>> res;
    while (pf[x] > 1) { int d = pf[x], c = 0; while (x % d == 0) { x /= d; c++; } res.emplace_back(d, c); }
    if (x != 1) res.emplace_back(x, 1); return res;
  }
  // not sorted [1..x]
  vector<int> divisors(int x) { assert(x < n); auto f = factorize(x); vector<int> res = { 1 };
    for (auto [p, c] : f) {
      vector<int> powp; powp.emplace_back(p); rep(i, c - 1) powp.emplace_back(powp.back() * p);
      for (int i = res.size() - 1; i >= 0; --i) for (int j = 0; j < c; ++j) res.emplace_back(res[i] * powp[j]);
    }
    // res.erase(res.begin()); [2..x]
    return res;
  }
};


void solve() {
  LL(n); VL(a, n);
  sort(all(a));

  // rep(i, n) a[i] %= 3;
  // debug(a);

  ll half = n / 2;
  RandGen rg;

  ll cnt = 100;
  while (cnt--) {
    ll i = rg.l(0, n), j = i; while (j == i) j = rg.l(0, n);

    vl cand = factorize(abs(a[i] - a[j]));
    cand.pb(4); uniq(cand);

    fore(p, cand) {
      if (p <= 2) continue;
      unordered_map<ll, ll> cnt;
      rep(k, n) {
        cnt[a[k] % p]++;
        if (cnt[a[k] % p] > half) OUTRET(p);
      }
    }
  }

  OUT(-1);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0); cout << fixed << setprecision(20);
  int t = 1; // cin >> t;
  while (t--) solve();
  // while (t--) compare();
}
