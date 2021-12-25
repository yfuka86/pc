#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

vector<vector<int>> G;
vector<ll> results;

void dfs(int v, int parent) {
  if (parent != -1) results[v] += results[parent];
  for(int i : G[v]) {
    dfs(i, v);
  }
}

int main()
{
  int n, q;
  cin >> n >> q;
  G.resize(n);
  results.resize(n);
  rep(i, n) {
    G[i] = {};
    results[i] = 0;
  }

  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    G[a - 1].push_back(b - 1);
  }

  rep(i, q) {
    int p, x;
    cin >> p >> x;
    results[p - 1] += x;
  }

  dfs(0, -1);

  rep(i, n) cout << results[i] << " ";
  cout << endl;
}
