// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja
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

struct Edge {
  int from, to;
  bool operator<(const struct Edge& other) const
  {
    return from < other.from;
  }
};

typedef pair<int, Edge> P;

int main()
{
  priority_queue<P> PQ;
  int V, E;
  cin >> V >> E;
  rep(i, E) {
    int s, t, w;
    cin >> s >> t >> w;
    Edge e = {s, t};
    PQ.push(make_pair(-w, e));
  }

  vector<bool> included(V, false);
  ll cost = 0;
  vector<P> temp;
  bool first_time = true;

  while(!PQ.empty()) {
    P p = PQ.top(); PQ.pop();
    Edge e = p.second;

    if (included[e.from] && included[e.to]) continue;
    if (!first_time && !included[e.from] && !included[e.to]) {
      temp.push_back(make_pair(p.first, p.second));
      continue;
    }
    first_time = false;

    included[e.from] = true;
    included[e.to] = true;
    cost -= p.first;

    rep(i, temp.size()) {
      PQ.push(temp[i]);
    }
    temp.clear();

    bool all = true;
    rep(i, V) all = all && included[i];
    if (all) break;
  }
  cout << cost << endl;
}

