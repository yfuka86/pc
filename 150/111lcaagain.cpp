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
int floor_pow2(int n) { int x = 0; while ((1U << (x + 1)) <= (unsigned int)(n)) x++; return x; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
// template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
// template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };


vector<vl> G;
vector<vl> par;
vl depths;

void dfs(ll v, ll prev, ll depth) {
  if (depths[v] != -1) return; // Already found
  if (prev != -1) {
    par[v].pb(prev);
    while (true) {
      vl grand_par = par[par[v].back()]; ll parsize = par[v].size() - 1;
      if ((ll)grand_par.size() > parsize) { par[v].pb(grand_par[parsize]); } else break; }
  }
  depths[v] = depth;
  // for(ll next: G[v]) dfs(next, v, depth + 1);
  rep(i, G[v].size()) {dfs(G[v][i], v, depth + 1);}
};
void dfs_init() { dfs(0, -1, 0); }

ll lca(ll n1, ll n2) {
  if (depths[n1] < depths[n2]) swap(n1, n2); while (depths[n1] != depths[n2]) n1 = par[n1][floor_pow2(depths[n1] - depths[n2])];
  assert(depths[n1] == depths[n2]);

  if (n1 == n2) return n1; if (par[n1][0] == par[n2][0]) return par[n1][0];
  rep(c, par[n1].size()) if (par[n1][c] == par[n2][c]) return lca(par[n1][c - 1], par[n2][c - 1]);
  return lca(par[n1].back(), par[n2].back()); // trace back to the different parents
}

int main()
{
  ios::sync_with_stdio(false);

  ll N; cin >> N;
  G.resize(N); par.resize(N); depths.resize(N); depths.assign(N, -1);
  rep(i, N) {
    ll k; cin >> k;
    rep(j, k) { ll c; cin >> c; G[i].pb(c); }
  }
  dfs_init();

  // Doubling dfs completed

  ll Q; cin >> Q;
  vl a(Q), b(Q);
  rep(i, Q) {
    cin >> a[i] >> b[i];
  }
  rep(i, Q) {
    cout << lca(a[i], b[i]) << "\n";
  }
}
