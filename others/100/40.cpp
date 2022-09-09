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
typedef pair<int, int> IP;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const ll MOD = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> schedule(N, -1);
  rep(i, K) {
    int a, b; cin >> a >> b; a--; b--;
    schedule[a] = b;
  }

  vector<vector<vector<int>>> dp(N, vector<vector<int>>(3, vector<int>(3, 0)));

  rep(i, 3) {
    if (schedule[1] != -1 && schedule[1] != i) continue;
    rep(j, 3) {
      if (schedule[0] != -1 && schedule[0] != j) continue;
      dp[1][i][j] = 1;
    }
  }

  rep2(i, 2, N) {
    rep(j, 3) {
      if (schedule[i] != -1 && schedule[i] != j) continue;
      rep(k, 3) {
        rep(m, 3) {
          if (j == k && k == m) continue;
          dp[i][j][k] += dp[i - 1][k][m];
        }
        dp[i][j][k] %= 10000;
      }
    }
  }

  int sum = 0;
  rep(i, 3) {
    rep(j, 3) {
      sum += dp[N - 1][i][j];
    }
  }
  cout << sum % 10000 << endl;
}

