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
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll lint(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  vl vlint(ll l, ll a, ll b) { ud d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
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
template<typename T> void uniq(vector<T>&a){ sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};

//-------------------------------------------------------
// https://atcoder.jp/contests/abc238/submissions/29086825
// https://cp-algorithms.com/algebra/prime-sieve-linear.html
struct PrimeSieve {
  int n; vector<bool> is_prime; vector<int> pr, mu, pf;
  // pr := primes, mu := moebius, pf[i] := smallest prime p s.t. p | i
  PrimeSieve(int _n){
    n = ++_n; is_prime.assign(n, true); mu.assign(n, 0); pf.assign(n, 0);
    is_prime[0] = is_prime[1] = false; mu[1] = 1;
    for (int i = 2; i < n; i++) {
      if (is_prime[i]) { pr.emplace_back(i); pf[i] = i; mu[i] = -1; }
      for (int p : pr) {
        if (ll(i) * p >= n) break;
        is_prime[i * p] = false; mu[i * p] = -mu[i]; pf[i * p] = p;
        if (i % p == 0) { mu[i * p] = 0; break; }
      }
    }
  }
  vector<pair<int, int>> factorize(int x) { assert(x < n); vector<pair<int, int>> res;
    while (pf[x] > 1) { int d = pf[x], c = 0; while (x % d == 0) { x /= d; c++; } res.emplace_back(d, c); }
    if (x != 1) res.emplace_back(x, 1); return res;
  }
  // not sorted except for 1
  vector<int> divisors(int x) { assert(x < n); auto f = factorize(x); vector<int> res = { 1 };
    for (auto [p, c] : f) for (int i = res.size() - 1; i >= 0; --i) for (int pow = 1; pow <= c; ++pow) res.emplace_back(res[i] * POW(p, pow));
    res.erase(res.begin()); return res;
  }
};

void solve() {
  ll n; cin >> n;
  vl p(n + 1); rep(i, n) cin >> p[i + 1];
  PrimeSieve ps(n);

  vvi ds(n + 1);
  rep(i, n + 1) { ds[i] = ps.divisors(i); }

  vl c2(n + 1);
  rep(i, n + 1) c2[i] = i * (i + 1) / 2;

  ll ans = 0;
  vl cnt(n + 1);
  rep2(k, 2, n + 1) {
    if (ps.mu[k] == 0) continue;
    ll now = 0;
    for (ll i = k; i <= n; i += k) {
      for (ll x: ds[p[i]]) cnt[x]++;
    }
    for (ll i = k; i <= n; i += k) {
      for (ll x: ds[p[i]]) if (cnt[x]) {
        now += c2[cnt[x]] * ps.mu[x];
        cnt[x] = 0;
      }
    }
    ans += now * ps.mu[k];
  }
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}