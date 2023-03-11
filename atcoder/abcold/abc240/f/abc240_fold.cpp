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
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

void solve() {
  ll n, m; cin >> n >> m;
  vector<LP> c(n);
  rep(i, n) {
    ll x, y; cin >> x >> y;
    c[i] = mp(x, y);
  }

  ll bcur = 0;
  vl bfirst(n);
  // 区間のx個目が必要という情報
  vl need(n, -1);
  rep(i, n) {
    bfirst[i] = bcur;
    auto [x, y] = c[i];
    if (bcur > 0) {
      if (bcur + y * x < 0) {
        need[i] = bcur / abs(x);
        // cout << "need" << i  << " " << need[i] << "\n";
      }
    }
    bcur += y * x;
  }

  ll ans = c[0].first;
  ll cur = 0;
  rep(i, n) {
    auto [x, y] = c[i];
    if (need[i] > 0) {
      ll dy = need[i];
      chmax(ans, cur + bfirst[i] * dy + (dy * (dy + 1) / 2) * x);
    }

    cur += bfirst[i] * y + (y * (y + 1) / 2) * x;
    // cout << cur << endl;
    chmax(ans, cur);
  }
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}
