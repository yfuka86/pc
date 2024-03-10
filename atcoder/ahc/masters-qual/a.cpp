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
namespace SolvingSpace{
using     ll=long long;     using   dd=double;
using    vll=vector<   ll>; using  vdd=vector< dd>;
using   vvll=vector<  vll>; using vvdd=vector<vdd>;
using  vvvll=vector< vvll>; using vvvdd=vector<vvdd>;
using vvvvll=vector<vvvll>;
using   pll=pair<ll,ll>;  using   tll=tuple<ll,ll,ll>; using   qll=tuple<ll,ll,ll,ll>;
using  vpll=vector< pll>; using  vtll=vector< tll>;    using  vqll=vector< qll>;
using vvpll=vector<vpll>; using vvtll=vector<vtll>;    using vvqll=vector<vqll>;
using namespace chrono;
constexpr ll INF = 1001001001001001001;
template<class T> inline ll sz(T &&v){ return (ll)v.size(); }
struct{
	system_clock::time_point st = system_clock::now();
	ll operator()()const{return duration_cast<microseconds>(system_clock::now()-st).count()/1000;}
} timeget;
//pair用テンプレート
template<class T,class S> inline pair<T,S>& operator+=(pair<T,S> &a,const pair<T,S> &b){ a.first+=b.first; a.second+=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator-=(pair<T,S> &a,const pair<T,S> &b){ a.first-=b.first; a.second-=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator*=(pair<T,S> &a,const pair<T,S> &b){ a.first*=b.first; a.second*=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator/=(pair<T,S> &a,const pair<T,S> &b){ a.first/=b.first; a.second/=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator%=(pair<T,S> &a,const pair<T,S> &b){ a.first%=b.first; a.second%=b.second; return a; }
template<class T,class S,class R> inline pair<T,S>& operator+=(pair<T,S> &a,R b){ a.first+=b; a.second+=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator-=(pair<T,S> &a,R b){ a.first-=b; a.second-=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator*=(pair<T,S> &a,R b){ a.first*=b; a.second*=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator/=(pair<T,S> &a,R b){ a.first/=b; a.second/=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator%=(pair<T,S> &a,R b){ a.first%=b; a.second%=b; return a; }
template<class T,class S,class R> inline pair<T,S> operator+(const pair<T,S> &a,R b){ pair<T,S> c=a; return c+=b; }
template<class T,class S,class R> inline pair<T,S> operator-(const pair<T,S> &a,R b){ pair<T,S> c=a; return c-=b; }
template<class T,class S,class R> inline pair<T,S> operator*(const pair<T,S> &a,R b){ pair<T,S> c=a; return c*=b; }
template<class T,class S,class R> inline pair<T,S> operator/(const pair<T,S> &a,R b){ pair<T,S> c=a; return c/=b; }
template<class T,class S,class R> inline pair<T,S> operator%(const pair<T,S> &a,R b){ pair<T,S> c=a; return c%=b; }
template<class T,class S,class R> inline pair<T,S> operator-(R b,const pair<T,S> &a){ pair<T,S> c=-a; return c+=b; }
template<class T,class S> inline pair<T,S> operator-(const pair<T,S> &a,const pair<T,S> &b){ pair<T,S> c=a; return c-=b; }
template<class T,class S> inline pair<T,S> operator-(const pair<T,S> &a){ pair<T,S> c=a; return c*=(-1); }
template<class T,class S> inline ostream &operator<<(ostream &os,const pair<T,S> &a){ return os << a.first << ' ' << a.second; }

struct rndutil{
	using Int = long long;
	mt19937 mt;
	rndutil(Int seed=0):mt((unsigned int)seed){}
	Int val(Int a,Int b){ return mt()%(b-a+1)+a; }//[a,b]の乱数
	dd dval(){ return (dd)mt()/(1ll<<32); }//[0,1)の浮動小数点乱数
	vector<Int> ary(Int n,Int a,Int b){//長さnの配列、要素[a,b]内、重複可
		vector<Int> v(n);
		for (Int i=0;i<n;++i) v[i]=this->val(a,b);
		return v;
	}
	vdd dary(Int n){//長さnの[0,1)の浮動小数点乱数
		vdd v(n);
		for (Int i=0;i<n;++i) v[i]=this->dval();
		return v;
	}
	string str(Int n,char cs,char ce){//長さnのstring、使用文字cs~ce、重複可
		string str(n,cs);
		for (Int i=0;i<n;++i) str[i]+=(char)this->val(0,ce-cs);
		return str;
	}
	vector<Int> sample(Int n,Int a,Int b){//長さnの配列、要素[a,b]内、重複無
		Int len=b-a+1;
		assert(n<=len);
		vector<Int> v(len);
		iota(v.begin(),v.end(),a);
		for (Int i=0;i<n;++i) swap(v[i],v[this->val(i,len-1)]);
		v.resize(n);
		return v;
	}
	template <class T> auto sample(const T &v){//1つ選択
		return v[val(0,(Int)v.size()-1)];
	}
	template <class T> auto samplepop(T &v){//1つ取り出し(末尾swapし削除)
		Int i=val(0,(Int)v.size()-1);
		auto ret=v[i];
		v[i]=v.back();
		v.pop_back();
		return ret;
	}
	Int weightedSampleCore(const vector<Int> &cm){//重み付き乱択 累積和版
		Int randval=val(1,cm.back());
		return Int(lower_bound(cm.begin(),cm.end(),randval)-cm.begin());
	}
	Int weightedSample(const vector<Int> &pr){//重み付き乱択
		vector<Int> cm=pr;
		for (Int i=1;i<(Int)cm.size();++i) cm[i]+=cm[i-1];
		return weightedSampleCore(cm);
	}
	template <class T> void shuffle(T &v){//配列や文字列をシャッフル
		Int n=(Int)v.size();
		for (Int i=0;i<n;++i) swap(v[i],v[this->val(i,n-1)]);
	}
	pair<Int,Int> range(Int a,Int b,Int m=1){ //[a,b]内閉区間長さm以上
		while (true){
			Int l=this->val(a,b+1),r=this->val(a,b+1);
			if (r-l<m)continue;
			return {l,r-1};
		}
	}
	pair<Int,vector<pair<Int,Int>>> graph(Int n){ //単純連結無向グラフ 木に近いものが多め
		while (true){
			vector<pair<Int,Int>> uv;
			UnionFindTree uft(n);
			for (Int v=0;v<n;++v) for (Int u=v+1;u<n;++u){
				if (this->val(1,n*(n-1)/2)>=n)continue;//各辺確率n/Mで採用(M:総辺数n(n-1)/2)
				uv.emplace_back(v,u);
				uft.Unite(v,u);
			}
			if (uft.grpnm()==1) return {(Int)uv.size(),uv};
		}
	}
	vector<pair<Int,Int>> tree(Int n){ //木
		vector<pair<Int,Int>> uv;
		UnionFindTree uft(n);
		while (uft.grpnm()>1){
			Int u=this->val(0,n-1),v=this->val(0,n-1);
			if (uft.Same(u,v)) continue;
			if (u>v)swap(u,v);
			uft.Unite(u,v);
			uv.emplace_back(u,v);
		}
		return uv;
	}
	struct UnionFindTree{
		vector<Int> par,rank,size;
		Int g;
		UnionFindTree(Int num): par(num),rank(num),size(num,1),g(num){
			for (Int i=0;i<num;++i) par[i] = i;
		}
		bool Same(Int x,Int y) { return Root(x) == Root(y); }
		Int Root(Int x) { return (par[x] == x) ? x : par[x]=Root(par[x]); }
		Int Size(Int x){ return size[Root(x)]; }
		Int grpnm() { return g; }
		void Unite(Int x,Int y){
			x = Root(x);
			y = Root(y);
			if (x == y) return;
			if (rank[x] < rank[y]) par[x] = y;
			else                   par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
			size[x] = size[y] = size[x] + size[y];
			g--;
		}
	};
};
rndutil ru;
/*
rndutil ru;
- -------- 整数x -------- 区間[a,b]
ll x=ru.val(a,b);
- -------- 浮動小数点数x -------- [0,1)
dd x=ru.dval();
- -------- 整数ベクトルv -------- 長さn,要素の区間[a,b] 配列重複有
vll v=ru.ary(n,a,b);
- -------- 整数ベクトルv -------- 長さn,要素の区間[a,b] 配列重複無
vll v=ru.sample(n,a,b);
- -------- 浮動小数点ベクトルv -------- 長さn,[0,1)
vdd v=ru.dary(n);
- -------- 文字列s -------- 長さn,使用文字'a'~'z'
string s=ru.str(n,'a','z');
- -------- 乱択 -------- vll,string等から1つ選択
ll   x=ru.sample(v);
char c=ru.sample(s);
- -------- 乱択削除 -------- vll,string等から1つ取り出し(末尾swapし削除)
ll x=ru.samplepop(v);
- -------- 重み付き乱択 -------- i∈{0,1,…,n-1}を重みwiで選択
ll i=ru.weightedSample(w);
ll i=ru.weightedSampleCore(cm);
.                          ↑wの累積和を与えることで高速に
- -------- シャッフル -------- vll,string等
ru.shuffle(a);
- -------- 範囲[l,r] --------  [l,r]⊆[a,b] 区間長1以上
auto[l,r]=ru.range(a,b);
auto[l,r]=ru.range(a,b,m);
.                      ↑区間長m以上
- -------- 木(辺集合uv) --------  頂点数n
vpll uv=ru.tree(n);
- -------- 単純連結無向グラフ(辺集合uv,辺数m) --------  頂点数n
auto[m,uv]=ru.graph(n);
*/

bool wall = false;
void visualize(vector<string> &v, vector<string> &h, vector<vector<int>> &a, int t = 0) {
	using ld = long double;
	const int sz = 40;
	ll n = a.size();
	always(); // 迷路は常に描画する
	noStroke();

	if (!wall) {
		wall = true;
		// 背景を白で描画
		fill("white");
		rect(0, 0, sz * (n + 1), sz * (n + 1));

		noFill();
		stroke("green");

		rep(i, 0, n) {
			line(n * sz, i * sz, n * sz, (i + 1) * sz);
			line(i * sz, n * sz, (i + 1) * sz, n * sz);
		}

		rep(y, 0, n) {
			rep(x, 1, n) {
				if (v[y][x-1] == '1') {
					line(x * sz, y * sz, x * sz, (y + 1) * sz);
				}
			}
		}

		rep(y, 1, n) {
			rep(x, 0, n) {
				if (h[y-1][x] == '1') {
					line(x * sz, y * sz, (x + 1) * sz, y * sz);
				}
			}
		}
	}

	time(t);
	rep(y, 0, n) {
		rep(x, 0, n) {
			int white = 255 - static_cast<int>(255 * ((ld)a[y][x] / n / n));
			fill(255, white, white, 255);        // 密度が高いと赤色を表示する。密度が低いと白色
			square(x * sz + 1, y * sz + 1, sz - 2);    // 正方形を描画

			fill("black");
			text(to_string(a[y][x]), x * sz, (y + 1) * sz);    // 密度の値を最大1000で描画
		}
	}

	noStroke();
}

int error(vector<string> &v, vector<string> &h, vector<vector<int>> &a) {
	int n = (int)a.size();
	int ret = 0;
	rep(i, 0, n) rep(j, 0, n) {
		if (i < n - 1) {
			if (h[i][j] == '0') {
				int d = a[i][j] - a[i + 1][j];
				ret += d * d;
			}
		}
		if (j < n - 1) {
			if (v[i][j] == '0') {
				int d = a[i][j] - a[i][j + 1];
				ret += d * d;
			}
		}
	}
	return ret;
}

/********* グローバル変数(namespace内) *********/
ll t,N;
vector<string> glb_v;
vector<string> glb_h;
vvll glb_a;

vpll glb_orgxy;

/*
dir
　１
０┼２
　３
*/
//            左     上     右    下
pll dxy[4]={{0,-1},{-1,0},{0,1},{1,0},};
inline ll inner(pll a,pll b){ return a.first*b.first+a.second*b.second; }
inline ll norm1(pll v){ return abs(v.first)+abs(v.second); }
inline ll manD(pll v,pll u){ return norm1(v-u); }

bool isRwall(pll xy){
	auto [x,y]=xy;
	return y==N-1 or y==-1 or glb_v[x][y]=='1';
}
bool isLwall(pll xy){ return isRwall({xy.first,xy.second-1}); }
bool isDwall(pll xy){
	auto [x,y]=xy;
	return x==N-1 or x==-1 or glb_h[x][y]=='1';
}
bool isUwall(pll xy){ return isDwall({xy.first-1,xy.second}); }
ll a(pll xy){
	auto [x,y]=xy;
	return glb_a[x][y];
}
bool isWall(pll xy,ll di){
	if      (di==0) return isLwall(xy);
	else if (di==1) return isUwall(xy);
	else if (di==2) return isRwall(xy);
	else if (di==3) return isDwall(xy);
	assert(false);return true;
}

void calcglb_orgxy(){
	glb_orgxy.resize(N*N);
	for (ll x=0;x<N;++x) for (ll y=0;y<N;++y){
		pll xy={x,y};
		glb_orgxy[a(xy)]=xy;
	}
}


/********* アニーリング *********/

struct solution{
	vvll fd;
	ll score=INF;
	solution(vvll &fd_):fd(fd_){}
	ll &Fd(pll xy){ return fd[xy.first][xy.second]; }
	void clearscore(){ score=INF; }
	pll randwalk(ll D,pll xy){ //Dマスランダムウォーク
		pll qxy=xy;
		while(true){
			for (ll i=0;i<D;++i){
				ll di=ru.val(0,3);
				if (isWall(qxy,di)){ i--;continue; }
				qxy+=dxy[di];
			}
			if (xy!=qxy)break;
		}
		return qxy;
	}

	ll Neighborhood1(ll distMxTh){//入替えて差0以下なら入れ替える、悪かったら戻す
		pll oxy,qxy;
		while (true){
			ll x=ru.val(0,N-1);
			ll y=ru.val(0,N-1);
			oxy={x,y};
			ll D=ru.val(1,3);
			qxy=randwalk(D,oxy);
			//ll distMxTh=2;
			ll ova=Fd(oxy);
			ll qva=Fd(qxy);
			pll oOrgxy=glb_orgxy[ova];
			pll qOrgxy=glb_orgxy[qva];
			if (manD(oOrgxy,qxy)>distMxTh) continue;
			break;
		}
		ll orgsc=ScoreTwo(oxy,qxy);
		swap(Fd(oxy),Fd(qxy));//oxyとqxyを入替え
		ll newsc=ScoreTwo(oxy,qxy);
		ll sa=newsc-orgsc;
		if (sa>0){
			swap(Fd(oxy),Fd(qxy));//oxyとqxyを戻す
			sa=0;
		}
		return sa;
	}
	ll ScoreOne(pll xy){
		ll ret=0;
		for (ll di=0;di<4;di++){
			if (isWall(xy,di))continue;
			pll xxyy=xy+dxy[di];
			ll sa=Fd(xy)-Fd(xxyy);
			ret=sa*sa;
		}
		return ret;
	}
	ll ScoreTwo(pll xya,pll xyb){
		ll ret=ScoreOne(xya)+ScoreOne(xyb);
		if (manD(xya,xyb)==1){
			ll sa=Fd(xya)-Fd(xyb);
			ret-=sa*sa;
		}
		return ret;
	}
	ll Score(){
		if (this->score==INF) calcScore();
		return this->score;
	}
	void calcScore(){
		ll sc=0;
		for (ll x=0;x<N;++x) for (ll y=0;y<=N-2;++y){//横
			pll xy={x,y};
			if (isRwall(xy))continue;
			ll d=Fd(xy)-Fd(xy+pll{0,1});
			sc+=d*d;
		}
		for (ll y=0;y<N;++y) for (ll x=0;x<=N-2;++x){//縦
			pll xy={x,y};
			if (isDwall(xy))continue;
			ll d=Fd(xy)-Fd(xy+pll{1,0});
			sc+=d*d;
		}
		this->score=sc;
	}

	vector<vector<int>> output(){
		vector<vector<int>> ret(N,vector<int>(N));
		for(ll x=0;x<N;++x) for(ll y=0;y<N;++y) ret[x][y]=(int)Fd({x,y});
		return ret;
	}
};

solution annealing(ll distMxTh,solution &solini,ll endtime,ll milestone=1000,bool bDump=true)
{
	const dd tmpr0=0.001,tmpr1=0.001; //どの程度悪化しても更新するか saのばらつきを見て決めてみる
	vll prob={1,};//{0,0,0,0,1,1,0,0}; //この比率で各近傍が作成される
	for (ll i=1;i<sz(prob);++i) prob[i]+=prob[i-1];

	ll startTime=timeget(),duration=endtime-startTime;
	dd tmpr=tmpr0;

	solution best=solini, cur=move(solini);

	for (ll iter=0;iter<INF;iter++){
		if (iter>0 and iter%milestone==0) cerr<<iter<<"  "<<timeget()<<"ms\n";
		ll curTime=timeget();
		if (curTime>endtime){ cerr<<"iternum:"<<iter<<'\n'; break; }
		if (iter%10==0){//温度変更
			dd alpha=(curTime-startTime)/(dd)duration;
			tmpr=pow(tmpr0,1-alpha)*pow(tmpr1,alpha);
		}

		solution nxt=cur;
		nxt.clearscore();

		ll sabun=0;
		{//近傍作成処理
			ll rndval=ru.val(0,prob.back()-1);

			if (rndval<prob[0]){
				while (true){
					//bool isok=nxt.Neighborhood1();
					sabun=nxt.Neighborhood1(distMxTh);
					if (sabun<0) break;
					if (curTime>endtime) break;
				}
			}
			else assert(false);
		}
		{//更新
			int sign=-1;//1:大きい方が良い -1:小さい方が良い
			ll sa=(nxt.Score()-cur.Score())*sign;
			//ll sa=sabun*sign;
			if (sa>0. or exp(sa/tmpr)>ru.dval()){
				cur=move(nxt);
				//cur.clearscore();
				if (best.Score()*sign<cur.Score()*sign){
					best=cur;
					if (bDump){
						cerr<<iter<<string(28,' ')<<"bestScore "<<best.Score()<<' ';
						cerr << timeget() <<"ms"<< '\n';
					}
				}
				else if (best.Score()==cur.Score()){
					if (bDump){
						//cerr<< "*\n";
					}
				}
			}
		}
	}
	return best;
}


vector<vector<int>> solve(
	ll t_,ll N_,vector<string> &v_,vector<string> &h_,vvll &a_
){
	t=t_,N=N_,glb_v=v_,glb_h=h_,glb_a=a_;
	calcglb_orgxy();

	ll mode=0; //0:提出 1:デバグ

	solution solini(glb_a);

	ll endtime=500000;
	bool debugdump=true;
	if (mode==0) endtime=1600, debugdump=false;
	//            0 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9
	vll distMxTh(20, 5);
	solution best=annealing(distMxTh[t],solini,endtime,10000,debugdump);

	return best.output();
}

};//SolvingSpace

int N = -1;

bool wall = false;
void visualize(vector<string> &v, vector<string> &h, vector<vector<ll>> &a, int tak, int ao, int t = 0) {
  ll n = a.size();
	const int sz = 1200 / n;
  always(); // 迷路は常に描画する
	noStroke();

	if (!wall) {
		wall = true;
		// 背景を白で描画
		fill("white");
		rect(0, 0, sz * (n + 1), sz * (n + 1));

		noFill();
		stroke("green");

		rep(i, 0, n) {
			line(n * sz, i * sz, n * sz, (i + 1) * sz);
			line(i * sz, n * sz, (i + 1) * sz, n * sz);
		}

		rep(y, 0, n) {
			rep(x, 1, n) {
				if (v[y][x-1] == '1') {
					line(x * sz, y * sz, x * sz, (y + 1) * sz);
				}
			}
		}

		rep(y, 1, n) {
			rep(x, 0, n) {
				if (h[y-1][x] == '1') {
					line(x * sz, y * sz, (x + 1) * sz, y * sz);
				}
			}
		}
	}

	time(t);
	rep(y, 0, n) {
		rep(x, 0, n) {
			int white = 255 - static_cast<int>(100 * ((ld)a[y][x] / n / n));
			fill(255, white, white, 255);		// 密度が高いと赤色を表示する。密度が低いと白色
			square(x * sz + 1, y * sz + 1, sz - 2);	// 正方形を描画

			fill("black");
			text(to_string(a[y][x]), x * sz, (y + 1) * sz);	// 密度の値を最大1000で描画
		}
	}

	fill("red");
	circle(tak % n * sz + sz / 2, tak / n * sz + sz / 2, sz / 2);
	fill("blue");
	circle(ao % n * sz + sz / 2, ao / n * sz + sz / 2, sz / 3);

	noStroke();
}

int error(vector<string> &v, vector<string> &h, vector<vector<int>> &a) {
  int n = a.size();
  int ret = 0;
  rep(i, 0, n) rep(j, 0, n) {
    if (i < n - 1) {
      if (h[i][j] == '0') {
        int d = a[i][j] - a[i + 1][j];
        ret += d * d;
      }
    }
    if (j < n - 1) {
      if (v[i][j] == '0') {
        int d = a[i][j] - a[i][j + 1];
        ret += d * d;
      }
    }
  }
  return ret;
}

vector<vector<ll>> cost, from;
vector<ll> histx, histy;
const string drul = "DRUL"; const vector<ll> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
template <class T, class S, class U> bool incl(const T &x, const S &l, const U &r) { return l <= x and x < r; }
string bfs(vector<string> &v, vector<string> &h, vector<vector<ll>> &a, int x, int y, int nx, int ny) {
	ll n = a.size();
	queue<pair<int, int>> que;
	que.push({x, y});
	histx.pb(x); histy.pb(y);
	cost[x][y] = 0;

	while(!que.empty()) {
		auto [i, j] = que.front(); que.pop();
		bool toend = false;
		rep(d, 0, 4) {
			ll di = i + dx[d];
			ll dj = j + dy[d];
			if (incl(di, 0, N) && incl(dj, 0, N)) {
				// 壁がなくて範囲内
				if ((di != i && h[min(i, di)][j] == '0') || (dj != j && v[i][min(j, dj)] == '0')) {
					if (chmin(cost[di][dj], cost[i][j] + 1)) {
						histx.pb(di); histy.pb(dj);
						from[di][dj] = d;
						que.push({di, dj});
						if (di == nx && dj == ny) toend = true;
					}
				}
			}
		}
		if (toend) break;
	}
	string ret = "";
	while (from[nx][ny] != -1) {
		ll dtmp = from[nx][ny];
		ret.pb(drul[dtmp]);
		nx -= dx[dtmp];
		ny -= dy[dtmp];
	}
	reverse(all(ret));
	while (histx.size()) {
		cost[histx.back()][histy.back()] = LINF;
		from[histx.back()][histy.back()] = -1;
		histx.pop_back(); histy.pop_back();
	}
	return ret;
}

ll bfsmax(vector<string> &v, vector<string> &h, vector<vector<ll>> &a, int x, int y) {
	ll n = a.size();
	vector<vector<ll>> cost(n, vector<ll>(n, LINF));
	queue<pair<int, int>> que;
	que.push({x, y});
	cost[x][y] = 0;

	while(!que.empty()) {
		auto [i, j] = que.front(); que.pop();
		bool toend = false;
		rep(d, 0, 4) {
			ll di = i + dx[d];
			ll dj = j + dy[d];
			if (incl(di, 0, N) && incl(dj, 0, N)) {
				// 壁がなくて範囲内
				if ((di != i && h[min(i, di)][j] == '0') || (dj != j && v[i][min(j, dj)] == '0')) {
					if (chmin(cost[di][dj], cost[i][j] + 1)) {
						que.push({di, dj});
					}
				}
			}
		}
	}
	ll c = 0, ans = -1;
	rep(i, n) rep(j, n) if (chmax(c, cost[i][j])) ans = i * n + j;
	return ans;
}

#include <fstream>
void solve() {
  LL(t); cin >> N;
	ll n = N;
	cost.assign(N, vector<ll>(N, LINF));
	from.assign(N, vector<ll>(N, -1));

  vs v(N); IN(v);
  vs h(N - 1); IN(h);

  vector<vector<ll>> a(N, vector<ll>(N, 0));
	vector<ll> pos(N * N);
  rep(i, N) rep(j, N) {
    cin >> a[i][j];
		a[i][j]--;
		pos[a[i][j]] = i * N + j;
  }
	vector<vector<ll>> original = a;

	// 始点の端を探す
	ll st = bfsmax(v, h, a, 0, 0);
	// ll st = bfsmax(v, h, a, tst / n, tst % n);
	// ll st = 0;

	vector<ll> dfsorder; dfsorder.pb(st);
	{
		vector<bool> vis(N * N); vis[0] = 1;
		function<void(ll)> dfs = [&](ll tak) {
			ll i = tak / n, j = tak % n;
			rep(d, 0, 4) {
				ll di = i + dx[d], dj = j + dy[d];
				if (incl(di, 0, N) && incl(dj, 0, N)) {
					// 壁がなくて範囲内
					if ((di != i && h[min(i, di)][j] == '0') || (dj != j && v[i][min(j, dj)] == '0')) {
						if (!vis[di * N + dj]) {
							vis[di * N + dj] = 1;

							dfsorder.pb(di * N + dj);
							dfs(di * N + dj);
						}
					}
				}
			}
		};
		dfs(st);
	}
	// debug(dfsorder);

	// 答えとしたいもの
	vector<vector<int>> b = SolvingSpace::solve(t, N, v, h, a);
	ll cur1 = st, cur2 = st;
	vector<pair<char, char>> ans;
	set<ll> swapans;
	ll ti = 0;

	rep(i, dfsorder.size()) {
		ll nx1 = dfsorder[i];
		ll nxx = nx1 / n, nxy = nx1 % n;
		ll nx2 = pos[b[nxx][nxy]];
		ll nxx2 = nx2 / n, nxy2 = nx2 % n;

		string tak = bfs(v, h, a, cur1 / n, cur1 % n, nxx, nxy);
		string ao = bfs(v, h, a, cur2 / n, cur2 % n, nxx2, nxy2);
		while (tak.size() < ao.size()) tak.pb('.');
		while (tak.size() > ao.size()) ao.pb('.');

		// debug(cur1, cur2, nx1, nx2, tak, ao);

		rep(ii, tak.size()) { ans.pb({tak[ii], ao[ii]}); }
		swapans.insert(ans.size());

		// スワップの処理と移動の処理
		swap(a[nxx][nxy], a[nxx2][nxy2]);
		pos[a[nxx][nxy]] = nx1;
		pos[a[nxx2][nxy2]] = nx2;
		cur1 = nx1; cur2 = nx2;
	}
	ans.pb({'.', '.'});


	OUT(st / n, st % n, st / n, st % n);
	rep(i, ans.size()) {
		if (i >= n * n * 4 - 1) break;
		OUT(swapans.find(i) != swapans.end() ? 1 : 0, ans[i].fi, ans[i].se);
	}
	// debug(n, ans.size(), (ld)ans.size() / n / n);

	if (0) {
		// ログファイルのパス
		std::string filePath = "log.txt";
		std::ofstream logFile(filePath, std::ios::app);
		// ログファイルにメッセージを追記
		logFile << t << "," << n << "," << ans.size() << "," << (ld)ans.size() / n / n << std::endl;
	}

	if (0){
		// ビジュアライズ
		ll ti = 0, ta = st, ao = st;
		rep(i, ans.size()) {
			if (swapans.find(i) != swapans.end()) swap(original[ta / n][ta % n], original[ao / n][ao % n]);
			rep(d, 4) {
				ll taki = ta / n, takj = ta % n, aoi = ao / n, aoj = ao % n;
				if (ans[i].fi == drul[d]) ta = (taki + dx[d]) * n + takj + dy[d];
				if (ans[i].se == drul[d]) ao = (aoi + dx[d]) * n + aoj + dy[d];
			}
			visualize(v, h, original, ta, ao, ti++);
		}
	}
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout << fixed << setprecision(20);
  int t = 1; //cin >> t;
  while (t--) if (1) solve(); else compare();
}
