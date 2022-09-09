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

using namespace std;

vector<vector<int> > dp;

int main()
{
  int N, W;
  cin >> N >> W;
  dp.resize(N);
  dp.assign(N, vector<int>(W + 1, 0));

  rep(i, N) {
    int v, w;
    cin >> v >> w;
    rep(j, W + 1) {
      if (i == 0) {
        if (j < w) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = v;
        }
      } else {
        if (j < w) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
        }
      }
    }
  }

  cout << dp[N - 1][W] << endl;
}

