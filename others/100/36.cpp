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
  int N, W;
  cin >> N >> W;

  vector<int> v(N);
  vector<int> w(N);
  rep(i, N) cin >> v[i] >> w[i];

  vector<int> dp(W + 1, 0);
  rep(i, N) {
    int value = v[i];
    int weight = w[i];
    rep(j, W) {
      if (W - j >= weight) dp[j + weight] = max(dp[j + weight], dp[j] + value);
    }
  }
  cout << dp[W] << endl;
}

