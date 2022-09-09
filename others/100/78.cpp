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
  int M, N, K;
  cin >> M >> N >> K;
  vector<vector<vector<int>>> sums(3, vector<vector<int>>(M, vector<int>(N, 0)));
  vector<char> c = {'J', 'O', 'I'};

  rep(i, M) {
    string s; cin >> s;
    rep(j, N) {
      rep(k, 3) {
        int sum = 0;
        if (s[j] == c[k]) sum++;
        if (i > 0) sum += sums[k][i - 1][j];
        if (j > 0) sum += sums[k][i][j - 1];
        if (i > 0 && j > 0) sum -= sums[k][i - 1][j - 1];
        sums[k][i][j] = sum;
      }
    }
  }

  rep(_, K) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2; x1--; y1--; x2--; y2--;

    rep(i, 3) {
      vector<vector<int>> &l = sums[i];
      int sum = l[x2][y2];
      if (x1 > 0) sum -= l[x1 - 1][y2];
      if (y1 > 0) sum -= l[x2][y1 - 1];
      if (x1 > 0 && y1 > 0) sum += l[x1 - 1][y1 - 1];

      cout << sum;
      if (i == 2) { cout << endl; } else { cout << " "; };
    }
  }

  return 0;
}

