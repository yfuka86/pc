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
typedef long long ll; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 3;
const ll LINF = LLONG_MAX / 3;
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
vector<vl> G, par; vl fs, ls, depth; ll cur = 0;
void dfs(ll v, ll p, ll d) {
  if (depth[v] != -1) return; // Already found
  if (p != -1) { par[v].pb(p); while (true) { vl &grand_par = par[par[v].back()]; ll parsize = par[v].size() - 1; if ((ll)grand_par.size() > parsize) { par[v].pb(grand_par[parsize]); } else break; } } // LCA doubling

  depth[v] = d; fs[v] = cur++;
  for(ll next: G[v]) {
    dfs(next, v, d + 1);
    cur++;
  }
  ls[v] = cur - 1;
};
void dfs_init(ll n) {
  par.resize(n); fs.resize(n); ls.resize(n); depth.resize(n); depth.assign(n, -1); cur = 0;
  dfs(0, -1, 0); cur = 0;
}

ll lca(ll n1, ll n2) {
  if (depth[n1] < depth[n2]) swap(n1, n2); while (depth[n1] != depth[n2]) n1 = par[n1][floor_pow2(depth[n1] - depth[n2])]; assert(depth[n1] == depth[n2]);
  if (n1 == n2) return n1; if (par[n1][0] == par[n2][0]) return par[n1][0]; rep(c, par[n1].size()) if (par[n1][c] == par[n2][c]) return lca(par[n1][c - 1], par[n2][c - 1]); return lca(par[n1].back(), par[n2].back()); // trace back to the different parents
}

ll dist(ll n1, ll n2) { return depth[n1] + depth[n2] - 2 * depth[lca(n1, n2)]; }
//------------------------------------------------------------------------------


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N; cin >> N; G.resize(N);
  rep(i, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    G[a].pb(b); G[b].pb(a);
  }
  dfs_init(N);

  ll Q; cin >> Q;
  rep(i, Q) {
    ll K; cin >> K; vl V(K);
    rep(j, K) { cin >> V[j]; V[j]--; }

    vector<LP> vp(K);
    rep(i, K) {
      vp[i] = make_pair(fs[V[i]], V[i]);
    }
    sort(all(vp));

    ll ans = 0;
    rep(i, K - 1) {
      ans += dist(vp[i].second, vp[i + 1].second);
    }
    ans += dist(vp.back().second, vp[0].second);

    cout << ans / 2 << "\n";
  }
}


