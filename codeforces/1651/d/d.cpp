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
template <class T> T POW(T x, int n) { assert(n >= 0); T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

void solve() {
  ll n; cin >> n;
  vector<LP> points(n);
  map<ll, set<LP>> p;

  rep(i, n) {
    ll x, y; cin >> x >> y; points[i] = mp(x, y);
    p[x].insert(mp(y, i));
  }

  vector<pair<ll, LP>> dp(n, mp(LINF, mp(0, 0)));

  function<void(ll, ll, ll)> neib = [&](ll x, ll y, ll i){
    if (dp[i].first != LINF) return;
    ll mi = LINF;
    LP ans;
    rep(j, 225) {
      if (j > mi) break;
      if (p.count(x + j)) {
        auto itr = p[x + j].lower_bound(mp(y, 0));
        if (itr != p[x + j].end() && itr->first == y) {
          auto [ny, ni] = *itr;
          neib(x + j, y, ni);
          if (chmin(mi, j + dp[ni].first)) ans = dp[ni].second;
        } else {
          if (chmin(mi, j)) ans = mp(x + j, y);
        }
      } else if (p.count(x - j)) {
        auto itr = p[x - j].lower_bound(mp(y, 0));
        if (itr != p[x - j].end() && itr->first == y) {
          auto [ny, ni] = *itr;
          neib(x - j, y, ni);
          if (chmin(mi, j + dp[ni].first)) ans = dp[ni].second;
        } else {
          if (chmin(mi, j)) ans = mp(x - j, y);
        }
      } else {
        if (chmin(mi, j)) ans = mp(x - j, y);
      }
    }
  };

  rep(i, n) {
    auto [x, y] = points[i];
    neib(x, y, i);
  }
  rep(i, n) {
    auto [x, y] = dp[i].second;
    cout << x << " " << y << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) solve();
}

using A = ll;
template<typename Q> A iquery(Q q, string str = "?") {
  cout << str <<  " " << q << "\n"; cout.flush();
  A a; cin >> a; return a;
}

template<typename A> void ianswer(A a) {
  cout << "! " << a << "\n"; cout.flush();
}
