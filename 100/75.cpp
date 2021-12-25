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
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define vi vector<int>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
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
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

ll mod_pow(ll x, ll n, ll m = mod) {
  if (n < 0) {
    ll res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m)x %= m;
  if (x < 0)x += m;
  if (x == 0)return 0;
  ll res = 1;
  while (n) {
    if (n & 1)res = res * x % m;
    x = x * x % m; n >>= 1;
  }
  return res;
}
struct modint {
  int n;
  modint() :n(0) { ; }
  modint(ll m) {
    if (m < 0 || mod <= m) {
      m %= mod; if (m < 0)m += mod;
    }
    n = m;
  }
  operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
  if (n == 0)return modint(1);
  modint res = (a * a) ^ (n / 2);
  if (n % 2)res = res * a;
  return res;
}

ll inv(ll a, ll p) {
  return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = modint(1);
  for (int i = 0; i < max_n - 1; i++) {
    fact[i + 1] = fact[i] * modint(i + 1);
  }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1];
  for (int i = max_n - 2; i >= 0; i--) {
    factinv[i] = factinv[i + 1] * modint(i + 1);
  }
}
modint comb(int a, int b) {
  if (a < 0 || b < 0 || a < b)return 0;
  return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
  if (a < 0 || b < 0 || a < b)return 0;
  return fact[a] * factinv[a - b];
}

vector<vi> G;
vector<vi> orders;
int d_count = 0;
void dfs(int i) {
  if (orders[i].size() > 0) return;
  d_count++;
  orders[i].pb(d_count);
  rep(j, G[i].size()){
    dfs(G[i][j]);
    orders[i].pb(d_count);
  }
}

modint prob(vector<int> &a) {
  const modint one = modint(1);
  const modint two = modint(2);
  vector<modint> not_exists(a.size());
  rep(i, a.size()) not_exists[i] = one / (two^a[i]);

  modint sum = 0;

  modint mul = 1;
  rep(i, a.size()) {
    mul *= not_exists[i];
  }
  sum += mul;

  rep(i, a.size()) {
    sum += mul / not_exists[i] * (one - not_exists[i]);
  }

  return (one - sum) / two;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; cin >> N; G.resize(N); orders.resize(N);
  rep(i, N - 1) {
    int a, b; cin >> a >> b; --a; --b;
    G[a].pb(b);
    G[b].pb(a);
  }
  dfs(0);

  modint ans = 0;
  rep(i, N) {
    int osize = orders[i].size();
    vi trees(osize, 0);
    Rep(j, 1, osize) {
      trees[j] = orders[i][j] - orders[i][j - 1];
    }
    trees[0] = N - (orders[i][osize - 1] - orders[i][0]) - 1;
    ans += prob(trees);
  }
  cout << ans << "\n";
}
