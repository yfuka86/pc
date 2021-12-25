// https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <math.h>
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

int main()
{
  int n;
  cin >> n;
  vector<P> S(n);
  vector<vector<bool>> exists(5001, vector<bool>(5001, false));
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    S[i] = make_pair(x, y);
    exists[x][y] = true;
  }
  sort(all(S));

  int max_area = 0;

  rep(i, n) {
    P s1 = S[i];
    int x = s1.first;
    int y = s1.second;
    for(int j = n - 1 ; j > i ; j--) {
      P s2 = S[j];

      int a = s2.first - x;
      int b = s2.second - y;
      int area = a * a + b * b;

      if (area <= max_area) continue;
      int check[4] = { x - b, y + a, x + a - b, y + a + b };
      bool valid = true;
      rep(i, 4) if (check[i] < 0 || check[i] > 5000) valid = false;
      if (!valid) continue;
      if (!exists[x - b][y + a] || !exists[x + a - b][y + a + b]) continue;
      max_area = area;
    }
  }

  cout << max_area << endl;
}

