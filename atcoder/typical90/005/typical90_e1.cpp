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
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
void comp(vector<int>&a){ vector<int> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T>
void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T>
void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V>
void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

//------------------------------------------------------------------------------
const ll mod = 1000000007;
struct modint { int n; modint() :n(0) { ; } modint(ll m) { if (m < 0 || mod <= m) { m %= mod; if (m < 0)m += mod; } n = m; } operator int() { return n; } };
typedef vector<modint> vmi;
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) { if (n == 0) return modint(1); modint res = (a * a) ^ (n / 2); if (n % 2) res = res * a; return res; }
ll inv(ll a, ll p) { return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p); }
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
ll mod_pow(ll x, ll n, ll m = mod) {
  if (n < 0) { ll res = mod_pow(x, -n, m); return mod_pow(res, m - 2, m); }
  if (abs(x) >= m) x %= m; if (x < 0) x += m; if (x == 0) return 0;
  ll res = 1; while (n) { if (n & 1) res = res * x % m; x = x * x % m; n >>= 1; } return res; }
//------------------------------------------------------------------------------

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, B, K;
  cin >> N >> B >> K;
  vl available(K); rep(i, K) cin >> available[i];
  ll pow2 = ceil_pow2(N) + 1;

  vl p10(pow2);
  rep(i, pow2) p10[i] = mod_pow(10LL, 1LL << i, B);

  vector<vmi> dp(pow2, vmi(B, modint(0)));
  rep(i, K) dp[0][available[i] % B] += modint(1);

  rep(i, pow2 - 1) {
    rep(j, B) {
      rep(k, B) {
        dp[i + 1][(j * p10[i] + k) % B] += dp[i][j] * dp[i][k];
      }
    }
  }

  // coutmatrix(dp);

  vector<vmi> ans(pow2 + 1, vmi(B, modint(0)));
  ans[0][0] = 1;
  rep(i, pow2) {
    if (N & 1LL << i) {
      rep(j, B) {
        rep(k, B) {
          ans[i + 1][(j * p10[i] + k) % B] += ans[i][j] * dp[i][k];
        }
      }
    } else {
      rep(j, B) ans[i + 1][j] = ans[i][j];
    }
  }
  // coutmatrix(ans);

  cout << ans[pow2][0] << "\n";
}


