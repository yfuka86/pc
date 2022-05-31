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
#define fi first
#define se second

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT; typedef tuple<ll, ll, ll, ll> LT4;
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
  vl vecperm(ll l, ll from = 0) { vl perm(l); iota(all(perm), from); shuffle(perm); return perm; }
  string str(ll l, vector<char> op) { vl fig = vecl(l, 0, op.size()); string s; rep(i, l) s.pb(op[fig[i]]); return s; }
  string straz(ll l, ll a = 0, ll z = 26) { vl az = vecl(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string strnum(ll l, ll zero = 0, ll ten = 10) { vl zt = vecl(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
  void shuffle(vl &a) { std::shuffle(all(a), mt); }
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
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template <class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }

template<typename T> void coutarray(vector<T>& v, int offset = 0, string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset) cout << v[i] + offset; else cout << v[i]; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v, int offset = 0) { rep(i, v.size()) { coutarray(v[i], offset); } }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T, typename S> void coutpair(pair<T, S> & p) { cout << p.first << " " << p.second << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
const string drul = "DRUL"; vl dx = {1, 0, -1, 0}; vl dy = {0, 1, 0, -1};

ll solve(ll N, vl a) {
  ll ans = -1; return ans;
}

ll naive(ll N, vl a) {
  vl par;
  rep(_, N / 2) { par.pb(1); par.pb(-1); }
  RandGen().shuffle(par);

  sort(all(a));
  vl rev = a; reverse(all(rev));
  vl mi = rev, ma = a;
  do {
    ll sum = 0;
    bool valid = true;
    rep(i, N) {
      sum += par[a[i]];
      if (sum < 0) valid = false;
    }
    if (valid) { chmin(mi, a); chmax(ma, a); }
  } while (next_permutation(all(a)));

  coutarray(par);
  coutarray(mi,1);
  coutarray(ma,1);
  return 0;
}

void compare() {
  RandGen rg; ll c = 0, loop = 10;
  while (true) { c++; if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll N = 6;
    vl a = rg.vecperm(N);
    auto s = solve(N, a); auto n = naive(N, a);
    if (n != s) {
      cout << c << "times tried" << "\n";
      cout << N << "\n"; coutarray(a);
      cout << "solve: " << s << "\n";
      cout << "naive: " << n << "\n";
      break;
    }
  }
}

vl build(vl& a, bool minimum = true) {
  priority_queue<ll, vl, greater<ll>> open, close;
  vl ret;

  rep(i, a.size()) {
    if (a[i] == 1) open.push(minimum ? i : -i);
    else close.push(minimum ? i : -i);
  }

  ll sum = 0;
  while(open.size() || close.size()) {
    if (open.size() == 0) {
      ret.pb(close.top()); close.pop();
    } else {
      if (sum > 0 && close.top() < open.top()) {
        ret.pb(close.top()); close.pop();
        sum--;
      } else {
        ret.pb(open.top()); open.pop();
        sum++;
      }
    }
  }

  if (!minimum) {
    rep(i, ret.size()) ret[i] = -ret[i];
  }
  return ret;
}

void solve() {
  ll N; cin >> N;
  vlin(p, N * 2);
  vlin(q, N * 2);
  rep(i, N * 2) {
    p[i]--; q[i]--;
  }

  bool valid = true;

  vl ans(N * 2, 0);
  rep(i, N * 2 - 1) {
    if (p[i] > p[i + 1]) {
      if (ans[p[i]] == -1 || ans[p[i + 1]] == 1) valid = false;
      ans[p[i]] = 1;
      ans[p[i + 1]] = -1;
    }
    if (q[i] < q[i + 1]) {
      if (ans[q[i]] == -1 || ans[q[i + 1]] == 1) valid = false;
      ans[q[i]] = 1;
      ans[q[i + 1]] = -1;
    }
  }
  rep(i, N * 2) {
    if (ans[i] == 0) valid = false;
  }

  ll sum1 = 0, sum2 = 0;
  rep(i, N * 2) {
    sum1 += ans[p[i]];
    sum2 += ans[q[i]];
    if (sum1 < 0 || sum2 < 0) valid = false;
  }
  if (sum1 != 0 || sum2 != 0) valid = false;

  if (!valid || build(ans) != p || build(ans, false) != q) cout << -1 << "\n";
  else {
    rep(i, N * 2) {
      if (ans[i] == 1) cout << "("; else cout << ")";
    }
    cout << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(15);
  int t = 1; // cin >> t;
  // while (t--) solve();
  while (t--) compare();
}
