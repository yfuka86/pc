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

const ll mod = 1000000007;
//------------------------------------------------------------------------------
template< int mod > struct ModInt {
  int x; ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }  ModInt &operator-=(const ModInt &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  ModInt &operator*=(const ModInt &p) { x = (int) (1LL * x * p.x % mod); return *this; }  ModInt &operator/=(const ModInt &p) { *this *= p.inv(); return *this; }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inv() const { int a = x, b = mod, u = 1, v = 0, t; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } return ModInt(u); }
  ModInt pow(int64_t n) const { ModInt ret(1), mul(x); while(n > 0) { if(n & 1) ret *= mul; mul *= mul; n >>= 1; } return ret; }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
  static constexpr int get_mod() { return mod; }
};
using mint = ModInt< mod >; using vmi = vector<mint>; using vvmi = vector<vmi>; using v3mi = vector<vvmi>; using v4mi = vector<v3mi>;
//------------------------------------------------------------------------------
const int max_n = (1 << 20) + 1;
mint fact[max_n], factinv[max_n];
void init_f() { fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); } factinv[max_n - 1] = mint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
mint comb(int a, int b) { assert(a < max_n && fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
mint combP(int a, int b) { assert(a < max_n && fact[0] != 0); if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, ll p = mod) { ll ret = 1; x %= p; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
ll mod_inv(ll x, ll m) { ll a = x, b = m, u = 1, v = 0, t; while(b) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } if (u < 0) u += m; return u % m; }
//------------------------------------------------------------------------------

vmi fa = {1,641102369,578095319,5832229,259081142,974067448,316220877,690120224,251368199,980250487,682498929,134623568,95936601,933097914,167332441,598816162,336060741,248744620,626497524,288843364,491101308,245341950,565768255,246899319,968999,586350670,638587686,881746146,19426633,850500036,76479948,268124147,842267748,886294336,485348706,463847391,544075857,898187927,798967520,82926604,723816384,156530778,721996174,299085602,323604647,172827403,398699886,530389102,294587621,813805606,67347853,497478507,196447201,722054885,228338256,407719831,762479457,746536789,811667359,778773518,27368307,438371670,59469516,5974669,766196482,606322308,86609485,889750731,340941507,371263376,625544428,788878910,808412394,996952918,585237443,1669644,361786913,480748381,595143852,837229828,199888908,526807168,579691190,145404005,459188207,534491822,439729802,840398449,899297830,235861787,888050723,656116726,736550105,440902696,85990869,884343068,56305184,973478770,168891766,804805577,927880474,876297919,934814019,676405347,567277637,112249297,44930135,39417871,47401357,108819476,281863274,60168088,692636218,432775082,14235602,770511792,400295761,697066277,421835306,220108638,661224977,261799937,168203998,802214249,544064410,935080803,583967898,211768084,751231582,972424306,623534362,335160196,243276029,554749550,60050552,797848181,395891998,172428290,159554990,887420150,970055531,250388809,487998999,856259313,82104855,232253360,513365505,244109365,1559745,695345956,261384175,849009131,323214113,747664143,444090941,659224434,80729842,570033864,664989237,827348878,195888993,576798521,457882808,731551699,212938473,509096183,827544702,678320208,677711203,289752035,66404266,555972231,195290384,97136305,349551356,785113347,83489485,66247239,52167191,307390891,547665832,143066173,350016754,917404120,296269301,996122673,23015220,602139210,748566338,187348575,109838563,574053420,105574531,304173654,542432219,34538816,325636655,437843114,630621321,26853683,933245637,616368450,238971581,511371690,557301633,911398531,848952161,958992544,925152039,914456118,724691727,636817583,238087006,946237212,910291942,114985663,492237273,450387329,834860913,763017204,368925948,475812562,740594930,45060610,806047532,464456846,172115341,75307702,116261993,562519302,268838846,173784895,243624360,61570384,481661251,938269070,95182730,91068149,115435332,495022305,136026497,506496856,710729672,113570024,366384665,564758715,270239666,277118392,79874094,702807165,112390913,730341625,103056890,677948390,339464594,167240465,108312174,839079953,479334442,271788964,135498044,277717575,591048681,811637561,353339603,889410460,839849206,192345193,736265527,316439118,217544623,788132977,618898635,183011467,380858207,996097969,898554793,335353644,54062950,611251733,419363534,965429853,160398980,151319402,990918946,607730875,450718279,173539388,648991369,970937898,500780548,780122909,39052406,276894233,460373282,651081062,461415770,358700839,643638805,560006119,668123525,686692315,673464765,957633609,199866123,563432246,841799766,385330357,504962686,954061253,128487469,685707545,299172297,717975101,577786541,318951960,773206631,306832604,204355779,573592106,30977140,450398100,363172638,258379324,472935553,93940075,587220627,776264326,793270300,291733496,522049725,579995261,335416359,142946099,472012302,559947225,332139472,499377092,464599136,164752359,309058615,86117128,580204973,563781682,954840109,624577416,895609896,888287558,836813268,926036911,386027524,184419613,724205533,403351886,715247054,716986954,830567832,383388563,68409439,6734065,189239124,68322490,943653305,405755338,811056092,179518046,825132993,343807435,985084650,868553027,148528617,160684257,882148737,591915968,701445829,529726489,302177126,974886682,241107368,798830099,940567523,11633075,325334066,346091869,115312728,473718967,218129285,878471898,180002392,699739374,917084264,856859395,435327356,808651347,421623838,105419548,59883031,322487421,79716267,715317963,429277690,398078032,316486674,384843585,940338439,937409008,940524812,947549662,833550543,593524514,996164327,987314628,697611981,636177449,274192146,418537348,925347821,952831975,893732627,1277567,358655417,141866945,581830879,987597705,347046911,775305697,125354499,951540811,247662371,343043237,568392357,997474832,209244402,380480118,149586983,392838702,309134554,990779998,263053337,325362513,780072518,551028176,990826116,989944961,155569943,596737944,711553356,268844715,451373308,379404150,462639908,961812918,654611901,382776490,41815820,843321396,675258797,845583555,934281721,741114145,275105629,666247477,325912072,526131620,252551589,432030917,554917439,818036959,754363835,795190182,909210595,278704903,719566487,628514947,424989675,321685608,50590510,832069712,198768464,702004730,99199382,707469729,747407118,302020341,497196934,5003231,726997875,382617671,296229203,183888367,703397904,552133875,732868367,350095207,26031303,863250534,216665960,561745549,352946234,784139777,733333339,503105966,459878625,803187381,16634739,180898306,68718097,985594252,404206040,749724532,97830135,611751357,31131935,662741752,864326453,864869025,167831173,559214642,718498895,91352335,608823837,473379392,385388084,152267158,681756977,46819124,313132653,56547945,442795120,796616594,256141983,152028387,636578562,385377759,553033642,491415383,919273670,996049638,326686486,160150665,141827977,540818053,693305776,593938674,186576440,688809790,565456578,749296077,519397500,551096742,696628828,775025061,370732451,164246193,915265013,457469634,923043932,912368644,777901604,464118005,637939935,956856710,490676632,453019482,462528877,502297454,798895521,100498586,699767918,849974789,811575797,438952959,606870929,907720182,179111720,48053248,508038818,811944661,752550134,401382061,848924691,764368449,34629406,529840945,435904287,26011548,208184231,446477394,206330671,366033520,131772368,185646898,648711554,472759660,523696723,271198437,25058942,859369491,817928963,330711333,724464507,437605233,701453022,626663115,281230685,510650790,596949867,295726547,303076380,465070856,272814771,538771609,48824684,951279549,939889684,564188856,48527183,201307702,484458461,861754542,326159309,181594759,668422905,286273596,965656187,44135644,359960756,936229527,407934361,267193060,456152084,459116722,124804049,262322489,920251227,816929577,483924582,151834896,167087470,490222511,903466878,361583925,368114731,339383292,388728584,218107212,249153339,909458706,322908524,202649964,92255682,573074791,15570863,94331513,744158074,196345098,334326205,9416035,98349682,882121662,769795511,231988936,888146074,137603545,582627184,407518072,919419361,909433461,986708498,310317874,373745190,263645931,256853930,876379959,702823274,147050765,308186532,175504139,180350107,797736554,606241871,384547635,273712630,586444655,682189174,666493603,946867127,819114541,502371023,261970285,825871994,126925175,701506133,314738056,341779962,561011609,815463367,46765164,49187570,188054995,957939114,64814326,933376898,329837066,338121343,765215899,869630152,978119194,632627667,975266085,435887178,282092463,129621197,758245605,827722926,201339230,918513230,322096036,547838438,985546115,852304035,593090119,689189630,555842733,567033437,469928208,212842957,117842065,404149413,155133422,663307737,208761293,206282795,717946122,488906585,414236650,280700600,962670136,534279149,214569244,375297772,811053196,922377372,289594327,219932130,211487466,701050258,398782410,863002719,27236531,217598709,375472836,810551911,178598958,247844667,676526196,812283640,863066876,857241854,113917835,624148346,726089763,564827277,826300950,478982047,439411911,454039189,633292726,48562889,802100365,671734977,945204804,508831870,398781902,897162044,644050694,892168027,828883117,277714559,713448377,624500515,590098114,808691930,514359662,895205045,715264908,628829100,484492064,919717789,513196123,748510389,403652653,574455974,77123823,172096141,819801784,581418893,15655126,15391652,875641535,203191898,264582598,880691101,907800444,986598821,340030191,264688936,369832433,785804644,842065079,423951674,663560047,696623384,496709826,161960209,331910086,541120825,951524114,841656666,162683802,629786193,190395535,269571439,832671304,76770272,341080135,421943723,494210290,751040886,317076664,672850561,72482816,493689107,135625240,100228913,684748812,639655136,906233141,929893103,277813439,814362881,562608724,406024012,885537778,10065330,60625018,983737173,60517502,551060742,804930491,823845496,727416538,946421040,678171399,842203531,175638827,894247956,538609927,885362182,946464959,116667533,749816133,241427979,871117927,281804989,163928347,563796647,640266394,774625892,59342705,256473217,674115061,918860977,322633051,753513874,393556719,304644842,767372800,161362528,754787150,627655552,677395736,799289297,846650652,816701166,687265514,787113234,358757251,701220427,607715125,245795606,600624983,10475577,728620948,759404319,36292292,491466901,22556579,114495791,647630109,586445753,482254337,718623833,763514207,66547751,953634340,351472920,308474522,494166907,634359666,172114298,865440961,364380585,921648059,965683742,260466949,117483873,962540888,237120480,620531822,193781724,213092254,107141741,602742426,793307102,756154604,236455213,362928234,14162538,753042874,778983779,25977209,49389215,698308420,859637374,49031023,713258160,737331920,923333660,804861409,83868974,682873215,217298111,883278906,176966527,954913,105359006,390019735,10430738,706334445,315103615,567473423,708233401,48160594,946149627,346966053,281329488,462880311,31503476,185438078,965785236,992656683,916291845,881482632,899946391,321900901,512634493,303338827,121000338,967284733,492741665,152233223,165393390,680128316,917041303,532702135,741626808,496442755,536841269,131384366,377329025,301196854,859917803,676511002,373451745,847645126,823495900,576368335,73146164,954958912,847549272,241289571,646654592,216046746,205951465,3258987,780882948,822439091,598245292,869544707,698611116};

void solve() {
  init_f();
  LL(n);
  VL(x, n);
  ll sum = sum_of(x);

  auto calc_fact = [&](ll y) {
    if (y <= 1000000) return fact[y];
    else {
      mint ret = fa[y / 1000000];
      rep(i, y / 1000000 * 1000000 + 1, y + 1) ret *= i;
      return ret;
    }
  };

  mint free = mint(1) / sum / (sum - 1);
  // debug(al);

  mint ans = sum;
  // debug(ans);
  rep(i, n) {
    if (x[i] < 2) continue;
    // 2個の選び方 * 隣合う回数
    ans -= mint(x[i]) * (x[i] - 1) * (sum - 1) * free;
  }

  OUT(ans);

  // mint f = 1;
  // vmi ar;
  // rep(i, 1, 1000000001) {
  //   f *= i;
  //   if (i % 1000000 == 0) ar.pb(f);
  // }
  // debug(ar);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout << fixed << setprecision(20);
  int t = 1; // cin >> t;
  while (t--) if (1) solve(); else compare();
}
