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

int main()
{
  ios::sync_with_stdio(false);

  while(true) {
    ll H;
    cin >> H;
    if (H == 0) break;

    vector<vl> board(5, vl(H));

    rep_r(i, H) {
      rep(j, 5) cin >> board[j][i];
    }

    ll score = 0;
    while(true) {
      bool erased = false;
      rep_r(i, H) {
        ll c = 1, from = 0, to = 0;
        rep(j, 5) {
          if (j > 0 && board[j - 1][i] == board[j][i]) {c++; } else c = 1;
          if (c > to - from) { to = j + 1; from = to - c; }
        }

        if (to - from >= 3 && board[from][i] != 0) {
          score += (to - from) * board[from][i];
          rep2(k, from, to) {
            board[k].erase(board[k].begin() + i);
            board[k].pb(0);
          }
          erased = true;
        }
      }
      if (!erased) break;
    }

    cout << score << "\n";
  }
}


