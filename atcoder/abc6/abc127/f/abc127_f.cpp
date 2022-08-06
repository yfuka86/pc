#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define vlin(name,sz,offset) vl name(sz); rep(i,sz){cin>>name[i]; name[i]-=offset;}
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT; typedef tuple<ll, ll, ll, ll> LT4;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> v3l; typedef vector<v3l> v4l; typedef vector<v4l> v5l;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<LT> vlt; typedef vector<vlt> vvlt; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb; typedef vector<vb> vvb;
template<typename T> class infinity{ public: static constexpr T MAX=numeric_limits<T>::max(); static constexpr T MIN=numeric_limits<T>::min(); static constexpr T val=numeric_limits<T>::max()/2-1e6; static constexpr T mval=numeric_limits<T>::min()/2+1e6; };
const int INF = infinity<int>::val; const ll LINF = infinity<ll>::val; const ld DINF = infinity<ld>::val;

struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll l(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  LP lp(ll a, ll b, bool rng = true) { ll x = l(a, b - 1), y = l(rng ? x + 1 : a, b - 1); return {x, y}; }
  vl vecl(ll n, ll a, ll b) { ud d(a, b - 1); vl ret(n); rep(i, n) ret[i] = d(mt); return ret; }
  vl vecperm(ll n, ll from = 0) { vl perm(n); iota(all(perm), from); shuffle(perm); return perm; }
  string str(ll n, string op) { vl fig = vecl(n, 0, op.size()); string s; rep(i, n) s.pb(op[fig[i]]); return s; }
  string straz(ll n, ll a = 0, ll z = 26) { vl az = vecl(n, a, z); string s; rep(i, n) s.pb('a' + az[i]); return s; }
  string strnum(ll n, ll zero = 0, ll ten = 10) { vl zt = vecl(n, zero, ten); string s; rep(i, n) s.pb('0' + zt[i]); return s; }
  void shuffle(vl &a) { std::shuffle(all(a), mt); }
};

#define dout cout
template<typename T, typename=void> struct is_specialize:false_type{};
template<typename T> struct is_specialize<T, typename conditional<false,typename T::iterator, void>::type>:true_type{};
template<typename T> struct is_specialize<T, typename conditional<false,decltype(T::first), void>::type>:true_type{};
template<typename T> struct is_specialize<T, enable_if_t<is_integral<T>::value, void>>:true_type{};
void dump(const char &t) { dout<<t; } void dump(const string &t) { dout<<t; } void dump(const bool &t) { dout<<(t ? "true" : "false"); }
template <typename T, enable_if_t<!is_specialize<T>::value, nullptr_t> =nullptr> void dump(const T&t) { dout<<t; }
template<typename T> void dump(const T&t, enable_if_t<is_integral<T>::value>* =nullptr) { string tmp;if(t==infinity<T>::val||t==infinity<T>::MAX)tmp="inf";if(is_signed<T>::value&&(t==infinity<T>::mval||t==infinity<T>::MIN))tmp="-inf";if(tmp.empty())tmp=to_string(t);dout<<tmp; }
template<typename T,typename U> void dump(const pair<T,U>&);
template<typename T> void dump(const T&t, enable_if_t<!is_void<typename T::iterator>::value>* =nullptr) { dout << "{ "; for(auto it=t.begin();it!=t.end();){ dump(*it); dout << (++it==t.end() ? "" : " "); } dout<<" }"; }
template<typename T,typename U> void dump(const pair<T,U>&t) { dout<<"("; dump(t.first); dout<<" "; dump(t.second); dout << ")"; }
void trace() { dout << "\n"; } template<typename Head, typename... Tail> void trace(Head&&head, Tail&&... tail) { dump(head); if(sizeof...(tail)) dout<<", "; trace(forward<Tail>(tail)...); }
#ifdef ONLINE_JUDGE
#define debug(...) (void(0))
#else
#define debug(...) do {dout<<#__VA_ARGS__<<" = ";trace(__VA_ARGS__); } while(0)
#endif
template<typename T> void coutarray(vector<T>& v, int offset = 0, string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset) cout << v[i] + offset; else cout << v[i]; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v, int offset = 0) { rep(i, v.size()) { coutarray(v[i], offset); } }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<typename Q, typename A> void iquery(initializer_list<Q> q, A &a, string str = "? ") { cout << str; vector<Q> v(q); coutarray(v); cout.flush(); cin >> a; }
// template<typename Q, typename A> void iquery(initializer_list<Q> q, A &a, string str = "? ") { vector<Q> query(q); RandGen rg;
//   a = query[0] ? A() : A();
// }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(__uint128_t x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template<typename T> ll digits(T n) { assert(n >= 0); ll ret = 0; while(n > 0) { ret++; n /= 10; } return ret; }
template<typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template<typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a) { sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a) { vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template<class T> vector<T> csum(vector<T> &a) { vl ret(a.size() + 1, 0); rep(i, a.size()) ret[i + 1] = ret[i] + a[i]; return ret; }
template<class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
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

// 中央値を管理するデータ構造
//   - size()   : O(1)
//   - empty()  : O(1)
//   - insert() : O(log N)
//   - erase()  : O(log N)
//   - get()  : O(1)
//   - query()  : O(1)
template <class T = ll>
struct Median {
  public:
  Median() {}

  // x を追加する
  //   - O(log N)
  void insert(const T& x) {
    if (empty()) { _size = 1; c1 = c2 = x; return; }

    if (_size & 1) {  // 奇数個
      assert(c1 == c2);
      if (x <= c1) {
        _insert_R(c2);
        _insert_L(x);
        c1 = *L.rbegin();
      } else {
        _insert_L(c1);
        _insert_R(x);
        c2 = *R.begin();
      }
    } else {  // 偶数個
      if (x <= c1) {
        _insert_L(x);
        c1 = c2 = *L.rbegin();
        _erase_L(prev(L.end()));
      } else {
        _insert_R(x);
        c1 = c2 = *R.begin();
        _erase_R(R.begin());
      }
    }
    _size++;
  }

  // x を削除して、その成否を返す
  //   - O(log N)
  bool erase(const T& x) {
    if (empty()) { return false; }
    if (_size == 1) { _size = 0; c1 = c2 = 0; return true; }

    if (_size & 1) {  // 奇数個
      assert(c1 == c2);
      if (x < c1) {
        if (not _try_erase_L(x)) { return false; }
        _insert_L(c1);
        c2 = *R.begin();
      } else if (c1 < x) {
        if (not _try_erase_R(x)) { return false; }
        _insert_R(c2);
        c1 = *L.rbegin();
      } else {
        c1 = *L.rbegin();
        c2 = *R.begin();
      }
    } else {  // 偶数個
      if (x <= c1) {
        if (not _try_erase_L(x)) { return false; }
        c1 = c2 = *R.begin();
        _erase_R(R.begin());
      } else if (c2 <= x) {
        if (not _try_erase_R(x)) { return false; }
        c1 = c2 = *L.rbegin();
        _erase_L(prev(L.end()));
      } else {
        return false;
      }
    }
    _size--;
    return true;
  }

  // 中央値を返す
  //   - O(1)
  //   - floor((N+1)/2) 番目に小さい要素を返す
  T get_l() const noexcept { return c1; }

  // 中央値を返す
  //   - O(1)
  //   - ceil((N+1)/2) 番目に小さい要素を返す
  T get_r() const noexcept { return c2; }

  // 「差の絶対値の総和」の最小値を返す
  //  - O(1)
  //  - min{Σ|x - a_i|}
  ll query() const noexcept {
    ll m = get_l();
    ll res = 0;
    res += (ll)L.size() * m - SL;
    res += SR - (ll)R.size() * m;
    return res;
  }

  // 要素数を返す
  //   - O(1)
  int size() const noexcept { return _size; }

  // 要素数が 0 か否かを返す
  //   - O(1)
  bool empty() const noexcept { return (_size == 0); }

  private:
  multiset<T> L, R;
  T c1 = 0, c2 = 0;
  ll SL = 0, SR = 0;
  int _size = 0;

  void _insert_L(const T& x) { SL += x; L.insert(x); }
  void _insert_R(const T& x) { SR += x; R.insert(x); }
  void _erase_L(const class multiset<T>::iterator& it) { SL -= *it; L.erase(it); }
  void _erase_R(const class multiset<T>::iterator& it) { SR -= *it; R.erase(it); }
  bool _try_erase_L(const T& x) {
    auto it = L.find(x);
    if (it == L.end()) { return false; }
    else { _erase_L(it); return true; }
  }
  bool _try_erase_R(const T& x) {
    auto it = R.find(x);
    if (it == R.end()) { return false; }
    else { _erase_R(it); return true; }
  }
};


void solve() {
  ll q; cin >> q;
  Median s;
  ll offset = 0;
  rep(i, q) {
    ll t; cin >> t;
    if (t == 1) {
      ll a, b; cin >> a >> b;
      s.insert(a); offset += b;
    } else {
      ll x = s.get_l();
      ll fx = s.query() + offset;
      cout << x << " " << fx << "\n";
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(15);
  int t = 1; //cin >> t;
  while (t--) solve();
  // while (t--) compare();
}
