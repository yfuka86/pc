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
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
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
const ll MOD = 998244353;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }


ll mod_pow(ll x, ll k)
{
  ll res = 1;
  for (; k; k /= 2, x = x * x % MOD) if (k & 1) res = res * x % MOD;
  return res;
}

ll factpow(ll n, ll k) {
  ll ret = 1;
  rep(i, k) {
    ret = ret * (n - i) % MOD;
  }
  return ret;
}

int main()
{
  ll N, K;
  cin >> N >> K;
  vi A(N);
  rep(i, N) cin >> A[i];

  vector<ll> dp(N, 0);
  dp[0] = 1;

  rep(i, N) {
    dp[i + 1] += dp[i] * A[i] % MOD;
  }

  ll ans = 0;
  rep(i, N + 1) {
    if (N - i <= K) {
      ans += dp[i] * factpow(K, N - i) % MOD * mod_pow(N, K - (N - i)) % MOD;
      ans = ans % MOD;
    }
  }
  cout << (ans * mod_pow(mod_pow(N, K), MOD - 2) % MOD) << endl;
}

