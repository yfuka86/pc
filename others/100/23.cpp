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
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> p(N);
  rep(i, N) cin >> p[i];

  vector<int> dp;
  rep(i, N) {
    dp.push_back(0);
    dp.push_back(p[i]);
    rep2(j, i+1, N) {
      dp.push_back(p[i] + p[j]);
    }
  }
  sort(all(dp));


  int mx = 0;
  rep(i, dp.size()) {
    vector<int>::iterator itr = upper_bound(all(dp), M - dp[i]);
    if (itr == dp.begin()) continue;
    chmax(mx, dp[i] + dp[itr - dp.begin() - 1]);
  }
  cout << mx << endl;
}

