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
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  int H, W;
  cin >> H >> W;

  int whitecount = 0;
  vector<vector<bool>> maze(H, vector<bool>(W));
  vector<vector<int>> cost(H, vector<int>(W, -1));
  rep(i, H) {
    string s; cin >> s;
    rep(j, W) {
      if (s[j] == '.') {
        maze[i][j] = 0;
        whitecount++;
      } else {
        maze[i][j] = 1;
      }
    }
  }

  queue<vector<int>> que;

  auto process = [&](int x, int y, int c) -> void {
    if (cost[x][y] == -1) {
      cost[x][y] = c;
      que.push({x, y});
    }
  };

  auto bfs = [&](vector<int> v) -> void {
    int x = v[0], y = v[1];
    int c = cost[x][y] + 1;
    if (x > 0 && maze[x - 1][y] == 0) process(x - 1, y, c);
    if (x < H - 1 && maze[x + 1][y] == 0) process(x + 1, y, c);
    if (y > 0 && maze[x][y - 1] == 0) process(x, y - 1, c);
    if (y < W - 1 && maze[x][y + 1] == 0) process(x, y + 1, c);
  };

  cost[0][0] = 1;
  bfs({0, 0});
  while(!que.empty()) {
    bfs(que.front());
    que.pop();
  }

  cout << (cost[H - 1][W - 1] == -1 ? -1 : whitecount - cost[H - 1][W - 1]) << endl;
}

