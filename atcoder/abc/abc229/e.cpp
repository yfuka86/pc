#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;
  for (auto e : G[v]) {
    if (!seen[e.to]) {
      dfs(G, e.to);
    }
  }
}

int main()
{
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back({b});
  }

  rep(i, N) {
    seen.assign(N, false);
    int cnt = 0;
    for (int j = i; j < N; j++) {
      if (!seen[j]) {
        dfs(G, j);
        cnt++;
      }
    }
    if (i != 0) cout << cnt << endl;
    G[i] = {};
  }
  cout << 0 << endl;
}

