
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

// ----------------------------------------------------------------------
template<typename T>
struct BIT {
  int n; vector<T> bit;
  BIT(int _n = 0) : n(_n), bit(n + 1) {}
  // sum of [0, i), 0 <= i <= n
  T sum(int i) { T s = 0; while (i > 0) { s += bit[i]; i -= i & -i; } return s;}
  // 0 <= i < n
  void add(int i, T x) { ++i; while (i <= n) { bit[i] += x; i += i & -i; } }
  //[l, r) 0 <= l < r < n
  T sum(int l, int r) { return sum(r) - sum(l); }
  // smallest i, sum(i) >= w, none -> n
  int lower_bound(T w) {
    if (w <= 0) return 0; int x = 0, l = 1; while (l * 2 <= n) l <<= 1;
    for (int k = l; k > 0; k /= 2) if (x + k <= n && bit[x + k] < w) { w -= bit[x + k]; x += k; }
    return x; }
};
// ----------------------------------------------------------------------
ll inv_num(vl& v) {
  BIT<int> bs(v.size()); ll ans = 0;
  rep(i, v.size()) { ans += i - bs.sum(v[i]); bs.add(v[i], 1); } return ans; }
// ----------------------------------------------------------------------

// ll solve(ll n, ll k, vl a) {
//   vl t = a; sort(all(t));
//   ll cnt = 0;
//   debug(inv_num(a));

//   ll loop = 0;
//   while (a != t) {
//     loop++;
//     BIT<ll> bt(n);
//     priority_queue<LP> inv;

//     ll cur = 0;
//     rep(i, k) { cur += i - bt.sum(a[i]); bt.add(a[i], 1); }
//     rep2(i, k, n) {
//       inv.push({cur, i - k});
//       cur -= bt.sum(a[i - k]);
//       bt.add(a[i - k], -1);
//       cur += k - 1 - bt.sum(a[i]);
//       bt.add(a[i], 1);
//     }
//     inv.push({cur, n - k});

//     BIT<ll> rngbt(n);
//     while(!inv.empty()) {
//       auto [cur, idx] = inv.top(); inv.pop();
//       // debug(cur, idx);
//       if (cur > 0 && rngbt.sum(idx, idx + k) == 0) {
//         sort(a.begin() + idx, a.begin() + idx + k);
//         // debug(idx, a);
//         cnt++;
//         rngbt.add(idx, 1);
//         rngbt.add(idx + k - 1, 1);
//       }
//     }
//     debug(a);
//   }
//   debug(loop);
//   return cnt;
// }

ll solve(ll n, ll k, vl a) {
  vl t = a; sort(all(t));
  ll cnt = 0;
  debug(inv_num(a));

  ll loop = 0;
  while (a != t) {
    loop++;
    vl idx(n), diff(n);
    rep(i, n) idx[a[i]] = i;
    rep(i, n) diff[i] = i - a[i];
    debug(diff);

    priority_queue<LP> inv;
    ll sum = 0;
    set<ll> S;
    rep(i, n) {
      sum += abs(a[i] - idx[a[i]]);
      S.insert(a[i]);
      if (i >= k) { sum -= abs(a[i - k] - idx[a[i - k]]); S.erase(a[i - k]); }
      // 集計
      if (i >= k - 1) {
        ll cur = i - k + 1, nsum = 0;
        for (auto s: S) {
          nsum += abs(cur - s);
          cur++;
        }
        inv.push({sum - nsum, i - k + 1});
      }
    }

    BIT<ll> rngbt(n);
    while(!inv.empty()) {
      auto [cur, idx] = inv.top(); inv.pop();
      if (cur > 0 && rngbt.sum(idx, idx + k) == 0) {
        sort(a.begin() + idx, a.begin() + idx + k);
        cnt++;
        rngbt.add(idx, 1);
        rngbt.add(idx + k - 1, 1);
      }
    }
    debug(a);
  }

  debug(loop);
  return cnt;
}

ll naive(ll n, ll k, vl a) {
  vl sorted = a;
  sort(all(sorted));
  map<vl, ll> mp;
  mp[sorted] = 0;

  vl t = sorted;
  do {
    rep(i, n - k + 1) {
      vl tt = t;
      sort(tt.begin() + i, tt.begin() + i + k);
      if (tt >= t) continue;
      if (mp.find(t) == mp.end()) mp[t] = mp[tt] + 1;
      else chmin(mp[t], mp[tt] + 1);
    }
  } while (next_permutation(all(t)));
  return mp[a];
}

void compare(bool check = true) { RandGen rg; ll c = 0, loop = 10;
  while (++c) { if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll n = 7;
    ll k = 4;
    vl a = rg.vecperm(n);
    auto so = solve(n, k, a); auto na = naive(n, k, a);
    if (!check || na != so) { cout << c << "times tried" << "\n";
      debug(n, a); debug(so); debug(na);
    if (check || (!check && c > loop)) break; }
  }
}

void solve() {
  ll n; cin >> n;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(15);
  int t = 1; //cin >> t;
  // while (t--) solve();
  while (t--) compare();
}
