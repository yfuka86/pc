#pragma GCC optimize("Ofast")
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
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define vi vector<int>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  vi tetranum(200);
  tetranum[0] = 1;
  Rep(i, 1, 200) tetranum[i] = tetranum[i - 1] * (i + 3) / i;

  vi dp(1000000, INF);
  vi odddp(1000000, INF);
  dp[0] = 0; dp[1] = 1; odddp[0] = 0; odddp[1] = 1;

  Rep(i, 2, 1000000) {
    rep(j, 200) {
      if (i >= tetranum[j]) {
        chmin(dp[i], dp[i - tetranum[j]] + 1);
        if (tetranum[j] % 2 == 1) {
          chmin(odddp[i], odddp[i - tetranum[j]] + 1);
        }
      } else {
        continue;
      }
    }
  }

  int N;
  while (true) {
    cin >> N;
    if (N == 0) break;
    cout << dp[N] << " " << odddp[N] << "\n";
  }
}

