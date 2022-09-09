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

// string s1, s2;
// vector<vector<int> > dp;

// int lcs(int i1, int i2) {
//   if (i1 == -1 || i2 == -1) return 0;
//   if (dp[i1][i2] != -1) return dp[i1][i2];

//   if (s1[i1] == s2[i2]) {
//     return dp[i1][i2] = lcs(i1 - 1, i2 - 1) + 1;
//   } else {
//     return dp[i1][i2] = max(lcs(i1 - 1, i2), lcs(i1, i2 - 1));
//   }
// }

int lcs(string &s1, string &s2){
  vector<vector<int> > dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
  function<int(int, int)> rec = [&](int m, int n) -> int {
    if (dp[m][n] != -1) return dp[m][n];
    if (m == 0 || n == 0) return dp[m][n] = 0;
    if (s1[m - 1] == s2[n - 1]) return dp[m][n] = rec(m - 1, n - 1) + 1;
    return max(rec(m, n - 1), rec(m - 1, n));
  };
  return rec(s1.size(), s2.size());
}


int main()
{
  int q;
  cin >> q;
  string s1, s2;

  rep(i, q) {
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << "\n";
  }
}

