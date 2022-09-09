#pragma GCC optimize("Ofast")
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
#include <cassert>
#include <bitset>
#include <numeric>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
int ceil_pow2(int n) { int x = 0; while ((1U << x) < (unsigned int)(n)) x++; return x; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
// template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
// template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };

vector<vi> G;
vi depth;
vector<vi> ancestors;

void dfs(int v, int prev, int d = -1) {
  if (ancestors[v].size() > 0) return;
  d++; depth[v] = d;

  // 再帰的にancestor追加
  ancestors[v].pb(prev);
  for(int i = 0; d > (1 << (i + 1)); i++) {
    prev = ancestors[prev][i];
    ancestors[v].pb(prev);
  }
  rep(i, G[v].size()) {
    dfs(G[v][i], v, d);
  }
}

int lca(int u, int v) {
  // if (debug) cout << u << ":" << v << "; " << endl;
  // if (debug) coutarray(ancestors[u]);
  // if (debug) coutarray(ancestors[v]);
  if (u == v) return u;
  rep(i, ancestors[u].size()){
    if (ancestors[u][i] == ancestors[v][i]) {
      if (i == 0) {
        return ancestors[u][i];
      } else {
        return lca(ancestors[u][i - 1], ancestors[v][i - 1]);
      }
    }
  }
  return lca(ancestors[u].back(), ancestors[v].back());
}

int main()
{
  ios::sync_with_stdio(false);

  int N; cin >> N;
  G.resize(N); depth.resize(N); ancestors.resize(N);
  G.assign(N, vi(0));
  ancestors.assign(N, vi(0));
  depth.assign(N, -1);
  rep(i, N) {
    int k; cin >> k;
    rep(j, k) { int c; cin >> c; G[i].pb(c); }
  }
  dfs(0, {});
  // coutmatrix(ancestors);

  int Q; cin >> Q;
  rep(i, Q) {
    int u, v; cin >> u >> v;
    if (depth[u] < depth[v]) swap(u, v);

    while(depth[u] > depth[v]) {
      rep(i, ancestors[u].size()) {
        if (depth[ancestors[u][i]] >= depth[v]) { u = ancestors[u][i]; } else break;
      }
    }
    assert(depth[u] == depth[v]);
    cout << lca(u, v) << "\n";


    // rep(j, ancestors[u].size()) {
    //   if (ancestors[u][j] != ancestors[v][j]) {
    //     cout << ancestors[u][j - 1] << "\n";
    //     break;
    //   }
    //   if (j == ancestors[u].size() - 1) cout << ancestors[u].back() << "\n";
    // }
  }
}


