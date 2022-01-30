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
typedef long long ll; typedef long double ld;
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
  int n, e, k; cin >> n >> e >> k;
  vi d(n + 1), limit(n + 1);
  rep(i, n) cin >> d[i];
  d[n] = e;
  rep(i, n) cin >> limit[i];
  limit[n] = 0;

  vector<vector<map<int, int>>> dp(n + 1, vector<map<int, int>>(k + 1));

  dp[0][0][0] = 0;

  rep(i, n) {
    int dist = d[i + 1] - d[i];
    rep(j, k + 1) {
      rep(l, n) {
        if (dp[i][j].count(l) == 0) continue;

        if (dp[i + 1][j].count(i + 1)) {
          chmin(dp[i + 1][j][i + 1], dp[i][j][l] + dist * limit[l]);
        } else dp[i + 1][j][i + 1] = dp[i][j][l] + dist * limit[l];

        if (j < k && limit[l] < limit[i + 1]) {
          if (dp[i + 1][j + 1].count(l)) {
            chmin(dp[i + 1][j + 1][l], dp[i][j][l] + dist * limit[l]);
          } else dp[i + 1][j + 1][l] = dp[i][j][l] + dist * limit[l];
        }
      }
    }
  }

  int ans = INF;
  rep(i, k + 1) {
    for (auto kv: dp[n][i]) {
      chmin(ans, kv.second);
    }
  }
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}

template<typename Q, typename A> A iquery(Q& q) {
  cout << "? " << q << "\n"; cout.flush();
  A a; cin >> a; return a;
}

template<typename A> void ianswer(A& a) {
  cout << "! " << a << "\n"; cout.flush();
}

