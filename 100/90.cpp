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
const double DINF = numeric_limits<double>::infinity();
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
  int N, M;
  cin >> N >> M;

  vi X(N); vi Y(N); vector<double> R(N);
  rep(i, N) cin >> X[i] >> Y[i] >> R[i];

  vi XM(M); vi YM(M); vector<double> RM(M, DINF);
  rep(i, M) cin >> XM[i] >> YM[i];

  rep(i, M) {
    rep (j, N) {
      double xdiff = X[j] - XM[i];
      double ydiff = Y[j] - YM[i];
      chmin(RM[i], sqrt(xdiff * xdiff + ydiff * ydiff) - R[j]);
    }
  }

  rep(i, M) {
    rep (j, M) {
      if (i == j) continue;
      double xdiff = XM[j] - XM[i];
      double ydiff = YM[j] - YM[i];
      double d = sqrt(xdiff * xdiff + ydiff * ydiff);
      double half = d / 2;
      if (RM[i] > half && RM[j] > half) {
        RM[i] = half;
        RM[j] = half;
      } else if (RM[i] + RM[j] > d) {
        if (RM[i] > RM[j]) RM[i] = d - RM[j];
        if (RM[j] > RM[i]) RM[j] = d - RM[i];
      }
    }
  }

  double ans = DINF;

  rep(i, N) chmin(ans, R[i]);
  rep(i, M) chmin(ans, RM[i]);
  cout << fixed << setprecision(7) << ans << endl;
}

