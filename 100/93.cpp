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

ll H, W, K;

ll solve(vector<vl> board, ll i, ll j) {
  board[j].erase(board[j].begin() + i);
  board[j].pb(0);

  // cout << i << ":" << j << "------------------" << endl;
  ll score = 0;
  ll erased_count = 0;
  while(true) {
    bool erased = false;
    rep_r(i, H) {
      map<ll, pair<ll, ll>> stones;
      rep(j, W) {
        if (j == 0) { stones[0] = make_pair(board[j][i], 1); continue;}
        if (board[j - 1][i] == board[j][i]) {
          (stones.rbegin()->second).second++;
        } else {
          stones[j] = make_pair(board[j][i], 1);
        }
      }

      for (auto kv: stones) {
        ll from = kv.first, count = kv.second.second, stone = kv.second.first;
        if (count < K || stone == 0) continue;

        score += count * stone * pow(2, erased_count);
        rep2(j, from, from + count) {
          board[j].erase(board[j].begin() + i);
          board[j].pb(0);
        }
        erased = true;
      }
      // coutmatrix(board);
      // cout << endl;
      // cout << erased_count << endl;
    }
    erased_count++;
    if (!erased) break;
  }
  return score;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> H >> W >> K;

  vector<vl> board(W, vl(H));
  rep_r(i, H) {
    string s; cin >> s;
    rep(j, W) board[j][i] = (s[j] - '0');
  }

  ll score = 0;
  rep(i, H) {
    rep(j, W) {
      chmax(score, solve(board, i, j));
    }
  }
  cout << score << "\n";
}
