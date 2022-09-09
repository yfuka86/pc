//https://atcoder.jp/contests/abc145/tasks/abc145_d
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
ll factorials[1000010] = { 1 };

ll mod_fact(int to) {
  if (factorials[to]) return factorials[to];

  rep2(i, 1, to + 1) {
    if (factorials[i]) continue;
    factorials[i] = factorials[i - 1] * i % MOD;
  }
  return factorials[to];
}

int main()
{
  int X, Y;
  cin >> X >> Y;

  int movex;
  int movey;
  if (X == Y) {
    if (X % 3 != 0) {
      cout << 0 << endl;
      return 0;
    }
    movex = movey = X / 3;
  } else {
    if (X < Y) swap(X, Y);
    int diff = X - Y;
    if (diff > Y || (X + diff) % 3 != 0) {
      cout << 0 << endl;
      return 0;
    }
    movex = (X + diff) / 3;
    movey = movex - diff;
  }

  ll ans = mod_fact(movex + movey) * mod_pow(mod_fact(movex), MOD - 2) % MOD * mod_pow(mod_fact(movey), MOD - 2) % MOD;
  cout << ans << endl;
}

