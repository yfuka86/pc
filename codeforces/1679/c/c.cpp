#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define vlin(name,sz) vl name(sz); rep(i,sz) cin>>name[i];
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT3; typedef tuple<ll, ll, ll> LT4;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll l(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  vl vecl(ll l, ll a, ll b) { ud d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vecperm(ll l) { vl perm(l); iota(all(perm), 1); random_shuffle(all(perm)); return perm; }
  string straz(ll l, ll a = 0, ll z = 26) { vl az = vecl(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string strnum(ll l, ll zero = 0, ll ten = 10) { vl zt = vecl(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
};
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a){ sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
template <class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }

template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
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

void solve() {
  ll n, q; cin >> n >> q;
  BIT<ll> btx(n), bty(n);
  map<ll, ll> freqx, freqy;

  rep(_, q) {
    ll t; cin >> t;
    if (t == 1) {
      ll x, y; cin >> x >> y; x--; y--;
      freqx[x]++;
      freqy[y]++;
      if (freqx[x] == 1) btx.add(x, 1);
      if (freqy[y] == 1) bty.add(y, 1);
    } else if (t == 2) {
      ll x, y; cin >> x >> y; x--; y--;
      freqx[x]--;
      freqy[y]--;
      if (freqx[x] == 0) btx.add(x, -1);
      if (freqy[y] == 0) bty.add(y, -1);
    } else {
      ll x, y, x2, y2; cin >> x >> y >> x2 >> y2; x--; y--;
      if (btx.sum(x, x2) == x2 - x || bty.sum(y, y2) == y2 - y) cout << "Yes" << "\n"; else cout << "No" << "\n";
    }

  }

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
