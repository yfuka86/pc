#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (ll i=(ll)from; i<(ll)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (ll i=(ll)N-1; i>=0; i--)
#define popcount __builtin_popcount

const ll LLINF = pow(2,61)-1;
const ll INF = pow(2,30)-1;

ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

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

int main() {
  ll N, M; cin >> N >> M;
  vector<ll> A(M), B(M);
  rep(i,M) { cin >> A[i] >> B[i]; A[i]--; B[i]--; }

  vector<vector<ll>> adj(N);
  rep(i,M) adj[A[i]].push_back(B[i]);

  UnionFind uf(N);
  vector<ll> result(N);
  ll now = 0;
  for (ll i=N-1; i>0; i--) {
    now++;
    for (auto x: adj[i]) {
      if (uf.same(i,x)) continue;
      uf.unite(i,x);
      now--;
    }
    result[i-1] = now;
  }

  debug(all(result));
  return 0;
}
