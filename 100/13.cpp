// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e
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

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template <class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }


int main()
{
  int R, C;
  cin >> R >> C;

  vector<int> v(C, 0);
  rep(i, R) {
    rep(j, C) {
      int t;
      cin >> t;
      if (t) v[j] |= 1 << i;
    }
  }

  int ret = 0;
  rep(i, (1 << R)) {
    int sum = 0;
    rep(j, C) {
      int result = v[j] ^ i;
      int num = 0;

      rep(k, R) {
        if ((result >> k) & 1) num++;
      }
      sum += max(num, R - num);
    }
    chmax(ret, sum);
  }

  cout << ret << endl;
}

