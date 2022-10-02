#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

using namespace std;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  string a, b;
  cin >> a >> b;

  vector<int> av(10, 0), bv(10, 0);
  rep(i, a.size()) av[int(a[i] - '0')]++;
  rep(i, b.size()) bv[int(b[i] - '0')]++;

  string anine = "";
  string bnine = "";
  string aover = "";
  string bover = "";
  string aex = "";
  string bex = "";

  rep2(i, 0, 9) {
    int m = min(av[i], bv[9 - i]);

    av[i] -= m;
    bv[9 - i] -= m;

    anine += string(m, i + '0');
    bnine += string(m, 9 - i + '0');
  }

  rep2(i, 10, 19) {
    rep2(j, 1, 10) {
      if (i - j >= 10) continue;
      int m = min(av[j], bv[i - j]);
      av[j] -= m;
      bv[i - j] -= m;

      aover += string(m, j + '0');
      bover += string(m, i - j + '0');
    }
  }
  reverse(all(aover));
  reverse(all(bover));

  rep2(i, 1, 10) {
    if (av[i] > 0) {
      aex += string(av[i], i + '0');
    }
    if (bv[i] > 0) {
      bex += string(bv[i], i + '0');
    }
  }

  cout << aex + anine + aover << endl;
  cout << bex + bnine + bover << endl;
}

