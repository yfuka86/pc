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
  vl vecperm(ll l) { vl perm(l); iota(all(perm), 1); random_shuffle(all(perm)); return perm; }
  string str(ll l, vector<char> op) { vl fig = vecl(l, 0, op.size()); string s; rep(i, l) s.pb(op[fig[i]]); return s; }
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
  ll ans = 1; return ans;
}

void compare() {
  RandGen rg; ll c = 0, loop = 10;
  while (true) { c++; if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll N = 10;
    vl a = rg.vecl(N, 1, 1e2);
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
  // not sorted [2..x]
  vector<int> divisors(int x) { assert(x < n); auto f = factorize(x); vector<int> res = { 1 };
    for (auto [p, c] : f) for (int i = res.size() - 1; i >= 0; --i) for (int pow = 1; pow <= c; ++pow) res.emplace_back(res[i] * POW(p, pow));
    res.erase(res.begin()); return res;
  }
};


vector<ll> primes_below(const ll N) {
  vector<bool> is_prime(N + 1, true); for(ll i = 2; i * i <= N; i++) { if ((i > 2 && i % 2 == 0) || !is_prime[i]) continue; for(ll j = i * i; j <= N; j += i) is_prime[j] = false; }
  vector<ll> ret; for(ll i = 2; i <= N; i++) if (is_prime[i]) ret.emplace_back(i); return ret; }


void solve() {
  ll N, M; cin >> N >> M;
  vlin(A, N);
  vl ps = primes_below(sqrt_ceil(2 * M));
  vl cnt(2 * M + 1, 0);
  rep(i, N) cnt[A[i]]++;
  vl f = cnt, f2 = cnt;

  for (auto p: ps) {
    for(ll i = 2 * M / p; i > 0; i--) {
      f[i] += f[i * p];
    }
    for(ll i = 1; p * i <= 2 * M; i++) {
      f2[i * p] += f2[i];
    }
  }
  vl agg(N, 0);
  rep(i, N) {
    if (A[i] == 1) agg[i] = N - 1;
    agg[A[i]] = f[i]
  }
  if (A[0] == 1)

  PrimeSieve prs(2 * M);
  rep(i, N) {
    auto ps = prs.factorize(A[i]);
    for (auto [p, c]: ps) {

    }
  }

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(15);
  int t = 1; // cin >> t;
  while (t--) solve();
  // while (t--) compare();
}