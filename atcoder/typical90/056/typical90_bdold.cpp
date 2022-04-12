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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, S; cin >> N >> S;

  vl a(N), b(N);
  rep(i, N) {
    cin >> a[i] >> b[i];
  }

  vector<vector<vl>> dp(N + 1, vector<vl>(S + 1, vl(2, 0)));
  dp[0][0][0] = 1;
  dp[0][0][1] = 1;
  rep(i, N) {
    rep_r(j, S) {
      if (dp[i][j][0] || dp[i][j][1]) {
        if (j + a[i] <= S) dp[i + 1][j + a[i]][0] = 1;
        if (j + b[i] <= S) dp[i + 1][j + b[i]][1] = 1;
      }
    }
  }

  // coutmatrix(dp);

  if (dp[N][S][0] || dp[N][S][1]) {
    string ans = "";

    ll cur = S;
    rep_r(i, N) {
      // cout << cur << endl;
      rep(j, 2) {
        if (dp[i + 1][cur][j]) {
          ans.pb(j == 0 ? 'A' : 'B');
          cur -= (j == 0 ? a[i] : b[i]);
          break;
        }
      }
    }
    reverse(all(ans));
    cout << ans << "\n";
  } else {
    cout << "Impossible" << "\n";
  }
}


