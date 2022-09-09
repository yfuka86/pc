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

int main()
{
  int m; cin >> m;
  vector<P> co(m);
  rep(i, m) {
    int a, b; cin >> a >> b;
    co[i] = make_pair(a, b);
  }

  int n; cin >> n;
  vector<P> star(n);
  rep(i, n) {
    int a, b; cin >> a >> b;
    star[i] = make_pair(a, b);
  }

  sort(all(co));
  sort(all(star));

  rep(i, n) {
    P s = star[i]; P c = co[0];
    int xdiff = s.first - c.first;
    int ydiff = s.second - c.second;

    bool ok = true;
    rep2(j, 1, m) {
      int searchx = co[j].first + xdiff;
      int searchy = co[j].second + ydiff;
      if (searchx < 0 || searchx > 1000000 || searchy < 0 || searchy > 1000000) ok = false;
      if (find(all(star), make_pair(searchx, searchy)) == star.end()) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << xdiff << " " << ydiff << endl;
      return 0;
    }
  }
}

