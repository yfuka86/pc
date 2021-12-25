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
#include <bitset>
#define rep(i,n) for (ll i=0; i<(ll)(n); ++i)
#define rep2(i,x,n) for(ll i=x; i<(ll)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  ll N;
  cin >> N;

  const ll threshold = 100000;

  ll sum = 0;
  rep2(i, 1, threshold) {
    sum += N / i;
  }

  if (N >= threshold) {
    vector<ll> dp(N / threshold + 1, 0);
    rep2(i, 1, N / threshold + 1) {
      ll from = N / (i + 1) + 1;
      dp[i] = from;
    }

    sum += (N - dp[1] + 1) * 1;
    rep2(i, 2, N / threshold + 1) {
      sum += (dp[i - 1] - dp[i]) * i;
    }
  }

  cout << sum << endl;
}

