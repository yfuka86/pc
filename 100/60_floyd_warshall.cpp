// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja

#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = numeric_limits<int>::max();

int main()
{
  int V, E;
  cin >> V >> E;

  vector<vector<int> > G(V, vector<int>(V, INF));
  rep(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s][t] = d;
  }

  vector<vector<int> > costs(V, vector<int>(V, INF));
  rep(j, V) {
    rep(k, V) {
      if (j == k) costs[j][k] = 0;
      if (G[j][k] != INF) costs[j][k] = G[j][k];
    }
  }

  rep(i, V) {
    rep(j, V) {
      rep(k, V) {
        int new_cost = (costs[j][i] == INF || costs[i][k] == INF) ? INF : costs[j][i] + costs[i][k];
        if (costs[j][k] > new_cost) {
          costs[j][k] = new_cost;
        }
      }
    }
  }

  rep(i, V) {
    if (costs[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  rep(i, V) {
    rep(j, V) {
      if (costs[i][j] == INF) {
        cout << "INF";
      } else {
        cout << costs[i][j];
      }
      if (j != V - 1) cout << " ";
    }
    cout << endl;
  }
}

