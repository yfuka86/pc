#pragma GCC optimize("Ofast")
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <bitset>
#include <numeric>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep_r(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(int i=sta;i<(int)(n);i++)
#define rep2_r(i,sta,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll mod = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
void comp(vector<int>&a){ vector<int> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T>
void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T>
void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };
template<typename K, typename V>
void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M;
  cin >> N >> M;

  vector<vector<LP>> G(N, vector<LP>(N, make_pair(LINF, 0)));
  vector<vector<LP>> dp(1 << N, vector<LP>(N, make_pair(LINF, -1)));
  rep(i, M) {
    ll s, t, d, ti; cin >> s >> t >> d >> ti; s--; t--;
    G[s][t] = make_pair(d, ti);
    G[t][s] = make_pair(d, ti);
  }
  dp[0][0] = make_pair(0, 1);

  rep(S, 1 << N) {
    rep(i, N) {
      if (!(S >> i & 1)) continue;
      ll mi = LINF;
      vector<LP> prevs;
      rep(j, N) {
        LP prev = dp[S^(1 << i)][j];
        if (prev.first == LINF || G[j][i].first == LINF) continue;
        ll past = prev.first + G[j][i].first;
        if (past <= G[j][i].second) {
          if (past < mi) {
            mi = past;
            prevs.clear();
            prevs.pb(prev);
          } else if (past == mi) {
            prevs.pb(prev);
          }
        }
      }
      ll cases = 0;
      for (LP p: prevs) cases += p.second;
      dp[S][i] = make_pair(mi, cases);
    }
  }

  LP ans = dp[(1 << N) - 1][0];
  if (ans.first == LINF) {
    cout << "IMPOSSIBLE" << "\n";
  } else cout << ans.first << " " << ans.second << "\n";
}

