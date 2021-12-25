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
int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}


int main()
{
  int N, M, Q;
  cin >> N >> M >> Q;

  vector<vector<int>> cumsum(N, vector<int>(N, 0));

  rep(i, M) {
    int t1, t2; cin >> t1 >> t2; t1--; t2--;
    rep2(j, 0, t1 + 1) {
      rep2(k, t2, N) {
        cumsum[j][k]++;
      }
    }
  }

  rep(i, Q) {
    int p, q; cin >> p >> q; p--; q--;
    cout << cumsum[p][q] << endl;
  }
}

