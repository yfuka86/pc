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

  int N, M;
  cin >> N >> M;

  vl A(N);
  vector<vl> cumsum(M, vl(N + 1, 0));
  vl setsum(1 << M, 0);
  rep(i, N) {
    cin >> A[i]; A[i]--;
    rep(j, M) {
      cumsum[j][i + 1] = cumsum[j][i] + (j == A[i] ? 1 : 0);
    }
  }
  rep(i, 1 << M) {
    rep(j, M) {
      if (i & (1 << j)) setsum[i] += cumsum[j][N];
    }
  }

  // coutmatrix(cumsum);
  // coutarray(setsum);

  // process
  vl dp(1 << M, LINF);
  dp[0] = 0;

  rep(i, 1 << M) {
    rep(j, M) {
      if (!(i & 1 << j)) continue;
      ll prev = i ^ 1 << j;
      ll tochange = cumsum[j][N] - (cumsum[j][setsum[i]] - cumsum[j][setsum[prev]]);
      chmin(dp[i], dp[prev] + tochange);
    }
  }

  cout << dp[(1 << M) - 1] << "\n";
}

