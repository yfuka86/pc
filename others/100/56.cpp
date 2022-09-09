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

struct Edge {
  int to, cost;
};
const int INF = numeric_limits<int>::max();

vector<vector<Edge> > graph_input(int n, int m) {
  vector<vector<Edge> > G(n);
  rep(i, m) {
    int a, b, d;
    cin >> a >> b >> d;
    Edge e = {b, d};
    G[a].push_back(e);
  }
  return G;
}

// PQは降順に処理される

int main()
{
  int V, E, r;
  cin >> V >> E >> r;

  vector<vector<Edge> > G(V);
  G = graph_input(V, E);

  priority_queue<P> PQ;
  vector<int> costs(V, INF);

  PQ.push(make_pair(0, r));

  while(!PQ.empty()) {
    P p = PQ.top(); PQ.pop();
    int v = p.second;
    if(costs[v] <= -p.first) continue;
    costs[v] = -p.first;

    rep(i, G[v].size()) {
      Edge e = G[v][i];
      if (costs[e.to] > costs[v] + e.cost) {
        PQ.push(make_pair(-(costs[v] + e.cost), e.to));
      }
    }
  }

  rep(i, V) {
    if (costs[i] == INF) {
      cout << "INF" << endl;
    } else {
      cout << costs[i] << endl;
    }
  }
}

