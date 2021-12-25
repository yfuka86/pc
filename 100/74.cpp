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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const ll MOD = 1000000007;

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

// どこまで計算するか
ll facs[200010] = { 1 };
ll mod_fact(int to) {
  if (facs[to]) return facs[to];

  rep2(i, 1, to + 1) {
    if (facs[i]) continue;
    facs[i] = facs[i - 1] * i % MOD;
  }
  return facs[to];
}

ll nCr(ll n, ll r)
{
  if (n<r || r<0) return 0;
  return (mod_fact(n) * mod_pow(mod_fact(r) , MOD - 2) % MOD) * mod_pow(mod_fact(n - r) , MOD - 2)  % MOD;
}

int main()
{
  ll n, k;
  cin >> n >> k;

  cout << nCr(n + k - 1, k) << endl;
}

