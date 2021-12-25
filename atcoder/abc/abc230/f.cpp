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
#include <bitset>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

const ll MOD = 998244353;

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

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  int N;
  cin >> N;

  vector<ll> seq(N, 0);
  rep(i, N) cin >> seq[i];


}

