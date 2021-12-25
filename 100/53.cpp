// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=ja

#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <bitset>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = numeric_limits<int>::max();

int main()
{
  int N;
  cin >> N;

  int seq[N];

  rep(i, N) {
    cin >> seq[i];
  }

  vector<int> dp(N, INF);

  rep(i, N) {
    vector<int>::iterator iter = upper_bound(all(dp), seq[i]);
    if (iter != dp.end()) {
      int idx = iter - dp.begin();
      if (idx == 0 || dp[idx - 1] < seq[i]) {
        dp[idx] = seq[i];
      }
    }
  }

  int count = 0;
  rep(i, N) if (dp[i] != INF) count++;
  cout << count << endl;
}

