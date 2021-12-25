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
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> IP;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const ll MOD = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> d(N);
  rep(i, N) cin >> d[i];

  vector<int> weather(M);
  rep(i, M) cin >> weather[i];

  vector<vector<int>> dp(M, vector<int>(N + 1, INF));

  rep(i, M) {
    dp[i][0] = 0;
  }
  dp[0][1] = d[0] * weather[0];

  rep2(i, 1, M) {
    for(int j = N; j > 0; j--) {
      if (j == 0 || dp[i - 1][j - 1] == INF) {
        dp[i][j] = dp[i - 1][j];
        continue;
      }
      dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + weather[i] * d[j - 1]);
    }
  }
  cout << dp[M - 1][N] << endl;
}

