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
#define YES(ok) { if (ok) { OUT("YES"); } else OUT("NO"); }
#define Yes(ok) { if (ok) { OUT("Yes"); } else OUT("No"); }
ostream &operator<<(ostream &os, const i128 n) { os << (ll)n; return os; } // long longの範囲までしか出力しない
template<class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) { return os << p.first << " " << p.second; }
void OUT() { cout << '\n'; } template <typename Head, typename... Tail> void OUT(Head &&head, Tail &&...tail) { cout << head; if(sizeof...(tail)) cout << ' '; OUT(tail...); }
template<class T, class S = ll> void OUTARRAY(vector<T>& v, S offset = S(0), string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset != T(0)) { T t; t = v[i] + offset; cout << t; } else cout << v[i]; } cout << "\n"; }
template<class T, class S = ll> void OUTMAT(vector<vector<T>>& v, S offset = S(0)) { rep(i, v.size()) { OUTARRAY(v[i], offset); } }
template<typename T> void OUTBIN(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<typename Q, typename A> void IQUERY(initializer_list<Q> q, A &a, string str = "? ") { cout << str; vector<Q> v(q); OUTARRAY(v); cout.flush(); cin >> a; }
// template<typename Q, typename A> void IQUERY(initializer_list<Q> q, A &a, string str = "? ") { vector<Q> query(q); RandGen rg;
//   a = query[0] ? A() : A();
// }
template<typename A> void IANSWER(vector<A> a, string str = "! ") { cout << str; OUTARRAY(a); cout.flush(); } template<typename A> void IANSWER(initializer_list<A> a, string str = "! ") { vector<A> v(a); IANSWER(v, str); }
template<typename A, typename R> void IANSWER(vector<A> a, R &r, string str = "! ") { IANSWER(a, str); cin >> r; } template<typename A, typename R> void IANSWER(initializer_list<A> a, R &r, string str = "! ") { IANSWER(a, str); cin >> r; }

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
  void read_tree(int off = 1) { for(int i = 0; i < size() - 1; i++) { ll u, v; cin >> u >> v; u-=off; v-=off; add_edge(u, v); } }
  void read_treep(int off = 1) { for(int i = 0; i < size() - 1; i++) { ll p; cin >> p; p-=off; add_edge(i+1, p); } }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };
const string drul = "DRUL"; const vl dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

using namespace std;

//----------- p5visualizerのマクロ Version 1.1（ここから） -------------
#define VISUALIZE // 提出時にはここをコメントアウトすること。そうしないとTLEする。

#ifdef VISUALIZE
std::ofstream sVisStream("VisCommands.txt");

// ビジュアライザ上で表示される時間を指定します
inline void time(int t) {
	sVisStream << "time = " << t << ";" << std::endl;
}

// ビジュアライザ上で常に表示されます
inline void always() {
	time(-1);
}

inline void setSingleColor(int colorOrGray, int alpha = 255) {
	sVisStream << colorOrGray;
	if (alpha < 255) {
		sVisStream << ", " << alpha;
	}
}

inline void setRGBColor(int r, int g, int b, int alpha = 255) {
	sVisStream << r << ", " << g << ", " << b;
	if (alpha < 255) {
		sVisStream << ", " << alpha;
	}
}

// リファレンス https://p5js.org/reference/
// Web上のエディタ https://editor.p5js.org/


//---------- Shape : 2D Primitives ----------
inline void arc(float x, float y, float w, float h, float start, float stop) {
	sVisStream << "arc(" << x << ", " << y << ", " << w << ", " << h << ", " << start << ", " << stop << ");" << std::endl;
}

inline void ellipse(float x, float y, float w, float h) {
	sVisStream << "ellipse(" << x << ", " << y << ", " << w << ", " << h << ");" << std::endl;
}

inline void circle(float x, float y, float d) {
	sVisStream << "circle(" << x << ", " << y << ", " << d << ");" << std::endl;
}

inline void line(float x1, float y1, float x2, float y2) {
	sVisStream << "line(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ");" << std::endl;
}

inline void point(float x, float y) {
	sVisStream << "point(" << x << ", " << y << ");" << std::endl;
}

inline void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	sVisStream << "quad(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << x3 << ", " << y3 << ", " << x4 << ", " << y4 << ");" << std::endl;
}

inline void rect(float x, float y, float w, float h) {
	sVisStream << "rect(" << x << ", " << y << ", " << w << ", " << h << ");" << std::endl;
}

inline void square(float x, float y, float s) {
	sVisStream << "square(" << x << ", " << y << ", " << s << ");" << std::endl;
}

inline void triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
	sVisStream << "triangle(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << x3 << ", " << y3 << ");" << std::endl;
}

//---------- Shape : Attributes ----------
inline void ellipseMode(const std::string& mode) {
	sVisStream << "ellipseMode(" << mode << ");" << std::endl;
}

inline void noSmooth() {
	sVisStream << "noSmooth();" << std::endl;
}

inline void rectMode(const std::string& mode) {
	sVisStream << "rectMode(" << mode << ");" << std::endl;
}

inline void smooth() {
	sVisStream << "smooth();" << std::endl;
}

inline void strokeCap(const std::string& cap) {
	sVisStream << "strokeCap(" << cap << ");" << std::endl;
}

inline void strokeJoin(const std::string& join) {
	sVisStream << "strokeJoin(" << join << ");" << std::endl;
}

inline void strokeWeight(float weight) {
	sVisStream << "strokeWeight(" << weight << ");" << std::endl;
}

//---------- Shape : Curves ----------
inline void bezier(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	sVisStream << "bezier(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", "
		<< x3 << ", " << y3 << ", " << x4 << ", " << y4 << ");" << std::endl;
}

inline void bezierDetail(int detail) {
	sVisStream << "bezierDetail(" << detail << ");" << std::endl;
}

inline void bezierPoint(float a, float b, float c, float d, float t) {
	sVisStream << "bezierPoint(" << a << ", " << b << ", " << c << ", " << d << ", " << t << ");" << std::endl;
}

inline void bezierTangent(float a, float b, float c, float d, float t) {
	sVisStream << "bezierTangent(" << a << ", " << b << ", " << c << ", " << d << ", " << t << ");" << std::endl;
}

inline void curve(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	sVisStream << "curve(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", "
		<< x3 << ", " << y3 << ", " << x4 << ", " << y4 << ");" << std::endl;
}

inline void curveDetail(int detail) {
	sVisStream << "curveDetail(" << detail << ");" << std::endl;
}

inline void curveTightness(float tightness) {
	sVisStream << "curveTightness(" << tightness << ");" << std::endl;
}

inline void curvePoint(float a, float b, float c, float d, float t) {
	sVisStream << "curvePoint(" << a << ", " << b << ", " << c << ", " << d << ", " << t << ");" << std::endl;
}

inline void curveTangent(float a, float b, float c, float d, float t) {
	sVisStream << "curveTangent(" << a << ", " << b << ", " << c << ", " << d << ", " << t << ");" << std::endl;
}

//---------- Shape : Vertex ----------
inline void beginContour() {
	sVisStream << "beginContour();" << std::endl;
}

inline void beginShape(const std::string& mode = "") {
	if (!mode.empty()) {
		sVisStream << "beginShape(\"" << mode << "\");" << std::endl;
	} else {
		sVisStream << "beginShape();" << std::endl;
	}
}

inline void bezierVertex(float x1, float y1, float x2, float y2, float x3, float y3) {
	sVisStream << "bezierVertex(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << x3 << ", " << y3 << ");" << std::endl;
}

inline void curveVertex(float x, float y) {
	sVisStream << "curveVertex(" << x << ", " << y << ");" << std::endl;
}

inline void endContour() {
	sVisStream << "endContour();" << std::endl;
}

inline void endShape(const std::string& mode = "") {
	if (!mode.empty()) {
		sVisStream << "endShape(\"" << mode << "\");" << std::endl;
	} else {
		sVisStream << "endShape();" << std::endl;
	}
}

inline void quadraticVertex(float cx, float cy, float x, float y) {
	sVisStream << "quadraticVertex(" << cx << ", " << cy << ", " << x << ", " << y << ");" << std::endl;
}

inline void vertex(float x, float y) {
	sVisStream << "vertex(" << x << ", " << y << ");" << std::endl;
}

//---------- Color : Setting ----------
inline void background(int gray, int alpha = 255) {
	sVisStream << "background(";
	setSingleColor(gray, alpha);
	sVisStream << ");" << std::endl;
}

inline void background(int r, int g, int b, int alpha = 255) {
	sVisStream << "background(";
	setRGBColor(r, g, b, alpha);
	sVisStream << ");" << std::endl;
}

inline void background(const std::string& value) {
	sVisStream << "background(\"" << value << "\");" << std::endl;
}

inline void clear() {
	sVisStream << "clear();" << std::endl;
}

inline void colorMode(const std::string& mode, int max1, int max2, int max3, int maxA) {
	sVisStream << "colorMode(" << mode << ", " << max1 << ", " << max2 << ", " << max3 << ", " << maxA << ");" << std::endl;
}

inline void fill(int gray, int alpha = 255) {
	sVisStream << "fill(";
	setSingleColor(gray, alpha);
	sVisStream << ");" << std::endl;
}

inline void fill(int r, int g, int b, int alpha = 255) {
	sVisStream << "fill(";
	setRGBColor(r, g, b, alpha);
	sVisStream << ");" << std::endl;
}

inline void fill(const std::string& value) {
	sVisStream << "fill(\"" << value << "\");" << std::endl;
}

inline void noFill() {
	sVisStream << "noFill();" << std::endl;
}

inline void noStroke() {
	sVisStream << "noStroke();" << std::endl;
}

inline void stroke(int gray, int alpha = 255) {
	sVisStream << "stroke(";
	setSingleColor(gray, alpha);
	sVisStream << ");" << std::endl;
}

inline void stroke(int r, int g, int b, int alpha = 255) {
	sVisStream << "stroke(";
	setRGBColor(r, g, b, alpha);
	sVisStream << ");" << std::endl;
}

inline void stroke(const std::string& value) {
	sVisStream << "stroke(\"" << value << "\");" << std::endl;
}

inline void erase() {
	sVisStream << "erase();" << std::endl;
}

inline void noErase() {
	sVisStream << "noErase();" << std::endl;
}

//---------- Structure ----------
inline void push() {
	sVisStream << "push();" << std::endl;
}

inline void pop() {
	sVisStream << "pop();" << std::endl;
}

//---------- Typography ----------
inline void textAlign(const std::string& alignX, const std::string& alignY = "") {
	if (alignY.empty()) {
		sVisStream << "textAlign(" << alignX << ");" << std::endl;
	} else {
		sVisStream << "textAlign(" << alignX << ", " << alignY << ");" << std::endl;
	}
}

inline void textLeading(float leading) {
	sVisStream << "textLeading(" << leading << ");" << std::endl;
}

inline void textSize(float size) {
	sVisStream << "textSize(" << size << ");" << std::endl;
}

inline void textStyle(const std::string& style) {
	sVisStream << "textStyle(" << style << ");" << std::endl;
}

inline void textAscent() {
	sVisStream << "textAscent();" << std::endl;
}

inline void textDescent() {
	sVisStream << "textDescent();" << std::endl;
}

inline void textWrap(const std::string& wrap) {
	sVisStream << "textWrap(\"" << wrap << "\");" << std::endl;
}

inline void text(const std::string& str, float x, float y) {
	sVisStream << "text(\"" << str << "\", " << x << ", " << y << ");" << std::endl;
}

inline void textFont(const std::string& fontName) {
	sVisStream << "textFont(\"" << fontName << "\");" << std::endl;
}

#else //  VISUALIZE

inline void time(int t) {}
inline void always() {}
inline void setSingleColor(int, int = 255) {}
inline void setRGBColor(int, int, int, int = 255) {}

//---------- Shape : 2D Primitives ----------
inline void arc(float, float, float, float, float, float) {}
inline void ellipse(float, float, float, float) {}
inline void circle(float, float, float) {}
inline void line(float, float, float, float) {}
inline void point(float, float) {}
inline void quad(float, float, float, float, float, float, float, float) {}
inline void rect(float, float, float, float) {}
inline void square(float, float, float) {}
inline void triangle(float, float, float, float, float, float) {}

//---------- Shape : Attributes ----------
inline void ellipseMode(const std::string&) {}
inline void noSmooth() {}
inline void rectMode(const std::string&) {}
inline void smooth() {}
inline void strokeCap(const std::string&) {}
inline void strokeJoin(const std::string&) {}
inline void strokeWeight(float) {}

//---------- Shape : Curves ----------
inline void bezier(float, float, float, float, float, float, float, float) {}
inline void bezierDetail(int) {}
inline void bezierPoint(float, float, float, float, float) {}
inline void bezierTangent(float, float, float, float, float) {}
inline void curve(float, float, float, float, float, float, float, float) {}
inline void curveDetail(int) {}
inline void curveTightness(float) {}
inline void curvePoint(float, float, float, float, float) {}
inline void curveTangent(float, float, float, float, float) {}

//---------- Shape : Vertex ----------
inline void beginContour() {}
inline void beginShape(const std::string & = "") {}
inline void bezierVertex(float, float, float, float, float, float) {}
inline void curveVertex(float, float) {}
inline void endContour() {}
inline void endShape(const std::string & = "") {}
inline void quadraticVertex(float, float, float, float) {}
inline void vertex(float, float) {}

//---------- Color : Setting ----------
inline void background(int, int = 255) {}
inline void background(int, int, int, int = 255) {}
inline void background(const std::string&) {}
inline void clear() {}
inline void colorMode(const std::string&, int, int, int, int = 0) {}
inline void fill(int, int = 255) {}
inline void fill(int, int, int, int = 255) {}
inline void fill(const std::string&) {}
inline void noFill() {}
inline void noStroke() {}
inline void stroke(int, int = 255) {}
inline void stroke(int, int, int, int = 255) {}
inline void stroke(const std::string&) {}
inline void erase() {}
inline void noErase() {}

//---------- Structure ----------
inline void push() {}
inline void pop() {}

//---------- Typography ----------
inline void textAlign(const std::string&, const std::string & = "") {}
inline void textLeading(float) {}
inline void textSize(float) {}
inline void textStyle(const std::string&) {}
inline void textAscent() {}
inline void textDescent() {}
inline void textWrap(const std::string&) {}
inline void text(const std::string&, float, float) {}
inline void textFont(const std::string&) {}
#endif // VISUALIZE

//----------- p5visualizerのマクロ（ここまで） -------------


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

void solve() {
  // LL(n);
  always(); // 迷路は常に描画する
	noStroke();

	// 背景を白で描画
	fill("white");
	rect(0, 0, 100, 100);

	noFill();
	stroke("green");
  line(0, 0, 100, 100);	// 横方向の壁を線で描画

	noStroke();
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout << fixed << setprecision(20);
  int t = 1; //cin >> t;
  while (t--) if (1) solve(); else compare();
}
