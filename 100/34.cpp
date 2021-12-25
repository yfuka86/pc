#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<ll> dp(n + 1);
  dp[0] = 1; dp[1] = 1;

  rep2(i, 2, n + 1) {
    dp[i] = dp[i - 2] + dp[i - 1];
  }
  cout << dp[n] << endl;
}

