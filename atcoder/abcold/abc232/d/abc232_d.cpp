#pragma GCC optimize("Ofast")
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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep_r(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(int i=sta;i<(int)(n);i++)
#define rep2_r(i,sta,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll mod = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
void comp(vector<int>&a){ vector<int> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T>
void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T>
void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };
template<typename K, typename V>
void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
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
    // でかいほうがいい
    if (c > costs[x][y]) {
      costs[x][y] = c;
      que.push(make_pair(x, y));
    }
  };

  auto bfs = [&](P p)  {
    int x = p.first, y = p.second;
    int c = costs[x][y] + 1;

    if (x < h - 1 && maze[x + 1][y]) process(x + 1, y, c);
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;

  vector<vector<bool>> maze(H, vector<bool>(W, false));

  rep(i, H) {
    string s; cin >> s;
    rep(j, W) if (s[j] == '.') maze[i][j] = true;
  }

  vector<vector<int>> costs = bfs(maze, make_pair(0, 0));

  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      chmax(ans, costs[i][j]);
    }
  }
  cout << (ans + 1) << endl;
}
