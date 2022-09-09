#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

vector<int> vec_input(int n) {
  vector<int> v;
  int t = 0;
  for(int i = 0;i < n;i++){
    cin >> t;
    v.push_back(t);
  }
  return v;
}

int main()
{
  int N;
  cin >> N;
  vector<int> nums = vec_input(N);

  int ans = nums[N - 1];
  vector<vector<ll>> dp(N, vector<ll>(21, 0));

  rep(i, N - 1) {
    if (i == 0) {
      dp[0][nums[i]] = 1;
      continue;
    }
    rep(j, 21) {
      if (dp[i - 1][j] == 0) continue;
      if (j + nums[i] <= 20) dp[i][j + nums[i]] += dp[i - 1][j];
      if (j - nums[i] >= 0) dp[i][j - nums[i]] += dp[i - 1][j];
    }
  }

  cout << dp[N - 2][ans] << endl;
}

