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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=0;i--)
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

template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

struct Cell {
  bool up, down, left, right;
};

vector<vector<Cell> > maze;
vector<vl> costs;

void bfs() {
  queue<pair<ll, LP> > que;
  que.push(make_pair(1, make_pair(0, 0)));

  while(!que.empty()) {
    pair<ll, LP> p = que.front(); que.pop();
    ll cost = p.first, i = p.second.first, j = p.second.second;
    if (cost >= costs[i][j]) continue;

    costs[i][j] = cost;
    Cell c = maze[i][j];
    cost += 1;
    if (!c.up) { que.push(make_pair(cost, make_pair(i - 1, j))); }
    if (!c.down) { que.push(make_pair(cost, make_pair(i + 1, j))); }
    if (!c.right) { que.push(make_pair(cost, make_pair(i, j + 1))); }
    if (!c.left) { que.push(make_pair(cost, make_pair(i, j - 1))); }
  }
}

int main()
{
  ios::sync_with_stdio(false);

  while(true) {
    ll W, H;
    cin >> W >> H;
    if (W == 0 && H == 0) break;
    maze.resize(H);
    costs.resize(H);
    maze.assign(H, vector<Cell>(W, { 1, 1, 1, 1 }));
    costs.assign(H, vl(W, LINF));

    rep(i, H) {
      rep(j, W - 1) {
        int t; cin >> t;
        maze[i][j].right = t;
        maze[i][j + 1].left = t;
      }
      if (i == H - 1) break;
      rep(j, W) {
        int t; cin >> t;
        maze[i][j].down = t;
        maze[i + 1][j].up = t;
      }
    }

    bfs();
    if (costs[H - 1][W - 1] != LINF) {
      cout << costs[H - 1][W - 1] << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}


