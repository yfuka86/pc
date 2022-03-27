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
const int INF = numeric_limits<int>::max(); const ll LINF = LLONG_MAX; const double DINF = numeric_limits<double>::infinity();

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

void solve() {
  string S; cin >> S;
  ll K; cin >> K;
  ll N = S.size();
  vvl index(3);
  rep(i, N) rep(j, 3) if (S[i] == "KEY"[j]) index[j].pb(i);

  vector<vector<vvl>> dp(N + 1, vector<vvl>(N + 1, vvl(N + 1, vl(500, 0))));
  dp[0][0][0][0] = 1;
  ll kfreq = index[0].size(), efreq = index[1].size(), yfreq = index[2].size();


  rep(i, N) {
    rep(k, kfreq + 1) {
      rep(e, efreq + 1) {
        ll koff = 0, eoff = 0, yoff = 0;
        rep(kk, k) { if (kfreq > kk && index[0][kk] >= i) koff++; }
        rep(ee, e) { if (efreq > ee && index[1][ee] >= i) eoff++; }
        rep(yy, i - k - e) { if (yfreq > yy && index[2][yy] >= i) yoff++; }
        ll kd = eoff + yoff - i;
        ll ed = koff + yoff - i;
        ll yd = koff + eoff - i;

        rep(n, 499) {
          if (dp[i][k][e][n] == 0) continue;
          if (k < kfreq) {
            if (index[0][k] + kd >= 0) dp[i + 1][k + 1][e][n + index[0][k] + kd] += dp[i][k][e][n];
          }
          if (e < efreq) dp[i + 1][k][e + 1][n + abs(index[1][e] + ed)] += dp[i][k][e][n];
          if (i - k - e < yfreq) dp[i + 1][k][e][n + abs(index[2][i - k - e] + yd)] += dp[i][k][e][n];
        }
      }
    }
  }

  ll ans = 0;
  rep(i, min(500LL, K + 1)) {
    ans += dp[N][kfreq][efreq][i];
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
