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

vector<ll> primes_below(const ll N) {
  vector<bool> is_prime(N + 1, true); for(ll i = 2; i * i <= N; i++) { if ((i > 2 && i % 2 == 0) || !is_prime[i]) continue; for(ll j = i * i; j <= N; j += i) is_prime[j] = false; }
  vector<ll> ret; for(ll i = 2; i <= N; i++) if (is_prime[i]) ret.emplace_back(i); return ret; }


//-------------------------------------------------------
// https://atcoder.jp/contests/abc238/submissions/29086825
// https://cp-algorithms.com/algebra/prime-sieve-linear.html
const int PSX = 1e6 + 1;
struct PrimeSieve {
  bitset<PSX> is_prime; vector<int> pr;
  int mu[PSX];  // moebius
  int pf[PSX];  // pf[i] := smallest prime p s.t. p | i
  PrimeSieve(){
    is_prime.flip(); is_prime[0] = is_prime[1] = false; mu[1] = 1;
    for (int i = 2; i < PSX; i++) {
      if (is_prime[i]) { pr.push_back(i); pf[i] = i; mu[i] = -1; }
      for (int p : pr) {
        if (ll(i) * p >= PSX) break;
        is_prime[i * p] = false; mu[i * p] = -mu[i]; pf[i * p] = p;
        if (i % p == 0) { mu[i * p] = 0; break; }
      }
    }
  }
  vector<pair<int, int>> factorize(int x) { vector<pair<int, int>> vec; while (pf[x] > 1) { int d = pf[x], c = 0; while (x % d == 0) { x /= d; c++; } vec.emplace_back(d, c); } if (x != 1) vec.emplace_back(x, 1); return vec; }
};

void solve() {
  ll N; cin >> N;
  vl P(N + 1); rep(i, N) cin >> P[i + 1];
  vl ps = primes_below(N);

  vvl is(N + 1);
  rep2(i, 1, N + 1) is[i].pb(P[i]);
  for (auto p: ps) {
    for (ll i = N / p; i >= 1; --i) {
      is[i].insert(is[i].end(), is[i*p].begin(), is[i*p].end());
    }
  }

  vl plist;
  {
    PrimeSieve ps;
    rep2(i, 2, N + 1) {
      bool valid = true;
      for (auto [p, c]: ps.factorize(i)) if (c > 1) valid = false;
      if (valid) plist.pb(i);
    }
  }

  // coutmatrix(is);

  vl f(N + 1, 0);
  // rep2(p, 2, N + 1) {
  for (auto p: plist) {
    vl &v = is[p];
    if (v.size() <= 1) continue;

    if (v.size() < sqrt_ceil(N)) {
      rep(i, v.size()) {
        rep2(j, i + 1, v.size()) {
          if (gcd(v[i], v[j]) > 1) f[p]++;
        }
      }
    } else {
      vl cnt(N + 1, 0);
      for (auto e: v) cnt[e] += 1;
      for (auto p: ps) {
        for (ll i = N / p; i >= 1; --i) {
          cnt[i] += cnt[i*p];
        }
      }
      rep(i, N + 1) {
        if (cnt[i]) cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
      }
      for (auto p: ps) {
        for (ll i = 1; i * p <= N; i++) {
          cnt[i] -= cnt[i*p];
        }
      }
      f[p] = accumulate(cnt.begin() + 2, cnt.end(), 0LL);
    }
  }

  // coutarray(f);

  for (auto p: ps) {
    for (ll i = 1; i * p <= N; i++) {
      f[i] -= f[i*p];
    }
  }

  // coutarray(f);

  ll ans = accumulate(f.begin() + 2, f.end(), 0LL);
  rep2(i, 2, N + 1) if (P[i] != 1) ans++;

  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
