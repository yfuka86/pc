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
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N; cin >> N;
  vector<vl> G(N);
  rep(i, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    G[a].pb(b);
    G[b].pb(a);
  }
  vector<vl> par(N);
  vl depths(N, -1);

  function<void(ll, ll, ll)> dfs = [&](ll v, ll prev, ll depth) -> void {
    if (depths[v] != -1) return; // Already found
    if (prev != -1) {
      par[v].pb(prev);
      while (true) {
        vl grand_par = par[par[v].back()];
        ll parsize = par[v].size() - 1;
        if (grand_par.size() > parsize) { par[v].pb(grand_par[parsize]); } else break;
      }
    }
    depths[v] = depth;
    for(ll next: G[v]) {
      dfs(next, v, depth + 1);
    }
  };
  dfs(0, -1, 0);

  // Doubling dfs completed

  ll Q; cin >> Q;
  rep(i, Q) {
    ll a, b; cin >> a >> b; a--; b--;
    ll n1 = a, n2 = b;
    if (depths[n1] < depths[n2]) swap(n1, n2);
    // To make depths be the same
    while (depths[n1] != depths[n2]) {
      n1 = par[n1][floor_pow2(depths[n1] - depths[n2])];
    }

    ll lca = n1;
    while (n1 != n2) {
      if (par[n1][0] == par[n2][0]) { lca = par[n1][0]; break; }
      // trace back to the different parents;
      ll next1, next2;
      rep(c, par[n1].size()) if (par[n1][c] != par[n2][c]) { next1 = par[n1][c]; next2 = par[n2][c]; }
      n1 = next1; n2 = next2;
    }

    ll ans = depths[a] - depths[lca] + depths[b] - depths[lca] + 1;
    cout << ans << "\n";
  }
}


