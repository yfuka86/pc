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

ll n, m, center;
vvl g;
vector<set<ll>> ex, ey, edx, edy;

vvl ans;
set<vl> cands;

ll score() {
  ld ret = (ld)1e6 * n * n / m;
  ll s = 0, w = 0;
  ll c = center;
  rep(i, n) rep(j, n) {
    ll t = (i - c) * (i - c) + (j - c) * (j - c) + 1;
    s += t;
    if (g[i][j]) w += t;
  }
  return round(ret * w / s);
}
LP tr(ll x, ll y) {
  return mp(x + y, x - y + n - 1);
}
LP rt(ll x, ll y) {
  y -= n - 1;
  ll dx = (x + y) / 2, dy = (x - y) / 2;
  if (incl(dx, 0ll, n) && incl(dy, 0ll, n)) return mp(dx, dy);
  else return mp(-1, -1);
}
ll dg(ll x, ll y) {
  auto p = rt(x, y);
  if (p.fi == -1) return false;
  else return g[p.fi][p.se];
}

struct Cand;
vector<Cand> enum_cand(ll x, ll y);
vector<Cand> enum_dcand(ll x, ll y);
list<pair<vl, Cand>> que;
ll inv_count();

struct Cand {
  ll t, x1, y1, x2, y2, nx, ny;
  Cand(ll t, ll x1, ll y1, ll x2, ll y2, ll nx, ll ny): t(t), x1(x1), y1(y1), x2(x2), y2(y2), nx(nx), ny(ny) { }
  Cand(vl v) : t(v[0]), x1(v[1]), y1(v[2]), x2(v[3]), y2(v[4]), nx(v[5]), ny(v[6]) { }
  vl attr() { return {t, x1, y1, x2, y2, nx, ny}; }
  ll edgesize() const {
    ll e = abs(x2 - x1) * 2 + abs(y2 - y1) * 2;
    return t ? e / 2 : e;
  }
  ll score() const {
    auto p = rt(nx, ny);
    ll dx = (t ? p.fi : nx), dy = (t ? p.se : ny);
    dx -= center;
    dy -= center;
    return dx * dx + dy * dy + 1;
  }
  LP dscore() {
    if (!valid()) return mp(0, LINF);

    addtemp();
    LP p = t ? rt(nx, ny) : mp(nx, ny);
    LP trp = t ? mp(nx, ny) : tr(nx, ny);
    ll cnt = 1;
    fore(c, enum_cand(p.fi, p.se)) {
      if (cands.find(c.attr()) == cands.end()) { cnt++; break; }
    }
    fore(c, enum_dcand(trp.fi, trp.se)) {
      if (cands.find(c.attr()) == cands.end()) { cnt++; break; }
    }
    ll inv = inv_count();
    removetemp();
    return mp(cnt, inv);
  }
  vl sortattr() {
    auto [cnt, inv] = this->dscore();
    ll a = cnt * 100 / (inv + 1);
    ll sc = this->score(), esz = this->edgesize();
    return {-a * (10000 * sc / (esz * esz * esz * esz))};
  }
  bool valid() {
    if (t == 0) {
      if (g[nx][ny] == 1) return false;
      rep(i, x1 + 1, x2) if (g[i][y1] || g[i][y2]) return false;
      rep(j, y1 + 1, y2) if (g[x1][j] || g[x2][j]) return false;
      if (ex[x1].lower_bound(y1) != ex[x1].lower_bound(y2)) return false;
      if (ex[x2].lower_bound(y1) != ex[x2].lower_bound(y2)) return false;
      if (ey[y1].lower_bound(x1) != ey[y1].lower_bound(x2)) return false;
      if (ey[y2].lower_bound(x1) != ey[y2].lower_bound(x2)) return false;
    } else {
      if (rt(x1, y1).fi == -1 || rt(x2, y2).fi == -1 || rt(x1, y2).fi == -1 || rt(x2, y1).fi == -1 || rt(nx, ny).fi == -1) return false;
      if (dg(nx, ny) == 1) return false;
      rep(i, x1 + 2, x2) if (dg(i, y1) || dg(i, y2)) return false;
      rep(j, y1 + 2, y2) if (dg(x1, j) || dg(x2, j)) return false;
      if (edx[x1].lower_bound(y1) != edx[x1].lower_bound(y2)) return false;
      if (edx[x2].lower_bound(y1) != edx[x2].lower_bound(y2)) return false;
      if (edy[y1].lower_bound(x1) != edy[y1].lower_bound(x2)) return false;
      if (edy[y2].lower_bound(x1) != edy[y2].lower_bound(x2)) return false;
    }
    return true;
  }
  void add() {
    assert(valid());
    addtemp();
    if (t == 0) {
      ans.pb({nx, ny, nx ^ x1 ^ x2, ny, nx ^ x1 ^ x2, ny ^ y1 ^ y2, nx, ny ^ y1 ^ y2});
    } else {
      auto p1 = rt(nx, ny);
      auto p2 = rt(nx ^ x1 ^ x2, ny);
      auto p3 = rt(nx ^ x1 ^ x2, ny ^ y1 ^ y2);
      auto p4 = rt(nx, ny ^ y1 ^ y2);
      ans.pb({p1.fi, p1.se, p2.fi, p2.se, p3.fi, p3.se, p4.fi, p4.se});
    }
  }
  void addtemp() {
    assert(valid());
    if (t == 0) {
      g[nx][ny] = 1;
      rep(j, y1, y2) { ex[x1].insert(j); ex[x2].insert(j); }
      rep(i, x1, x2) { ey[y1].insert(i); ey[y2].insert(i); }
    } else {
      auto [xx, yy] = rt(nx, ny);
      g[xx][yy] = 1;
      rep(j, y1, y2, 2) { edx[x1].insert(j); edx[x2].insert(j); }
      rep(i, x1, x2, 2) { edy[y1].insert(i); edy[y2].insert(i); }
    }
  }
  void removetemp() {
    if (t == 0) {
      g[nx][ny] = 0;
      rep(j, y1, y2) { ex[x1].erase(j); ex[x2].erase(j); }
      rep(i, x1, x2) { ey[y1].erase(i); ey[y2].erase(i); }
    } else {
      auto [xx, yy] = rt(nx, ny);
      g[xx][yy] = 0;
      rep(j, y1, y2, 2) { edx[x1].erase(j); edx[x2].erase(j); }
      rep(i, x1, x2, 2) { edy[y1].erase(i); edy[y2].erase(i); }
    }
  }
  bool operator<(const struct Cand& other) const {
    return this->edgesize() > other.edgesize();
  }
};
ostream &operator<<(ostream &os, const Cand &c) {
  return os << "{" << c.x1 << "," << c.y1 << "," << c.x2 << "," << c.y2 << "}";
}

ll inv_count() {
  ll ret = 0;
  fore(s, c, que) { if (!c.valid()) ret++; }
  return ret;
}

vector<Cand> candx(ll x, ll y1, ll y2) {
  vector<Cand> t;
  ll i = x, a = y1, b = y2;
  rep_r(k, i) {
    if (g[k][a] && g[k][b]) break;
    if (g[k][a]) { t.pb(Cand(0, k, a, i, b, k, b)); break; }
    if (g[k][b]) { t.pb(Cand(0, k, a, i, b, k, a)); break; }
  }
  rep(k, i + 1, n) {
    if (g[k][a] && g[k][b]) break;
    if (g[k][a]) { t.pb(Cand(0, i, a, k, b, k, b)); break; }
    if (g[k][b]) { t.pb(Cand(0, i, a, k, b, k, a)); break; }
  }
  return t;
}
vector<Cand> candy(ll x1, ll x2, ll y) {
  vector<Cand> t;
  ll i = y, a = x1, b = x2;
  rep_r(k, i) {
    if (g[a][k] && g[b][k]) break;
    if (g[a][k]) { t.pb(Cand(0, a, k, b, i, b, k)); break; }
    if (g[b][k]) { t.pb(Cand(0, a, k, b, i, a, k)); break; }
  }
  rep(k, i + 1, n) {
    if (g[a][k] && g[b][k]) break;
    if (g[a][k]) { t.pb(Cand(0, a, i, b, k, b, k)); break; }
    if (g[b][k]) { t.pb(Cand(0, a, i, b, k, a, k)); break; }
  }
  return t;
}
vector<Cand> enum_cand(ll x, ll y) {
  // assert(g[x][y]);

  vector<Cand> t, ret;
  rep_r(i, y) if (g[x][i]) { fore(c, candx(x, i, y)) t.pb(c); break; }
  rep(i, y + 1, n) if (g[x][i]) { fore(c, candx(x, y, i)) t.pb(c); break; }
  rep_r(i, x) if (g[i][y]) { fore(c, candy(i, x, y)) t.pb(c); break; }
  rep(i, x + 1, n) if (g[i][y]) { fore(c, candy(x, i, y)) t.pb(c); break; }
  fore(c, t) if (c.valid()) ret.pb(c);
  return ret;
}

vector<Cand> dcandx(ll x, ll y1, ll y2) {
  assert(!((y1 - y2) & 1));
  vector<Cand> t;
  ll i = x, a = y1, b = y2;

  ll xroom = min(abs(y1 - (n - 1)), abs(y2 - (n - 1)));
  ll xl = xroom, xr = n * 2 - 1 - xroom;

  rep_r(k, xl, x - 1, 2) {
    if (dg(k, a) && dg(k, b)) break;
    if (dg(k, a)) { t.pb(Cand(1, k, a, i, b, k, b)); break; }
    if (dg(k, b)) { t.pb(Cand(1, k, a, i, b, k, a)); break; }
  }
  rep(k, x + 2, xr, 2) {
    if (dg(k, a) && dg(k, b)) break;
    if (dg(k, a)) { t.pb(Cand(1, i, a, k, b, k, b)); break; }
    if (dg(k, b)) { t.pb(Cand(1, i, a, k, b, k, a)); break; }
  }
  return t;
}
vector<Cand> dcandy(ll x1, ll x2, ll y) {
  assert(!((x1 - x2) & 1));
  vector<Cand> t;
  ll i = y, a = x1, b = x2;

  ll yroom = min(abs((x1 - (n - 1))), abs((x2 - (n - 1))));
  ll yl = yroom, yr = n * 2 - 1 - yroom;

  rep_r(k, yl, y - 1, 2) {
    if (dg(a, k) && dg(b, k)) break;
    if (dg(a, k)) { t.pb(Cand(1, a, k, b, i, b, k)); break; }
    if (dg(b, k)) { t.pb(Cand(1, a, k, b, i, a, k)); break; }
  }
  rep(k, y + 2, yr, 2) {
    if (dg(a, k) && dg(b, k)) break;
    if (dg(a, k)) { t.pb(Cand(1, a, i, b, k, b, k)); break; }
    if (dg(b, k)) { t.pb(Cand(1, a, i, b, k, a, k)); break; }
  }
  return t;
}
vector<Cand> enum_dcand(ll tx, ll ty) {
  vector<Cand> t, ret;
  auto [x, y] = rt(tx, ty);
  // assert(g[x][y]);

  ll xroom = abs(ty - (n - 1));
  ll xl = xroom, xr = n * 2 - 1 - xroom;
  ll yroom = abs(tx - (n - 1));
  ll yl = yroom, yr = n * 2 - 1 - yroom;

  rep_r(i, yl, ty - 1, 2) if (dg(tx, i)) { fore(c, dcandx(tx, i, ty)) t.pb(c); break; }
  rep(i, ty + 2, yr, 2) if (dg(tx, i)) { fore(c, dcandx(tx, ty, i)) t.pb(c); break; }
  rep_r(i, xl, tx - 1, 2) if (dg(i, ty)) { fore(c, dcandy(i, tx, ty)) t.pb(c); break; }
  rep(i, tx + 2, xr, 2) if (dg(i, ty)) { fore(c, dcandy(tx, i, ty)) t.pb(c); break; }

  fore(c, t) if (c.valid()) ret.pb(c);
  return ret;
}

ll solve(bool toans = true) {
  cin >> n >> m;
  VEC2(ll, x, y, m);

  ///////////////////////////////////
  // RandGen rg;
  // n = rg.l(15, 31) * 2 + 1, m = rg.l(n, n * n / 12 + 1);
  // vl x(m), y(m);
  // {
  //   set<LP> s;
  //   while (s.size() < m) s.insert({rg.l(n / 4, 3 * n / 4 + 1), rg.l(n / 4, 3 * n / 4 + 1)});
  //   ll cur = 0; fore(a, b, s) { x[cur] = a; y[cur] = b; cur++; }
  // }
  ///////////////////////////////////

  center = (n - 1) / 2;
  ex.clear(); ey.clear(); edx.clear(); edy.clear(); ans.clear(); cands.clear();
  g.assign(n, vl(n)); ex.resize(n); ey.resize(n); edx.resize(n * 2 - 1); edy.resize(n * 2 - 1);
  rep(i, m) g[x[i]][y[i]] = 1;

  auto cpush = [&](Cand c) {
    cands.insert(c.attr());
    que.pb(mp(c.sortattr(), c));
  };

  rep(i, n) rep(j, n) {
    if (g[i][j]) {
      fore(c, enum_cand(i, j)) cpush(c);
      auto [x, y] = tr(i, j);
      fore(c, enum_dcand(x, y)) cpush(c);
    }
  }

  while(!que.empty()) {
    que.sort();
    auto [d, c] = que.front(); que.pop_front();
    if (c.valid()) {
      c.add();
      ll cnt = 0;
      for (auto it = que.begin(); it != que.end(); ) {
        cnt++;
        auto &[d, c] = *it;
        if (!c.valid()) it = que.erase(it);
        else {
          if (cnt <= 100000 / que.size()) it->fi = c.sortattr(); // スコア更新入れるとさすがにTLEする
          it++;
        }
      }
      LP p = c.t ? rt(c.nx, c.ny) : mp(c.nx, c.ny);
      LP trp = c.t ? mp(c.nx, c.ny) : tr(c.nx, c.ny);
      // if (p.fi == -1) { debug(c.nx, c.ny); continue; }
      fore(c, enum_cand(p.fi, p.se)) cpush(c);
      fore(c, enum_dcand(trp.fi, trp.se)) cpush(c);
    }
  }

  if (toans) {
    OUT(ans.size());
    rep(i, ans.size()) OUTARRAY(ans[i]);
  }

  // debug(ans.size(), score());
  return score();
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0); cout << fixed << setprecision(20);
  int t = 1; // cin >> t;
  while (t--) solve();

  // ll sum = 0;
  // rep(_, 50) sum += solve(false);
  // debug(sum);
}
