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

struct Edge {
ll to, cost;
  bool operator<(const struct Edge& other) const {
    return cost < other.cost; }
};

vector<vl> floyd_warshall(vector<vector<Edge>> & G) {
  ll n = G.size(); vector<vl> costs(n, vl(n ,LINF));
  rep(i, n) { costs[i][i] = 0; for(Edge e: G[i]) costs[i][e.to] = e.cost; }

  rep(k, n) rep(i, n) rep(j, n) {
    if (costs[i][k] == LINF || costs[k][j] == LINF) continue;
    costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
  }
  return costs;
}

int main()
{
  int N, M; cin >> N >> M;
  vector<vector<Edge>> G(N);
  rep(i, M) {
    int a, b, t; cin >> a >> b >> t; a--; b--;
    G[a].pb({b, t});
    G[b].pb({a, t});
  }

  vector<vl> c = floyd_warshall(G);
  ll mi = LINF;
  rep(i, N) {
    ll ma = 0;
    rep(j, N) chmax(ma, c[i][j]);
    chmin(mi, ma);
  }
  cout << mi << endl;
}
