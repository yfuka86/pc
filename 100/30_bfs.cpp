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

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

vector<vector<int>> bfs(vector<vector<bool>> maze, P start) {
  queue<P> que;
  int h = maze.size();
  int w = maze[0].size();
  vector<vector<int>> costs(h, vector<int>(w, -1));

  auto process = [&](int x, int y, int c) -> void {
    if (costs[x][y] == -1) {
      costs[x][y] = c;
      que.push(make_pair(x, y));
    }
  };

  auto bfs = [&](P p)  {
    int x = p.first, y = p.second;
    int c = costs[x][y] + 1;

    if (x > 0 && maze[x - 1][y]) process(x - 1, y, c);
    if (x < h - 1 && maze[x + 1][y]) process(x + 1, y, c);
    if (y > 0 && maze[x][y - 1]) process(x, y - 1, c);
    if (y < w - 1 && maze[x][y + 1]) process(x, y + 1, c);
  };

  costs[start.first][start.second] = 0;
  que.push(start);
  while(!que.empty()) {
    bfs(que.front());
    que.pop();
  }
  return costs;
}

int main()
{
  int H, W, N;
  cin >> H >> W >> N;

  vector<vector<bool>> maze(H, vector<bool>(W));
  vector<P> goals(N + 1);

  rep(i, H) {
    string s;
    cin >> s;
    rep(j, W) {
      if (s[j] != 'X') maze[i][j] = true;
      if (s[j] >= '1' && s[j] <= '9') goals[s[j] - '0'] = make_pair(i, j);
      if (s[j] == 'S') goals[0] = make_pair(i, j);
    }
  }

  int sum = 0;
  rep2(i, 1, N + 1) {
    vector<vector<int>> costs = bfs(maze, goals[i - 1]);
    sum += costs[goals[i].first][goals[i].second];
  }
  cout << sum << endl;
}

