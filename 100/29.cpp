#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main()
{
  int R, C;
  cin >> R >> C;

  vector<int> start(2), goal(2);
  cin >> start[0] >> start[1] >> goal[0] >> goal[1];
  start[0]--; start[1]--; goal[0]--; goal[1]--;

  vector<vector<int>> maze(R, vector<int>(C));
  vector<vector<int>> cost(R, vector<int>(C, -1));
  rep(i, R) {
    string s; cin >> s;
    rep(j, C) maze[i][j] = s[j] == '.' ? 0 : 1;
  }

  queue<vector<int>> que;

  auto process = [&](int y, int x, int c) -> void {
    if (cost[y][x] == -1) {
      cost[y][x] = c;
      que.push({y, x});
    }
  };

  auto bfs = [&](vector<int> v) -> void {
    int y = v[0], x = v[1];
    int c = cost[y][x] + 1;
    if (maze[y][x - 1] == 0) process(y, x - 1, c);
    if (maze[y][x + 1] == 0) process(y, x + 1, c);
    if (maze[y - 1][x] == 0) process(y - 1, x, c);
    if (maze[y + 1][x] == 0) process(y + 1, x, c);
  };

  cost[start[0]][start[1]] = 0;
  bfs(start);
  while(!que.empty()) {
    bfs(que.front());
    que.pop();
  }

  cout << cost[goal[0]][goal[1]] << endl;
}


