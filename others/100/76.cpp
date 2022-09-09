// https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_a

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

template <class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  int N;
  cin >> N;
  vector<ll> sum(N + 1, 0);
  rep(i, N) {
    ll t;
    cin >> t;
    sum[i + 1] = t + sum[i];
  }

  rep(i, N) {
    ll ans = 0;
    rep(j, N + 1) {
      if (j + i + 1 > N) continue;
      chmax(ans, sum[j + i + 1] - sum[j]);
    }
    cout << ans << endl;
  }
}

