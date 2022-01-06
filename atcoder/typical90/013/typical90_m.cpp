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
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
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

vector<ll> dijkstra(vector<vector<Edge>>& G, ll start) {
  priority_queue<LP> PQ;
  vector<ll> costs(G.size(), LINF);

  PQ.push(make_pair(0, start));

  while(!PQ.empty()) {
    LP p = PQ.top(); PQ.pop();
    ll prev_cost = -p.first;
    ll v = p.second;
    if(costs[v] <= prev_cost) continue;
    costs[v] = prev_cost;

    rep(i, G[v].size()) {
      Edge e = G[v][i];
      ll next_cost = costs[v] + e.cost;
      if (costs[e.to] > next_cost) {
        PQ.push(make_pair(-next_cost, e.to));
      }
    }
  }
  return costs;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M;
  cin >> N >> M;
  vector<vector<Edge>> G(N);
  rep(i, M) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    G[a].pb({b, c});
    G[b].pb({a, c});
  }

  vl cost1 = dijkstra(G, 0);
  vl cost2 = dijkstra(G, N - 1);

  rep(i, N) {
    cout << cost1[i] + cost2[i] << "\n";
  }
}


