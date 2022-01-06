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
#include <cassert>
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

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
int ceil_pow2(int n) { int x = 0; while ((1U << x) < (unsigned int)(n)) x++; return x; }
int floor_pow2(int n) { int x = 0; while ((1U << (x + 1)) <= (unsigned int)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

struct Search {
  ll x, y;
  vl history;
  bool operator<(const struct Search& other) const
  {
    return x + y < other.x + other.y;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll H, W, K;
  cin >> H >> W >> K;

  vector<vl> maze(H, vl(W, -1));
  rep(i, H) rep(j, W) cin >> maze[i][j];
  vector<vl> cost(H, vl(W, LINF));
  // 右か下
  vector<vl> dxdy = {{1, 0}, {0, 1}};

  priority_queue<pair<ll, Search>> PQ;

  PQ.push(make_pair(0, Search{0, 0, {}}));
  while(!PQ.empty()) {
    pair<ll, Search> p = PQ.top(); PQ.pop();
    Search v = p.second;

    //　コスト計算
    ll next_cost;
    vl his = v.history;
    his.pb(maze[v.x][v.y]);
    sort(all(his));
    ll nextcost = his.size() > K ? accumulate(his.end() - K, his.end(), 0LL) : accumulate(all(his), 0LL);

    if (cost[v.x][v.y] <= nextcost) continue;
    cost[v.x][v.y] = nextcost;
    // cout << v.x << ":" << v.y << "=" << nextcost << endl;

    for (vl to: dxdy) {
      ll nx = v.x + to[0];
      ll ny = v.y + to[1];
      if (nx < H && ny < W) {
        PQ.push(make_pair(-next_cost, Search{nx, ny, his}));
      }
    }
  }

  cout << cost[H - 1][W - 1] << "\n";
}


