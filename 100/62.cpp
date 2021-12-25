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
const int INF = 1e9;
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
  int H, W;
  cin >> H >> W;

  vector<vi> G(10, vi(10, INF));

  rep(i, 10) rep(j, 10) cin >> G[i][j];
  rep(k, 10) rep(i, 10) rep(j, 10) chmin(G[i][j], G[i][k] + G[k][j]);

  int sum = 0;
  rep(i, H) {
    rep(j, W) {
      int t; cin >> t;
      if (t == 1 || t == -1) continue;
      sum += G[t][1];
    }
  }
  cout << sum << endl;
}

