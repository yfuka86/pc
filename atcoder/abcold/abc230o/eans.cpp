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
#define rep(i,n) for (ll i=0; i<(ll)(n); ++i)
#define rep2(i,x,n) for(ll i=x; i<(ll)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  ll N;
  cin >> N;

  ll ret = 0;
  ll i = 1;
  for (; i * i <= N; ++i) ret += N / i;

  for (; i <= N;) {
    ll j = N / i;
    ll nxti = N / j + 1;
    ret += j * (nxti - i);
    i = nxti;
  }
  cout << ret << '\n';
}

