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
#include <bitset>
#include <numeric>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep_r(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(int i=sta;i<(int)(n);i++)
#define rep2_r(i,sta,n) for(int i=(int)(n)-1;i>=0;i--)
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
const ll mod = 1000000007;

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

struct UnionFind {
  vector<ll> par, s, e;
  UnionFind(ll N) : par(N), s(N), e(N) { rep(i,N) { par[i] = i; s[i] = 1; e[i] = 0; } }
  ll root(ll x) { return par[x]==x ? x : par[x] = root(par[x]); }
  ll size(ll x) { return par[x]==x ? s[x] : s[x] = size(root(x)); }
  ll edge(ll x) { return par[x]==x ? e[x] : e[x] = edge(root(x)); }
  void unite(ll x, ll y) { ll rx=root(x), ry=root(y); if (size(rx)<size(ry)) swap(rx,ry); if (rx!=ry) { s[rx] += s[ry]; par[ry] = rx; e[rx] += e[ry]+1; } else e[rx]++; }
  bool same(ll x, ll y) {  ll rx=root(x), ry=root(y); return rx==ry; }
};

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

struct Cell {
  ld x, y, z, r;
};

pair<ld, LP> path(ll i1, ll i2, Cell c1, Cell c2) {
  ld x, y, z;
  x = c1.x - c2.x;
  y = c1.y - c2.y;
  z = c1.z - c2.z;
  ld diff = sqrt(x * x + y * y + z * z) - (c1.r + c2.r);
  if (diff <= 0) {
    return make_pair(0, make_pair(i1, i2));
  } else {
    return make_pair(diff, make_pair(i1, i2));
  }
}

int main()
{
  ios::sync_with_stdio(false);

  while(true) {
    ll N;
    cin >> N;
    if (N == 0) break;
    vector<Cell> cells(N);
    vector<pair<ld, LP> > edges;
    rep(i, N) {
      ld x, y, z, r;
      cin >> x >> y >> z >> r;
      cells[i] = {x, y, z, r};
    }

    rep(i, N) {
      rep(j, N) {
        if (i == j) continue;
        edges.pb(path(i, j, cells[i], cells[j]));
      }
    }
    sort(all(edges));

    // rep(i, edges.size()) {
    //   cout << edges[i].first << " " << edges[i].second.first << " " << edges[i].second.second << endl;
    // }

    UnionFind un(N);
    ld cost = 0;
    rep(i, edges.size()) {
      LP path = edges[i].second;
      if (!un.same(path.first, path.second)) {
        un.unite(path.first, path.second);
        cost += edges[i].first;
      }
    }

    cout << fixed << setprecision(3) << cost << "\n";
  }
}

