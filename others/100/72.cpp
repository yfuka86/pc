//https://atcoder.jp/contests/abc034/tasks/abc034_c

#include <iostream>
#include <iomanip>
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

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

using namespace std;
const ll MOD = 1000000007;

ll mod_pow(ll x, ll k)
{
  ll res = 1;
  for (; k; k /= 2, x = x * x % MOD) if (k & 1) res = res * x % MOD;
  return res;
}

// 便宜上
ll factorials[200010] = { 1 };

ll mod_fact(int to) {
  rep2(i, 1, to + 1) {
    if (factorials[i]) continue;
    factorials[i] = factorials[i - 1] * i % MOD;
  }
  return factorials[to];
}

// (w-1) + (h-1) C (w-1)
int main()
{
  int W, H;
  cin >> W >> H;

  ll ans = mod_fact(W + H - 2) * mod_pow(mod_fact(W - 1), MOD - 2) % MOD * mod_pow(mod_fact(H - 1), MOD - 2) % MOD;
  cout << ans << endl;
}

