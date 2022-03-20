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
const ll mod = 998244353;

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


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll H, W, K;
  cin >> H >> W >> K;

  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  vector<vector<modint>> dp(K + 1, vector<modint>(4, modint(0)));

  if (x1 != x2 && y1 != y2) {
    dp[0][3] = 1;
  } else if (x1 == x2 && y1 == y2) {
    dp[0][0] = 1;
  } else if (x1 == x2 && y1 != y2) {
    dp[0][1] = 1;
  } else if (x1 != x2 && y1 == y2) {
    dp[0][2] = 1;
  }

  rep2(i, 1, K + 1) {
    dp[i][0] += dp[i-1][1] + dp[i-1][2];
    dp[i][1] += dp[i-1][0] * modint(W - 1) + dp[i-1][1] * modint(W - 2) + dp[i-1][3];
    dp[i][2] += dp[i-1][0] * modint(H - 1) + dp[i-1][2] * modint(H - 2) + dp[i-1][3];
    dp[i][3] += dp[i-1][1] * modint(H - 1) + dp[i-1][2] * modint(W - 1) + dp[i-1][3] * (modint(H - 2) + modint(W - 2));
  }

  // coutmatrix(dp);
  cout << (dp[K][0]) << "\n";
}

