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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int W, H;
  cin >> W >> H;

  vector<vl> odd = {{0, -1}, {1, -1}, {-1, 0}, {1, 0}, {0, 1}, {1, 1}};
  vector<vl> even = {{-1, -1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}};

  vector<vl> maze(W + 2, vl(H + 2));
  vector<vl> painted(W + 2, vl(H + 2, 0));
  rep(i, H) rep(j, W) cin >> maze[j + 1][i + 1];

  queue<LP> que;
  que.push(make_pair(0, 0));
  while(!que.empty()) {
    LP p = que.front(); que.pop();

    ll x = p.first, y = p.second;
    if (x < 0 || x > W + 1 || y < 0 || y > H + 1) continue;
    if (maze[x][y] == 1 || painted[x][y] != 0) continue;

    painted[x][y] = 1;
    vector<vl> dir = y % 2 == 1 ? odd : even;
    for (vl d: dir) {
      que.push(make_pair(x + d[0], y + d[1]));
    }
  }

  ll sum = 0;
  rep2(i, 1, H + 1) {
    rep2(j, 1, W + 1) {
      if (maze[j][i] == 1) {
        vector<vl> dir = i % 2 == 1 ? odd : even;
        for (vl d: dir) {
          if (painted[j + d[0]][i + d[1]]) sum++;
        }
      }
    }
  }
  cout << sum << "\n";
}
