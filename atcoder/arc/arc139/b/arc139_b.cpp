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

struct RandGen {
  using uidll = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll lint(ll a, ll b) { uidll d(a, b - 1); return d(mt); }
  vl vlint(ll a, ll b, ll l) { uidll d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vlperm(ll a) { vl perm(a); iota(all(perm), 1); random_shuffle(all(perm)); return perm; }
};

// void compare() {
//   RandGen rg;
//   while (true) {
//     ll N = rg.lint(1, 1e2);
//     vl A = rg.vlint(1, 1e5, N);
//     ll s = solve(N, A); ll n = naive(N, A);
//     if (s != n) {
//       cout << N << "\n";
//       coutarray(A);
//       cout << "naive:" << n << "\n";
//       cout << "solve:" << s << "\n";
//       break;
//     }
//   }
// }

bool solve() {
  ll N, A, B, X, Y, Z;
  // cin >> N >> A >> B >> X >> Y >> Z;
  RandGen rg;
  vl r = rg.vlint(1, 1e6, 6);
  N = r[0], A = r[1], B = r[2], X = r[3], Y = r[4], Z = r[5];
  ll originalN = N;

  if (Y >= A * X && Z >= B * X) { cout << N * X << "\n"; return false; }
  if (A * Z < B * Y) { swap(A, B); swap(Y, Z); }

  ll naive = LINF;
  rep(a, N / A + 1) {
    ll b = (N - a * A) / B;
    ll c = N - a * A - b * B;
    chmin(naive, Y * a + Z * b + X * c);
    chmin(naive, Y * a + X * (N - a*A));
  }

  ll l = lcm(A, B);
  ll YZ = l / A * Y;
  ll ans = (N / l) * YZ;
  ll coef = N / l;
  N %= l;
  // ll ans = 0;
  ll changedN = N;
  ll d = LINF;
  rep(a, N / A + 1) {
    ll b = (N - a * A) / B;
    ll c = N - a * A - b * B;
    assert(b >= 0 && c >= 0);
    chmin(d, Y * a + Z * b + X * c);
    chmin(d, Y * a + X * (N - a*A));
  }

  if (naive == ans + d) return false;
  else {
    cout << originalN << " " <<  A << " " << B << " " << X  << " " << Y << " " << Z << "\n";
    cout << naive << "\n";
    cout << ans + d << " " << changedN << "\n";
    return true;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t; cin >> t;
  while (true) if (solve()) break;
}
