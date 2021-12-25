// https://atcoder.jp/contests/abc014/tasks/abc014_3
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
const int INF = numeric_limits<int>::max();

template <class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  int dp[1000002];
  rep(i, 1000002) dp[i] = 0;

  int n;
  cin >> n;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    dp[a]++;
    dp[b + 1]--;
  }

  int sum = 0;
  int ret = 0;
  rep(i, 1000002) {
    sum += dp[i];
    chmax(ret, sum);
  }
  cout << ret << endl;
}


