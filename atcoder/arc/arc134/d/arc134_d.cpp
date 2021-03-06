#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
struct RandGen {
  using uidll = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll lint(ll a, ll b) { assert(a < b); uidll d(a, b - 1); return d(mt); }
  vl vlint(ll l, ll a, ll b) { assert(a < b); uidll d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vlperm(ll l) { vl perm(l); iota(all(perm), 1); random_shuffle(all(perm)); return perm; }
  string saz(ll l, ll a = 0, ll z = 26) { vl az = vlint(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string snum(ll l, ll zero = 0, ll ten = 10) { vl zt = vlint(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
};
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};

vl naive(ll N, vl a, vl b) {
  vl ans; ans.pb(LINF);
  rep2(S, 1, 1 << N) {
    vl t;
    rep(i, N) if (S & 1 << i) t.pb(a[i]);
    rep(i, N) if (S & 1 << i) t.pb(b[i]);
    chmin(ans, t);
  }
  return ans;
}

// vl solve(ll N, vl a, vl b) {
void solve() {
  ll N; cin >> N;
  vl a(N), b(N);
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];

  vector<LT> t(N), sorted(N), sorted2(N);
  rep(i, N) { t[i] = {a[i], b[i], i}; sorted[i] = {a[i], b[i], i}; sorted2[i] = {a[i], i, b[i]}; }
  sort(all(sorted));sort(all(sorted2));

  vector<LT> ans;
  auto [fa, fb, fi] = sorted.front();

  if (fa < fb) {
    rep(i, N) {
      auto [aa, bb, ii] = t[i];
      if (aa == fa) ans.pb(t[i]);
    }

    for (auto t: sorted2) {
      auto [la, lb, li] = ans.back();
      auto [aa, ii, bb] = t;
      if (ii > li) {
        if (aa < get<1>(ans.front())) {
          ans.pb({aa, bb, ii});
        } else if (aa == get<1>(ans.front())) {
          if (ans.size() >= 1) {
            ll idx = 1;
            while (idx < ans.size()) {
              if (get<1>(ans.front()) < get<1>(ans[idx])) {
                ans.pb({aa, bb, ii});
                break;
              } else if (get<1>(ans.front()) == get<1>(ans[idx])) {
                idx++;
              } else break;
            }

          }
        }
      }
    }
  } else {
    ans.pb(sorted.front());
  }

  vl ansa;
  for (auto t: ans) { ansa.pb(get<0>(t)); }
  for (auto t: ans) { ansa.pb(get<1>(t)); }
  // return ansa;
  coutarray(ansa);
}

// void compare() {
//   RandGen rg;
//   ll c = 0, loop = 10;
//   while (true) {
//     c++; if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n";
//     ll N = 15;
//     vl a = rg.vlint(N, 1, 1e1);
//     vl b = rg.vlint(N, 1, 1e1);
//     vl n = naive(N, a, b);
//     vl s = solve(N, a, b);
//     if (n != s) {
//       cout << c << "times tried" << "\n";
//       cout << N << "\n";
//       coutarray(a);
//       coutarray(b);
//       cout << "naive:" << "\n";
//       coutarray(n);
//       cout << "solve:" << "\n";
//       coutarray(s);
//       break;
//     }
//   }
// }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
