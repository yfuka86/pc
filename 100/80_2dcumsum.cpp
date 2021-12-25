// https://atcoder.jp/contests/gigacode-2019/tasks/gigacode_2019_d
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

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}


int main()
{
  ll H, W, K, V;
  cin >> H >> W >> K >> V;

  vector<vector<ll>> costsum(H, vector<ll>(W));
  rep(i, H) {
    rep(j, W) {
      ll t;
      cin >> t;
      if (j > 0) t += costsum[i][j-1];
      if (i > 0) t += costsum[i-1][j];
      if (i > 0 && j > 0) t -= costsum[i-1][j-1];
      costsum[i][j] = t;
    }
  }

  ll maxarea = 0;
  rep(i, H) {
    rep(wi, W) {
      rep2(j, i, H) {
        rep2(wj, wi, W) {
          ll size = (j - i + 1) * (wj - wi + 1);
          if (size <= maxarea) continue;
          ll c = costsum[j][wj];
          if (i > 0) c -= costsum[i - 1][wj];
          if (wi > 0) c -= costsum[j][wi - 1];
          if (i > 0 && wi > 0) c += costsum[i - 1][wi - 1];

          if (c + size * K <= V) maxarea = size;
        }
      }
    }
  }

  cout << maxarea << endl;
}

