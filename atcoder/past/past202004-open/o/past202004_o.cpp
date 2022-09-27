#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long; using ld = long double; using i128 = __int128_t;
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
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &a) { for(auto &i : a) scan(i); } template <class T> void scan(T &a) { cin >> a; }
void IN() {} template <class Head, class... Tail> void IN(Head &head, Tail &...tail) { scan(head); IN(tail...); }
#define OUTRET(...) { { OUT(__VA_ARGS__); return; } }
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) { return os << p.first << " " << p.second; }
void OUT() { cout << '\n'; } template <typename Head, typename... Tail> void OUT(const Head &head, const Tail &...tail) { cout << head; if(sizeof...(tail)) cout << ' '; OUT(tail...); }
template<typename T> void OUTARRAY(vector<T>& v, int offset = 0, string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset) cout << v[i] + offset; else cout << v[i]; } cout << "\n"; }
template<typename T> void OUTMAT(vector<vector<T>>& v, int offset = 0) { rep(i, v.size()) { OUTARRAY(v[i], offset); } }
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
template<typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template<typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T = ll> T sum_of(const vector<T> &v, int l = 0, int r = INF) { return accumulate(rng_of(v, l, min(r, (int)v.size())), T(0)); }
ll max(int x, ll y) { return max((ll)x, y); } ll max(ll x, int y) { return max(x, (ll)y); }
ll min(int x, ll y) { return min((ll)x, y); } ll min(ll x, int y) { return min(x, (ll)y); }
ll mex(vl& v) { ll n = v.size(); vb S(n + 1); for (auto a: v) if (a <= n) S[a] = 1; ll ret = 0; while (S[ret]) ret++; return ret; }
// 操作系
template<typename T> void uniq(vector<T>&a) { sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a) { vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T, class U> bool chmin(T &a, const U &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T, class U> bool chmax(T &a, const U &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template<class T> vector<T> csum(vector<T> &a) { vl ret(a.size() + 1, 0); rep(i, a.size()) ret[i + 1] = ret[i] + a[i]; return ret; }
template<class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
template <class T, class S> bool incl(const T &x, const S &l, const S &r) { return l <= x and x < r; }
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

//------------------------------------------------------------------------------
struct UnionFind {
  vector<ll> par, s, e;
  UnionFind(ll N) : par(N), s(N), e(N) { rep(i,N) { par[i] = i; s[i] = 1; e[i] = 0; } }
  ll root(ll x) { return par[x]==x ? x : par[x] = root(par[x]); }
  ll size(ll x) { return par[x]==x ? s[x] : s[x] = size(root(x)); }
  ll edge(ll x) { return par[x]==x ? e[x] : e[x] = edge(root(x)); }
  void unite(ll x, ll y) { ll rx=root(x), ry=root(y); if (size(rx)<size(ry)) swap(rx,ry); if (rx!=ry) { s[rx] += s[ry]; par[ry] = rx; e[rx] += e[ry]+1; } else e[rx]++; }
  bool same(ll x, ll y) {  ll rx=root(x), ry=root(y); return rx==ry; }
};
//------------------------------------------------------------------------------

// https://nyaannyaan.github.io/library/tree/heavy-light-decomposition.hpp

template< typename T = ll > struct Edge {
  int from, to; T cost; int idx; Edge() = default; Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; } bool operator<(const struct Edge& other) const { return cost < other.cost; } };
template< typename T = ll > struct Graph {
  vector< vector< Edge< T > > > g; int es; Graph() = default; explicit Graph(int n) : g(n), es(0) {}
  size_t size() const { return g.size(); }
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }
  void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };

template <typename G>
struct HeavyLightDecomposition {
 private:
  void dfs_sz(int cur) {
    size[cur] = 1;
    for (auto& dst : g[cur]) {
      if (dst == par[cur]) { if (g[cur].size() >= 2 && int(dst) == int(g[cur][0])) swap(g[cur][0], g[cur][1]); else continue; }
      depth[dst] = depth[cur] + 1; par[dst] = cur; dfs_sz(dst); size[cur] += size[dst]; if (size[dst] > size[g[cur][0]]) swap(dst, g[cur][0]);
    }
  }
  void dfs_hld(int cur) {
    down[cur] = id++; drev[down[cur]] = cur;
    for (auto dst : g[cur]) { if (dst == par[cur]) continue; nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst)); dfs_hld(dst); }
    up[cur] = id;
  }
  // [u, v)
  vector<pair<int, int>> ascend(int u, int v) const {
    vector<pair<int, int>> res;
    while (nxt[u] != nxt[v]) { res.emplace_back(down[u], down[nxt[u]]); u = par[nxt[u]]; }
    if (u != v) res.emplace_back(down[u], down[v] + 1); return res;
  }
  // (u, v]
  vector<pair<int, int>> descend(int u, int v) const {
    if (u == v) return {};
    if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};
    auto res = descend(u, par[nxt[v]]);
    res.emplace_back(down[nxt[v]], down[v]);
    return res;
  }
 public:
  G& g; int id; vector<int> size, depth, down, drev, up, nxt, par;
  HeavyLightDecomposition(G& _g, int root = 0): g(_g), id(0), size(g.size(), 0), depth(g.size(), 0), down(g.size(), -1), drev(g.size(), -1), up(g.size(), -1), nxt(g.size(), root), par(g.size(), root) { dfs_sz(root); dfs_hld(root); }
  void build(int root) { dfs_sz(root); dfs_hld(root); }
  pair<int, int> idx(int i) const { return make_pair(down[i], up[i]); }
  template <typename F>
  void path_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) { int s = a + 1, t = b; s > t ? f(t, s) : f(s, t); }
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) { int s = a, t = b + 1; s > t ? f(t, s) : f(s, t); }
  }
  template <typename F>
  void path_noncommutative_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) f(a, b + 1);
  }
  template <typename F>
  void subtree_query(int u, bool vertex, const F& f) { f(down[u] + int(!vertex), up[u]); }
  int lca(int a, int b) { while (nxt[a] != nxt[b]) { if (down[a] < down[b]) swap(a, b); a = par[nxt[a]]; } return depth[a] < depth[b] ? a : b; }
  int la(int a, int d) { assert(depth[a] >= d); while (depth[nxt[a]] > d) a = par[nxt[a]]; return drev[down[a] - (depth[a] - d)]; }
  int dist(int a, int b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }
};

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
S op(S l, S r) { return max(l, r); }
S e() { return -LINF; }

void solve() {
  LL(n, m);
  VEC3(ll, a, b, c, m);
  vlt4 ed(m);
  rep(i, m) ed[i] = {c[i], --a[i], --b[i], i};
  sort(all(ed));

  UnionFind uf(n);
  Graph<ll> G(n);
  map<LP, ll> used;

  ll tot = 0;
  rep(i, m) {
    auto [c, a, b, _] = ed[i];
    if (!uf.same(a, b)) {
      uf.unite(a, b);
      G.add_edge(a, b, c);
      used[{a, b}] = c; used[{b, a}] = c;
      tot += c;
    }
  }
  HeavyLightDecomposition<Graph<ll>> hld(G, 0);
  // debug(hld.down);
  vl ans(m, tot);

  segtree<S, op, e> seg(n);
  rep(i, 1, n) {
    ll v = hld.down[i];
    seg.set(v, used[{hld.par[i], i}]);
  }

  rep(i, m) {
    auto [c, a, b, ei] = ed[i];
    ll ma = 0;
    hld.path_query(a, b, false, [&](ll l, ll r) {
      chmax(ma, seg.prod(l, r));
    });
    ans[ei] += c - ma;
  }
  OUTARRAY(ans, 0, "\n");
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0); cout << fixed << setprecision(20);
  int t = 1; // cin >> t;
  while (t--) solve();
  // while (t--) compare();
}
