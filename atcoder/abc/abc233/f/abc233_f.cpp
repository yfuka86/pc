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
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
//------------------------------------------------------------------------------
struct UnionFind {
  vector<ll> par, s, e;
  UnionFind(ll N) : par(N), s(N), e(N) { rep(i,N) { par[i] = i; s[i] = 1; e[i] = 0; } }
  ll root(ll x) { return par[x]==x ? x : par[x] = root(par[x]); }
  ll size(ll x) { return par[x]==x ? s[x] : s[x] = size(root(x)); }
  ll edge(ll x) { return par[x]==x ? e[x] : e[x] = edge(root(x)); }
  void unite(ll x, ll y) { ll rx=root(x), ry=root(y); if (size(rx)<size(ry)) swap(rx,ry); if (rx!=ry) { s[rx] += s[ry]; par[ry] = rx; e[rx] += e[ry]+1; } else e[rx]++; }
  bool same(ll x, ll y) {  ll rx=root(x), ry=root(y); return rx==ry; }
};
//------------------------------------------------------------------------------

struct Edge {
  ll to, id;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M;
  cin >> N;
  vl P(N), invP(N);
  rep(i, N){ cin >> P[i]; P[i]--; invP[P[i]] = i; }

  cin >> M;
  vector<vector<Edge>> G(N);
  UnionFind un(N);
  rep(i, M) {
    ll a, b; cin >> a >> b; a--; b--;
    G[a].pb({b, i});
    G[b].pb({a, i});
    un.unite(a, b);
  }

  vector<Edge> par(N);
  vl depth(N, -1);
  priority_queue<LP> que;
  function<void(ll, Edge, ll)> dfs = [&](ll v, Edge p, ll d) -> void {
    if (depth[v] != -1) return;
    depth[v] = d;
    par[v] = p;
    if (d > 0) que.push(make_pair(d, v));
    for (Edge next: G[v]) {
      dfs(next.to, {v, next.id}, d + 1);
    }
  };

  rep(i, N) {
    if (!un.same(i, P[i])) { cout << "-1" << "\n"; return 0; }
    if (depth[i] != -1) continue;
    dfs(un.root(i), { -1, -1 }, 0);
  }

  // cout << "dfsend" << endl;

  vector<bool> comp(N);
  vl ans;
  while(!que.empty()) {
    LP p = que.top(); que.pop();
    ll v1 = p.second, v2 = invP[p.second];
    comp[v1] = true;
    if (v1 == v2) continue;
    // cout << depth[v1] << "   " << v1 << ":" << v2 << endl;
    vl p1, p2;
    while(comp[v2]) {
      Edge e = par[v2];
      v2 = e.to;
      if (v1 == v2) break;
    }
    while (depth[v1] > depth[v2]) {
      Edge e = par[v1];
      v1 = e.to; p1.pb(e.id);
    }
    while (depth[v1] < depth[v2]) {
      Edge e = par[v2];
      v2 = e.to; p2.pb(e.id);
    }
    while (v1 != v2) {
      Edge e1 = par[v1];
      Edge e2 = par[v2];
      v1 = e1.to; v2 = e2.to;
      p1.pb(e1.id); p2.pb(e2.id);
    }

    reverse(all(p1));
    // coutarray(p2);
    // coutarray(p1);
    ans.insert(ans.end(), p2.begin(), p2.end());
    ans.insert(ans.end(), p1.begin(), p1.end());
  }

  cout << ans.size() << "\n";
  rep(i, ans.size()) {
    cout << ans[i] + 1 << (i == ans.size() - 1 ? "\n" : " ");
  }
}


