// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja

#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <bitset>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = numeric_limits<int>::max();

using namespace std;

int V, E;
vector<vector<int> > G;
int dp[1 << 16][16];

template <class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }

int cost(int set, int v) {
  dp[0][0] = 0;
  if (set == 0) {
    if (v == 0) {
      return 0;
    } else {
      return INF;
    }
  }
  if ((set & (1 << v)) == 0) return INF;

  int &ret = dp[set][v];
  if (ret != 0) return ret;
  ret = INF;
  rep(u, V) {
    int prev_cost = cost(set ^ (1 << v), u);
    if (prev_cost == INF || G[u][v] == INF) {
      chmin(ret, INF);
    } else {
      chmin(ret, prev_cost + G[u][v]);
    }
  }
  return ret;
}

int main()
{
  cin >> V >> E;
  G.resize(V);
  G.assign(V, vector<int>(V, INF));

  rep(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s][t] = d;
  }

  int ans = cost((1 << V) - 1, 0);

  if (ans != INF) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}

