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

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
void comp(vector<int>&a){ vector<int> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T>
void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T>
void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };
template<typename K, typename V>
void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N;
  cin >> N;
  vector<LP> x(N), y(N);
  vector<pair<ll, LP>> edges;

  rep(i, N) {
    ll m, n; cin >> m >> n;
    x[i] = make_pair(m, i);
    y[i] = make_pair(n, i);
  }

  sort(all(x));
  sort(all(y));

  rep2(i, 1, N) {
    ll costx = x[i].first - x[i - 1].first;
    edges.pb(make_pair(costx, make_pair(x[i].second, x[i - 1].second)));
    ll costy = y[i].first - y[i - 1].first;
    edges.pb(make_pair(costy, make_pair(y[i].second, y[i - 1].second)));
  }
  sort(all(edges));

  UnionFind un(N);
  ll sum = 0;
  for (pair<ll, LP> p: edges) {
    ll a = p.second.first;
    ll b = p.second.second;
    if (un.same(a, b)) continue;
    un.unite(a, b);
    sum += p.first;
  }

  cout << sum << "\n";
}

