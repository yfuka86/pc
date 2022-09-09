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

int w, h;
vector<vector<int> > land;
vector<vector<bool> > done;

void dfs(int x, int y) {
  done[x][y] = true;
  vector<int> x_options;
  vector<int> y_options;
  x_options.pb(x); if (x > 0) x_options.pb(x - 1); if (x < w - 1) x_options.pb(x + 1);
  y_options.pb(y); if (y > 0) y_options.pb(y - 1); if (y < h - 1) y_options.pb(y + 1);

  rep(i, x_options.size()) {
    rep(j, y_options.size()) {
      int new_x = x_options[i];
      int new_y = y_options[j];
      if (land[new_x][new_y] == 1 && !done[new_x][new_y]) dfs(new_x, new_y);
    }
  }
}

int main()
{
  while (true) {
    cin >> h >> w;
    if (w == 0 && h == 0) break;

    land.resize(w);
    land.assign(w, vector<int>(h, 0));
    done.resize(w);
    done.assign(w, vector<bool>(h, false));

    rep(i, w) rep(j, h) cin >> land[i][j];
    int count = 0;
    rep(i, w) rep(j, h) if (land[i][j] == 1 && done[i][j] == false) { dfs(i, j); count++; }
    cout << count << endl;
  }
}

