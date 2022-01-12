#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 3;
const ll LINF = LLONG_MAX / 3;
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

  ll N; cin >> N;
  vector<vl> time(N, vl(N));
  rep(i, N) rep(j, N) cin >> time[i][j];

  ll M; cin >> M;
  vector<vb> rumor(N, vb(N, false));
  rep(i, M) {
    ll x, y; cin >> x >> y; x--; y--;
    rumor[x][y] = true;
    rumor[y][x] = true;
  }

  vector<vl> dp(1 << N, vl(N, -1));
  rep(i, N) dp[0][i] = 0;

  rep(S, 1 << N) {
    // 次走る選手
    rep(i, N) {
      if (S >> i & 1) continue;

      ll mi = LINF;
      // 前の選手
      rep(j, N) {
        ll prev = dp[S][j];
        if (prev == -1) continue;
        ll segment = __builtin_popcount(S);
        if (!rumor[j][i]) chmin(mi, prev + time[i][segment]);
      }
      dp[S | 1 << i][i] = mi == LINF ? -1 : mi;
    }
  }

  ll ans = LINF;
  ll last = (1 << N) - 1;
  rep(i, N) {
    if (dp[last][i] != -1) chmin(ans, dp[last][i]);
  }
  cout << (ans == LINF ? -1 : ans) << "\n";
}


