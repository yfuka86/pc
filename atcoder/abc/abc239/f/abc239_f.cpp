#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
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

void solve() {
  ll N, M; cin >> N >> M;
  vl d(N); rep(i, N) cin >> d[i];
  if (accumulate(all(d), 0LL) != 2 * (N - 1)) { cout << "-1" << "\n"; return; }

  vl deg(N, 0);
  vector<vl> G(N);
  UnionFind un(N);
  rep(i, M) {
    ll a, b; cin >> a >> b; a--; b--;
    G[a].pb(b);
    G[b].pb(a);
    deg[a]++;
    deg[b]++;
    un.unite(a, b);
  }
  vl rem(N, 0);
  map<ll, vl> connected;
  rep(i, N) {
    rep(j, d[i] - deg[i]) {
      connected[un.root(i)].pb(i);
    }
  }
  vector<pair<ll, vl>> one, more;
  for(auto [v, li]: connected) {
    if (li.size() == 0) continue;
    if (li.size() == 1) one.pb(mp(v, li)); else more.pb(mp(v, li));
  }

  // -----------------------------------------
  vector<LP> ans;

  while(more.size() > 0) {
    auto [v, li] = more.back(); more.pop_back();
    while(li.size() > 1) {
      if (one.size() == 0) { cout << "-1" << "\n"; return; }
      auto [_, o] = one.back(); one.pop_back();
      un.unite(li.back(), o.back());
      ans.pb(mp(li.back(), o.back()));
      li.pop_back();
    }
    ll newroot = un.root(v);
    one.pb(mp(newroot, li));
  }

  if (one.size() != 2) { cout << "-1" << "\n"; return; }

  ll v1 = one[0].second.back(), v2 = one[1].second.back();
  ans.pb(mp(v1, v2));
  un.unite(v1, v2);

  if (un.size(0) == N && ans.size() == N - M - 1) {
    rep(i, N - M - 1) {
      cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
  } else {
    cout << "-1" << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
