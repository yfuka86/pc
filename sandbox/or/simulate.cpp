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

template <class T> std::vector<T> operator+(const std::vector<T> &v1, const std::vector<T> &v2) {
  std::vector<T> ans = v1;
  ans.insert(ans.end(), v2.begin(), v2.end());
  return ans;
}

struct Oripa {
  ll unit_price, unit_count, lose_unit, lose_count, bulk_count;
  ld reward_rate;
  vd top, second, third;
};

// return min/5%/10%/mean/10%/5%/max
vl stats(vl &v) {
  sort(all(v));
  return { v[0], v[v.size() / 20], v[v.size() / 10], v[v.size() / 2], v[v.size() - 1 - (v.size() / 10)], v[v.size() - 1 - (v.size() / 20)], v[v.size() - 1] };
}

void simulate() {
  ll n = 1000;
  ll fixed_budget = -1;

  // ld draw_ratio = 0.3;
  // Oripa o = {
  //   .unit_price = 1000,
  //   .unit_count = 80000,
  //   .lose_unit = 560,
  //   .lose_count = 60000,
  //   .bulk_count = 100,
  //   .reward_rate = 1.0,
  // };
  // o.top = vd({220,120,110,110,105,105,70,70,70,60,60,60,50,50,50,50,50,50,45,40,40});
  // o.second = vd({32,30,28,25,20,18,16,14,13,10,9}) + vd(103,3);

  // ld draw_ratio = 0.8;
  // Oripa o = {
  //   .unit_price = 3333,
  //   .unit_count = 15000,
  //   .lose_unit = 100,
  //   .lose_count = 7500,
  //   .bulk_count = 100,
  //   .reward_rate = 0.97
  // };
  // o.top = vd({160,80});
  // o.second = vd({50,45,40,22,15,15,13,13,10,10,10,10,8,8,8,7,7,6,6,6,5}) + vd(47, 1.5) + vd(515, 1);


  // ld draw_ratio = 0.9;
  // Oripa o = {
  //   .unit_price = 3700,
  //   .unit_count = 10000,
  //   .lose_unit = 120,
  //   .lose_count = 5000,
  //   .bulk_count = 10,
  //   .reward_rate = 0.97
  // };
  // o.top = vd({75,70,60,50,45,40});
  // o.second = vd({22,16,13,10,8,7,6,6,6,6,6,6}) + vd(41,2);

  ld draw_ratio = 0.1;
  Oripa o = {
    .unit_price = 2000,
    .unit_count = 15000,
    .lose_unit = 240,
    .lose_count = 7500,
    .bulk_count = 100,
    .reward_rate = 1.015
  };
  o.top = vd({90,70,55,50,45,45,40,40,40,35});
  o.second = vd({24,20,18,18,12,12,10,10,10,10,10,9,9,9,9,9,9,9,9,9,7,7,7,7,7,7,7,6,5,5,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3}) + vd(65,1.2);

  //////////////////////////////オリパ作成パート//////////////////////////////////

  rep(i, o.top.size()) o.top[i] *= 10000;
  rep(i, o.second.size()) o.second[i] *= 10000;

  ll prize_sum = sum_of(o.top) + sum_of(o.second) + sum_of(o.third);
  ll prize_cnt = o.top.size() + o.second.size() + o.third.size();

  vd oripa = o.top + o.second;
  rep(_, o.lose_count) oripa.pb(o.lose_unit);
  ld rem = (o.unit_price * o.unit_count) * o.reward_rate - prize_sum - (o.lose_count * o.lose_unit);
  ll rem_count = o.unit_count - prize_cnt - o.lose_count;
  ld rem_price = rem / rem_count;
  rep(_, rem_count) oripa.pb(rem_price);
  ll top_min = *min_element(all(o.top));

  ////////////////////////////////////////////////////////////////

  vd budget = {5,10,20,30,40,50,60,70,80,90,100,125,150,175,200,250,300,400,500,1000};
  vd ad = {0.5,0.75,1,2,3,4,5,6,7,8,9,10};
  if (fixed_budget != -1) budget.pb(fixed_budget);

  set<LP> budget_ad;
  fore(b, budget) fore(a, ad) budget_ad.insert({b*10000, a*10000});

  map<LP, ld> win_count, win_tot, lose_count, profit_loss;
  map<LP, vl> mins, losses;

  vl reached_to_top, yet_reached_to_top, top_mins, top_times;

  random_device seed_gen;
  mt19937 engine(seed_gen());
  rep(_, n) {
    shuffle(all(oripa), engine);
    set<LP> bad = budget_ad;
    ll cur = 0;
    ll mi = 0;
    ll to_draw = o.unit_count * draw_ratio;
    bool reached_top = false;

    rep(i, to_draw / o.bulk_count + 1) {
      { // もう次が引けない場合
        auto it = bad.begin();
        while (it != bad.end()) {
          if (cur + it->first < o.unit_price * o.bulk_count) {
            lose_count[*it]++;
            profit_loss[*it] += cur;
            it = bad.erase(it);
          } else {
            it = next(it);
          }
        }
      }

      // 引いて差し引きを把握
      cur -= o.unit_price * (min(o.bulk_count * (i + 1), to_draw) - o.bulk_count * i);
      cur += sum_of(oripa, o.bulk_count * i, min(o.bulk_count * (i + 1), to_draw));
      chmin(mi, cur);

      // XXが出るまで引く戦略
      ll ma = *max_element(oripa.begin() + o.bulk_count * i, oripa.begin() + min(o.bulk_count * (i + 1), to_draw));
      if (!reached_top && ma >= top_min) {
        reached_top = true;
        top_times.pb(i + 1);
        top_mins.pb(mi);
        reached_to_top.pb(cur);
      }

      { // 規定アドに達した場合
        auto it = bad.begin();
        while (it != bad.end()) {
          if (cur >= it->second) {
            win_count[*it]++;
            win_tot[*it] += cur;
            profit_loss[*it] += cur;
            mins[*it].pb(mi);
            it = bad.erase(it);
          } else {
            it = next(it);
          }
        }
      }
    }
    // 最後まで来てしまった場合の計算
    if (!reached_top) yet_reached_to_top.pb(cur);
    fore(b, a, bad) {
      profit_loss[{b, a}] += cur;
      losses[{b, a}].pb(cur);
    }
  }

  fore(_, vec, mins) sort(all(vec));

  OUT("一口", o.unit_price, "円", o.unit_count, "口", o.unit_price * o.unit_count, "円");
  OUT("還元", sum_of(oripa), "円", "残りカード平均", rem_price);
  OUT(to_string((ll)(draw_ratio * 100)) + "%", o.unit_count * draw_ratio, "口まで", o.bulk_count, "口ずつ回す");

  auto print = [&](LP key) {
    ll exp = (ll)profit_loss[key] / n;
    if (win_count[key] == 0) OUT("ロスカ 利確(", key, ") 期待値", exp, "回す意味なし");
    else OUT("予算:利確ライン(", key,
              ") 勝率", win_count[key] / n,
              "勝ave", (ll)win_tot[key] / (ll)win_count[key],
              "dworst/5%/10%/中央", mins[key].front(), "/", mins[key][mins[key].size() / 20], "/", mins[key][mins[key].size() / 10], "/", mins[key][mins[key].size() / 2],
              "ロスカ率", lose_count[key] / n,
              "期待値", (ll)profit_loss[key] / n
            );
  };
  // fore(key, val, profit_loss) {
  //   print(key);
  // }

  map<ll, LP> best_keys;
  fore(key, val, profit_loss) {
    if (best_keys.find(-val) == best_keys.end()) {
      best_keys[-val] = key;
    } else {
      chmin(best_keys[-val], key);
    }
  }

  auto it = best_keys.begin();
  set<ll> used_budget;
  rep(_, 30) {
    print(it->se);
    used_budget.insert(it->se.fi);
    while (it != best_keys.end() && used_budget.find(it->se.fi) != used_budget.end()) {
      it = next(it);
    }
    if (it == best_keys.end()) break;
  }

  vl rt = stats(reached_to_top);
  vl tm = stats(top_mins);
  vl tt = stats(top_times);
  OUT("TOPを引ける確率", (ld)reached_to_top.size() / n, "勝平均", (ld)sum_of(reached_to_top) / reached_to_top.size(), (ld)sum_of(top_times) / reached_to_top.size(), "回", "期待値", ((ld)sum_of(reached_to_top) + (ld)sum_of(yet_reached_to_top)) / n);
  OUT("TOPを引く時の収支min/5%/10%/中央", rt[0], rt[1], rt[2], rt[3]);
  OUT("TOPを引く時の回数min/5%/10%/中央", tt[6], tt[5], tt[4], tt[3]);
  OUT("TOPを引く時のmin/5%/10%/中央", tm[0], tm[1], tm[2], tm[3]);
  OUT("引けなかった時のマイナス平均", (ld)sum_of(yet_reached_to_top) / yet_reached_to_top.size());
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout << fixed << setprecision(3);
  debug(1);
  int t = 1; //cin >> t;
  while (t--) if (1) simulate();
}
