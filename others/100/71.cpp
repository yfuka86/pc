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
const ll MOD_BASE = 1000000007;

ll power(int base, int exp) {
  ll mods[32] = {};
  mods[0] = base % MOD_BASE;
  rep2(i, 1, 32) {
    mods[i] = mods[i-1] * mods[i-1] % MOD_BASE;
  }

  ll ans = 1;
  rep(i, 32) {
    if (exp >> i & 1) {
      ans = (ans * mods[i]) % MOD_BASE;
    }
  }
  return ans;
}

int main()
{
  ll N, Q;
  cin >> N >> Q;

  vector<ll> a(N);
  rep(i, N) cin >> a[i];
  vector<int> c(Q);
  rep(i, Q) { cin >> c[i]; c[i]--; }

  vector<ll> dist(N, 0);
  rep2(i, 1, N) {
    dist[i] = power(a[i - 1], a[i]);
  }

  vector<ll> sum(N, 0);
  rep2(i, 1, N) {
    sum[i] = (dist[i] - dist[0] + sum[i - 1]);
  }

  ll total = 0;
  rep2(i, 1, Q) {
    total += abs(sum[c[i]] - sum[c[i - 1]]);
  }
  total = (total + sum[c[0]] + sum[c[Q - 1]]) % MOD_BASE;

  cout << total << endl;
}

