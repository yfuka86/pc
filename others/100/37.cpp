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
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> c(m);
  rep(i, m) cin >> c[i];

  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  rep(i, n) {
    rep(j, m) {
      int next_idx = i + c[j];
      if (next_idx <= n) dp[next_idx] = min(dp[next_idx], dp[i] + 1);
    }
  }
  cout << dp[n] << endl;
}

