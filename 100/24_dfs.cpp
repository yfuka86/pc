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

using namespace std;

vector<vector<int> > G;
vector<P> results;
int t = 0;

void dfs(int v) {
  t++;
  if (results[v].first == 0) results[v].first = t;

  rep(i, G[v].size()) {
    if (results[G[v][i]].first == 0) {
      dfs(G[v][i]);
    }
  }

  t++;
  if (results[v].second < t) results[v].second = t;
}

int main()
{
  int N;
  cin >> N;
  G.resize(N);
  G.assign(N, vector<int>(0));
  results.resize(N);
  rep(i, N) {
    int u, k;
    cin >> u >> k; u--;
    rep(j, k) {
      int a;
      cin >> a; a--;
      G[i].push_back(a);
    }
    results[i] = make_pair(0, 0);
  }

  dfs(0);
  while (find(all(results), make_pair(0, 0)) != results.end()) {
    dfs(find(all(results), make_pair(0, 0)) - results.begin());
  }

  rep(i, N) {
    cout << i + 1 << " " << results[i].first << " " << results[i].second << endl;
  }
}
