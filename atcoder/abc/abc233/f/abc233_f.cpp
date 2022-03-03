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
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template <class T> T POW(T x, int n) { assert(n >= 0); T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
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
  ll N; cin >> N;
  vl p(N); rep(i, N) { cin >> p[i]; p[i]--; }

  ll M; cin >> M;
  vector<LP> op(M);
  vector<vector<LP>> G(N);
  UnionFind un(N);
  rep(i, M) {
    ll a, b; cin >> a >> b; a--; b--;
    op[i] = mp(a, b);
    G[a].pb(mp(b, i));
    G[b].pb(mp(a, i));
    un.unite(a, b);
  }

  rep(i, N) { if (!un.same(p[i], i)) { cout << "-1" << "\n"; return; } }

  vl depth(N, -1); vector<LP> par(N);
  function<void(LP, ll, ll)> dfs = [&](LP p, ll d, ll v)-> void {
    if (depth[v] != -1) return;
    par[v] = p;
    depth[v] = d;
    for (auto [next, id]: G[v]) {
      if (next == p.first) continue;
      dfs(mp(v, id), d + 1, next);
    }
  };
  rep(i, N) { if (depth[i] == -1) dfs(mp(-1, -1), 0, i); }

  function<vl(ll, ll)> getpath = [&](ll from, ll to) -> vl {
    vl vf, vt;
    while (from != to) {
      if (depth[from] > depth[to]) {
        auto [p, id] = par[from];
        vf.pb(id); from = p;
      } else {
        auto [p, id] = par[to];
        vt.pb(id); to = p;
      }
    }
    reverse(all(vt));
    vf.insert(vf.end(), vt.begin(), vt.end());
    return vf;
  };

  vector<vl> ans;
  vector<LP> depthinv(N);
  rep(i, N) depthinv[i] = mp(depth[i], i);
  sort(all(depthinv)); reverse(all(depthinv));
  for(auto [_, i]: depthinv) {
    if (i != p[i]) {
      ll from = find(all(p), i) - p.begin();
      vl path = getpath(from, i);
      ans.pb(path);
      for (ll id: path) {
        auto [a, b] = op[id];
        swap(p[a], p[b]);
      }
    }
  }

  vl a;
  for(vl v: ans) {
    for (ll id: v) {
      a.pb(id);
    }
  }
  cout << a.size() << "\n";
  coutarray(a, 1);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
