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

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

struct Edge {
  int to, cost;
};
int N, M, K, S;
vector<vector<int>> R;
vector<vector<Edge>> G;
vector<int> danger;

vector<ll> dijkstra(ll start) {
  priority_queue<LP> PQ;
  vector<ll> costs(G.size(), INF);

  PQ.push(make_pair(0, start));

  while(!PQ.empty()) {
    LP p = PQ.top(); PQ.pop();
    ll prev_cost = -p.first;
    ll v = p.second;
    if(costs[v] <= prev_cost) continue;
    costs[v] = prev_cost;

    rep(i, G[v].size()) {
      Edge e = G[v][i];
      ll next_cost = costs[v] + e.cost;
      if (costs[e.to] > next_cost) {
        PQ.push(make_pair(-next_cost, e.to));
      }
    }
  }
  return costs;
}

int main()
{
  cin >> N >> M >> K >> S;
  int P, Q;
  cin >> P >> Q;

  R.resize(N);
  G.resize(N);
  danger.resize(N);
  danger.assign(N, INF);

  queue<int> que;
  rep(i, K) {
    int t; cin >> t; t--;
    danger[t] = 0;
    que.push(t);
  }
  rep(i, M) {
    int a, b;
    cin >> a >> b; a--; b--;
    R[a].pb(b);
    R[b].pb(a);
  }
  while(!que.empty()) {
    int t = que.front(); que.pop();
    int cost = danger[t];
    for (int next: R[t]) {
      if (cost + 1 < danger[next]) {
        danger[next] = cost + 1;
        que.push(next);
      }
    }
  }

  rep(i, N) {
    for(int to: R[i]) {
      if (danger[to] == 0) continue;
      if (to == N - 1) {
        G[i].pb({to, 0});
      } else if (danger[to] <= S) {
        G[i].pb({to, Q});
      } else {
        G[i].pb({to, P});
      }
    }
  }

  vector<ll> costs = dijkstra(0);
  cout << costs[N - 1] << endl;
}

