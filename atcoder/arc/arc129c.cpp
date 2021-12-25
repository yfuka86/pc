// https://atcoder.jp/contests/arc129/tasks/arc129_c

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
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

vector<int> triangles;

int main()
{
  rep(i, 100000) {
    triangles.push_back((i > 0 ? triangles[i - 1] : 0) + i);
    if (triangles[i] > 1000000) break;
  }

  int N;
  cin >> N;

  vector<int> mods = {1, 3, 2, 6, 4, 5};
  vector<P> parts;

  string ans = "";
  while(N != 0) {
    int idx = upper_bound(all(triangles), N) - triangles.begin() - 1;
    N -= triangles[idx];
    ans += string(idx, '7');
    if (N == 0) break;

    vector<int> modsofar;
    rep(i, parts.size()) {
      modsofar.push_back(mods[(ans.size() - parts[i].second) % 6] * parts[i].first % 7);
    }
    vector<int> sumsofar;
    rep(i, modsofar.size()) {
      sumsofar.push_back(accumulate(modsofar.begin() + i, modsofar.end(), 0) % 7);
    }
    rep2(i, 1, 7) {
      bool check = true;
      rep(j, sumsofar.size()) {
        if ((sumsofar[j] + i) % 7 == 0) check = false;
      }
      if (check) {
        parts.push_back(make_pair(i, ans.size()));
        ans += (i + '0');
        break;
      }
    }
  }

  cout << ans << endl;
}

