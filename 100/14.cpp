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

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template <class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }

int bitcount(int n) {
  int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;
}

int main()
{
  int N, K;
  cin >> N >> K;
  vector<ll> h(N);
  rep(i, N) cin >> h[i];

  ll minsum = LINF;
  rep(i, 1 << (N - 1)) {
    if (K - 1 == bitcount(i)) {
      ll sum = 0;
      ll minh = h[0];
      rep(j, N) {
        if (i & 1 << (j - 1) && minh >= h[j]) {
          sum += minh + 1 - h[j];
          minh++;
        } else {
          minh = max(minh, h[j]);
        }
      }
      chmin(minsum, sum);
    }
  }

  cout << minsum << endl;
}



