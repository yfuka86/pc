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

LP crp(LP& a, LP& b, LP& c) {
  auto [ox, oy] = a;
  auto [bx, by] = b;
  auto [cx, cy] = c;
  ll x1 = bx - ox, y1 = by - oy;
  ll x2 = cx - ox, y2 = cy - oy;
  return {POW(y2 - y1, 2) + POW(x2 - x1, 2), x1 * y2 - y1 * x2};
}

void solve() {
  ll n; cin >> n;
  vector<LP> S(n), T(n);
  rep(i, n) {
    ll a, b; cin >> a >> b; S[i] = mp(a, b);
  }
  rep(i, n) {
    ll a, b; cin >> a >> b; T[i] = mp(a, b);
  }
  if (n == 1) {cout << "Yes" << "\n"; return; }

  // S[0], S[1]に相当するものを見つける
  auto [x1, y1] = S[0];
  auto [x2, y2] = S[1];
  ll dist = POW(x2 - x1, 2) + POW(y2 - y1, 2);

  multiset<LP> id;
  rep2(i, 2, n) {
    id.insert(crp(S[0], S[1], S[i]));
  }

  rep(i, n) {
    rep(j, n) {
      if (i == j) continue;
      auto [ix, iy] = T[i];
      auto [jx, jy] = T[j];
      ll d = POW(ix - jx, 2) + POW(iy - jy, 2);
      if (d == dist) {
        multiset<LP> tmp;
        rep(k, n) {
          if (k == i || k == j) continue;
          tmp.insert(crp(T[i], T[j], T[k]));
        }
        if (tmp == id) {
          // cout << i << " " << j << "\n";
          // for (auto v: tmp) cout << v << " ";
          cout << "Yes" << "\n"; return;
        }
      }
    }
  }
  cout << "No" << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
