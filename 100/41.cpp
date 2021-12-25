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

struct Cloth {
  int min, max, c;
};

int main()
{
  int D, N;
  cin >> D >> N;
  vector<int> temp(D);
  rep(i, D) cin >> temp[i];
  vector<Cloth> clothes(N);
  rep(i, N) {
    int a, b, c; cin >> a >> b >> c;
    clothes[i] = { a, b, c };
  }
  vector<vector<int>> dp(D, vector<int>(101, -1));

  rep(i, N) {
    int t = temp[0];
    Cloth c = clothes[i];
    if (c.min <= t && c.max >= t) dp[0][c.c] = 0;
  }

  rep2(i, 1, D) {
    int t = temp[i];
    rep(j, N) {
      Cloth c = clothes[j];
      if (c.min <= t && c.max >= t) {
        int m = 0;
        rep(k, 101) {
          if (dp[i - 1][k] == -1) continue;
          chmax(m, dp[i - 1][k] + abs(c.c - k));
        }
        dp[i][c.c] = m;
      }
    }
  }

  int m = 0;
  rep(i, 101) {
    chmax(m, dp[D - 1][i]);
  }

  cout << m << endl;
}

