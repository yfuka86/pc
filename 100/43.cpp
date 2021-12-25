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

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  vector<char> colors = { 'R', 'B', 'W', '#' };

  int N;
  cin >> N;
  vector<vi> original(N, vi(5));
  vector<vi> dp(N, vi(3, 0));

  rep(i, 5) {
    string s; cin >> s;
    rep(j, N) {
      rep(k, 4) {
        if (s[j] == colors[k]) original[j][i] = k;
      }
    }
  }

  rep(i, N) {
    rep(j, 3) {
      int c = 5 - count(all(original[i]), j);

      int beforemin = INF;
      if (i > 0) {
        rep(k, 3) {
          if (j == k) continue;
          chmin(beforemin, dp[i - 1][k]);
        }
      } else beforemin = 0;

      dp[i][j] = beforemin + c;
    }
  }

  int mi = INF;
  rep(i, 3) chmin(mi, dp[N - 1][i]);
  cout << mi << endl;
}

