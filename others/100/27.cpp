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
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int m, n;
vector<vector<int>> land;
int maximum = 0;

void dfs(int x, int y, vector<P> hist) {
  if (find(all(hist), make_pair(x, y)) != hist.end()) return;

  hist.pb(make_pair(x, y));
  chmax(maximum, int(hist.size()));
  if (x > 0 && land[x-1][y] == 1) dfs(x-1, y, hist);
  if (x < m-1 && land[x+1][y] == 1) dfs(x+1, y, hist);
  if (y > 0 && land[x][y-1] == 1) dfs(x, y-1, hist);
  if (y < n-1 && land[x][y+1] == 1) dfs(x, y+1, hist);
}

int main()
{
  cin >> m >> n;
  land.resize(m);
  land.assign(m, vector<int>(n));
  rep(i, m) rep(j, n) cin >> land[i][j];

  rep(i, m) {
    rep(j, n) {
      if (land[i][j] == 1) dfs(i, j, {});
    }
  }
  cout << maximum << endl;
}

