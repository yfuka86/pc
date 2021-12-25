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
const ll MOD = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

struct Edge {
  int to, cost;
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N, vector<int>(N, INF));

  rep(i, N) G[i][i] = 0;

  rep(i, M) {
    int a, b, t; cin >> a >> b >> t; a--; b--;
    G[a][b] = t;
    G[b][a] = t;
  }

  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        if (G[i][k] == INF || G[k][j] == INF) continue;
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }

  int mi = INF;
  rep(i, N) {
    int ma = 0;
    rep(j, N) {
      chmax(ma, G[i][j]);
    }
    chmin(mi, ma);
  }

  cout << mi << endl;
}
