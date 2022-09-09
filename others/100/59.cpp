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
  vector<P> taxis(N);
  vector<vector<int>> R(N);
  G.resize(N);

  rep(i, N) {
    int c, r;
    cin >> c >> r;
    taxis[i] = make_pair(c, r);
  }
  rep(i, K) {
    int a, b; cin >> a >> b; a--; b--;
    R[a].pb(b);
    R[b].pb(a);
  }

  rep(i, N) {
    P taxi = taxis[i];
    queue<int> que;
    vector<int> costs(N, INF);
    costs[i] = 0;
    que.push(i);
    while (!que.empty()) {
      int p = que.front(); que.pop();
      int v = p; int cost = costs[p];
      if (cost == INF) continue;
      cost++;
      if (cost > taxi.second) continue;

      for(int next: R[v]) {
        if (costs[next] <= cost) continue;
        costs[next] = cost;
        que.push(next);
        G[i].pb(Edge{next, taxi.first});
      }
    }
  }
  // rep(i, N) {
  //   cout << i << "::::";
  //   for(Edge e: G[i]) {
  //     cout << e.to << ":" << e.cost << " ";
  //   }
  //   cout << endl;
  // }

  vector<int> costs = dijkstra(0);
  cout << costs[N - 1] << endl;
}

