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
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template <class T> T POW(T x, int n) { T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
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
  ll N; cin >> N;
  vl a(N), b(N); rep(i, N) cin >> a[i]; rep(i, N) cin >> b[i];
  comp(a); comp(b);
  vector<LP> p(N); rep(i, N) { p[i] = mp(a[i], -b[i]); }
  sort(all(p));

  map<LP, ll> samep;
  rep(i, N) samep[p[i]]++;

  BIT<ll> bs(N);
  ll ans = 0;
  rep(i, N) {
    bs.add(-p[i].second, 1);
    ans += i + 1 - bs.sum(-p[i].second);
  }

  for (auto [p, count]: samep) {
    if (count > 1) ans += count * (count - 1) / 2;
  }
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
