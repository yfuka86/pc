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
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

int main()
{
  int k;
  cin >> k;
  vector<int> x;
  vector<int> y;
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    x.push_back(a); y.push_back(b);
  }
  rep(i, 8) {
    if (find(all(x), i) == x.end()) x.push_back(i);
    if (find(all(y), i) == y.end()) y.push_back(i);
  }

  do {
    bool check = true;
    rep(i, 8) {
      rep2(j, i + 1, 8) {
        if (!check) break;
        if (abs(x[j] - x[i]) == abs(y[j] - y[i])) check = false;
      }
    }
    if (check) break;
  } while (next_permutation(y.begin() + k, y.end()));

  rep(i, 8) {
    rep(j, 8) {
      bool q = false;
      rep(k, 8) {
        if (x[k] == i && y[k] == j) {
          cout << 'Q';
          q = true;
        }
      }
      if (!q) {
        cout << '.';
      }
    }
    cout << endl;
  }
}

