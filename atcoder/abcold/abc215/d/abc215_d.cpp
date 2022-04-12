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
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 2 - 10; const ll LINF = LLONG_MAX / 2 - 10; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template <class T> T POW(T x, int n) { assert(n >= 0); T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};
//-------------------------------------------------------
// https://atcoder.jp/contests/abc238/submissions/29086825
// https://cp-algorithms.com/algebra/prime-sieve-linear.html
const int PSX = 1e5 + 1;
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
  ll N, M; cin >> N >> M;
  vl A(N); rep(i, N) cin >> A[i];

  PrimeSieve ps;
  set<ll> factor;
  rep(i, N) {
    for (auto [f, c]: ps.factorize(A[i])) {
      factor.insert(f);
    }
  }

  vl ans;
  rep2(i, 1, M + 1) {
    bool valid = true;
    for (auto [f, c]: ps.factorize(i)) {
      if (factor.find(f) != factor.end()) { valid = false; break; }
    }
    if (valid) ans.pb(i);
  }
  cout << ans.size() << "\n";
  rep(i, ans.size()) {
    cout << ans[i] << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
