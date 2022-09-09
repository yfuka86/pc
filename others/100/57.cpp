#include <iostream>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

struct Edge {
  int to, cost;
};
const int INF = numeric_limits<int>::max();

vector<vector<Edge>> G;

vector<int> dijkstra(int start) {
  priority_queue<P> PQ;
  vector<int> costs(G.size(), INF);

  PQ.push(make_pair(0, start));

  while(!PQ.empty()) {
    pair<int, int> p = PQ.top(); PQ.pop();
    int prev_cost = -p.first;
    int v = p.second;
    if(costs[v] <= prev_cost) continue;
    costs[v] = prev_cost;

    rep(i, G[v].size()) {
      Edge e = G[v][i];
      int next_cost = costs[v] + e.cost;
      if (costs[e.to] > next_cost) {
        PQ.push(make_pair(-next_cost, e.to));
      }
    }
  }
  return costs;
}

int main()
{
  int N, K;
  cin >> N >> K;
  G.resize(N);

  rep(i, K) {
    int input_type; cin >> input_type;
    if (input_type == 1) {
      int c, d, e; cin >> c >> d >> e; c--; d--;
      G[c].push_back(Edge{d, e});
      G[d].push_back(Edge{c, e});
    } else {
      int a, b; cin >> a >> b; a--; b--;
      vector<int> costs = dijkstra(a);
      cout << (costs[b] == INF ? -1 : costs[b]) << endl;
    }
  }
}

