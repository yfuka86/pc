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

using namespace std;
const ll MOD_BASE = 1000000007;
ll mods[32] = {};

int main()
{
  ll m, n;
  cin >> m >> n;

  mods[0] = m % MOD_BASE;
  rep2(i, 1, 32) {
    mods[i] = mods[i-1] * mods[i-1] % MOD_BASE;
  }

  ll ans = 1;
  rep(i, 32) {
    if (n >> i & 1) {
      ans = (ans * mods[i]) % MOD_BASE;
    }
  }
  cout << ans << endl;
}

