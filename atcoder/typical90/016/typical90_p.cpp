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

// ap + bq = gcd(a, b)
LP extGCD(ll a, ll b) {
  ll p11 = 1, p12 = 0, p21 = 0, p22 = 1;
  while (b) {
    ll s = a / b;
    // matrix{{0, 1}, {1, -s}}
    a -= s * b; swap(a, b);

    p11 -= s * p21; p12 -= s * p22;
    swap(p11, p21); swap(p12, p22);
  }
  return {p11, p12};
}

void solve() {
  ll N; vl c(3); cin >> N >> c[0] >> c[1] >> c[2];
  sort(all(c));

  ll ans = 10000;
  rep_r(i, min<ll>(floor(N, c[2]) + 1, 10000)) {
    ll rem = N - c[2] * i;
    ll gc = gcd(c[0], c[1]), lc = lcm(c[0], c[1]);
    if (rem % gc != 0) continue;
    auto [g0, g1] = extGCD(c[0], c[1]);
    g0 *= rem / gc; g1 *= rem / gc;
    ll coef0 = lc / c[0], coef1 = lc / c[1];
    auto chans = [&]() { if (g0 >= 0 && g1 >= 0) chmin(ans, i + g0 + g1); };

    if (g0 < 0) {
      ll k = ceil(abs(g0), coef0);
      g0 += k * coef0; g1 -= k * coef1;
    } else {
      ll k = ceil(abs(g1), coef1);
      g0 -= k * coef0; g1 += k * coef1;
    }

    if (g0 >= 0 && g1 >= 0) {
      ll k = g0 / coef0;
      g0 -= k * coef0;
      g1 += k * coef1;
      chans();
    }
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
