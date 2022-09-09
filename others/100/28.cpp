// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja

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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;


vector<vector<int> > G;
vector<int> costs;
queue<int> que;

void bfs(int v) {
  rep(i, G[v].size()) {
    int next = G[v][i];
    if (costs[next] == -1) {
      costs[next] = costs[v] + 1;
      que.push(next);
    }
  }
};

int main()
{
  int n;
  cin >> n;
  G.resize(n);
  costs.resize(n);
  costs.assign(n, -1);

  rep(i, n) {
    int id, k; cin >> id >> k;
    rep(j, k) {
      int adj; cin >> adj; adj--;
      G[i].push_back(adj);
    }
  }

  costs[0] = 0;
  que.push(0);
  while(!que.empty()) {
    bfs(que.front());
    que.pop();
  }

  rep(i, n) {
    cout << i + 1 << " " << costs[i] << endl;
  }
}

